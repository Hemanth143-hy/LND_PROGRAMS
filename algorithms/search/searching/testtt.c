/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

//#include <zephyr/types.h>
#include <stddef.h>
#include <inttypes.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/kernel.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci.h>
#include <bluetooth/scan.h>
#include <bluetooth/gatt_dm.h>


#include <zephyr/bluetooth/services/bas.h>
#include <zephyr/bluetooth/services/hrs.h>
#include <bluetooth/services/hrs_client.h>

#include <dk_buttons_and_leds.h>

#include <zephyr/settings/settings.h>

#include <stdio.h>
#include <stdlib.h>


#define STACKSIZE 1024

#define KEY_PRINT1_MASK DK_BTN1_MSK
#define KEY_PRINT2_MASK DK_BTN2_MSK
#define KEY_PRINT3_MASK DK_BTN3_MSK
#define KEY_PRINT4_MASK DK_BTN4_MSK

#define KEY_READVAL1_MASK DK_BTN1_MSK
#define KEY_READVAL2_MASK DK_BTN2_MSK
#define KEY_READVAL3_MASK DK_BTN3_MSK
#define KEY_READVAL4_MASK DK_BTN4_MSK


#define RUN_STATUS_LED             DK_LED1
#define CENTRAL_CON_STATUS_LED	   DK_LED2




#define HRS_QUEUE_SIZE 16

static struct bt_hrs_client hrs_c;
static struct bt_conn *central_conn;



static int flag=1;

K_MSGQ_DEFINE(hrs_queue, sizeof(struct bt_hrs_client_measurement), HRS_QUEUE_SIZE, 4);



static const char * const sensor_location_str[] = {
	"Other",
	"Chest",
	"Wrist",
	"Finger",
	"Hand",
	"Ear lobe",
	"Foot"
};   

static void hrs_sensor_location_read_cb(struct bt_hrs_client *hrs_c,
					enum bt_hrs_client_sensor_location location,
					int err)
{
	if (err) {
		printk("HRS Sensor Body Location read error (err %d)\n", err);
		return;
	}

	printk("Heart Rate Sensor body location: %s\n", sensor_location_str[location]);
}

static void hrs_measurement_notify_cb(struct bt_hrs_client *hrs_c,
				      const struct bt_hrs_client_measurement *meas,
				      int err)
{
	if (err) {
		printk("Error during receiving Heart Rate Measurement notification, err: %d\n",
			err);
		return;
	}

	printk("Heart Rate Measurement notification received:\n\n");
	printk("\tHeart Rate Measurement Value Format: %s\n",
		meas->flags.value_format ? "16 - bit" : "8 - bit");
	printk("\tSensor Contact detected: %d\n", meas->flags.sensor_contact_detected);
	printk("\tSensor Contact supported: %d\n", meas->flags.sensor_contact_supported);
	printk("\tEnergy Expended present: %d\n", meas->flags.energy_expended_present);
	printk("\tRR-Intervals present: %d\n", meas->flags.rr_intervals_present);

	printk("\n\tHeart Rate Measurement Value: %d bpm\n", meas->hr_value);

	if (meas->flags.energy_expended_present) {
		printk("\n\tEnergy Expended: %d J\n", meas->energy_expended);
	}

	if (meas->flags.rr_intervals_present) {
		printk("\t RR-intervals: ");
		for (size_t i = 0; i < meas->rr_intervals_count; i++) {
			printk("%d ", meas->rr_intervals[i]);
		}
	}

	printk("\n");

	err = k_msgq_put(&hrs_queue, meas, K_NO_WAIT);
	if (err) {
		printk("Notification queue is full. Discarting HRS notification (err %d)\n", err);
	}
}


static void discovery_completed_cb(struct bt_gatt_dm *dm,
				   void *context)
{
	int err;

	printk("The discovery procedure succeeded\n");

	bt_gatt_dm_data_print(dm);

	err = bt_hrs_client_handles_assign(dm, &hrs_c);
	if (err) {
		printk("Could not init HRS client object (err %d)\n", err);
		return;
	}

	/*err = bt_hrs_client_sensor_location_read(&hrs_c, hrs_sensor_location_read_cb);
	if (err) {
		printk("Could not read Heart Rate Sensor location (err %d)\n", err);
	}

	err = bt_hrs_client_measurement_subscribe(&hrs_c, hrs_measurement_notify_cb);
	if (err) {
		printk("Could not subscribe to Heart Rate Measurement characteristic (err %d)\n",
		       err);
	}

	err = bt_gatt_dm_data_release(dm);
	if (err) {
		printk("Could not release the discovery data (err %d)\n", err);
	}*/
}

static void discovery_not_found_cb(struct bt_conn *conn,
				   void *context)
{
	printk("Heart Rate Service could not be found during the discovery\n");
}

static void discovery_error_found_cb(struct bt_conn *conn,
				     int err, void *context)
{
	printk("The discovery procedure failed with %d\n", err);
}

static const struct bt_gatt_dm_cb discovery_cb = {
	.completed = discovery_completed_cb,
	.service_not_found = discovery_not_found_cb,
	.error_found = discovery_error_found_cb
};

static void gatt_discover(struct bt_conn *conn)
{
	int err;

	err = bt_gatt_dm_start(conn, BT_UUID_HRS, &discovery_cb, NULL);
	if (err) {
		printk("Could not start the discovery procedure, error "
			   "code: %d\n", err);
	}
}


static void auth_cancel(struct bt_conn *conn)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing cancelled: %s\n", addr);
}

static void pairing_complete(struct bt_conn *conn, bool bonded)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing completed: %s, bonded: %d\n", addr, bonded);
}

static void pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing failed conn: %s, reason %d\n", addr, reason);
}

static const struct bt_conn_auth_cb auth_callbacks = {
	.cancel = auth_cancel
};

static struct bt_conn_auth_info_cb conn_auth_info_callbacks = {
	.pairing_complete = pairing_complete,
	.pairing_failed = pairing_failed
};






static int scan_start(void)
{
	if(flag==1)
	{
		int err = bt_scan_start(BT_SCAN_TYPE_SCAN_PASSIVE);
		printk("scanning started\n");
		flag++;
	}
	else
	{
		printk("already started\n");
	}
	return flag;
}


static bool is_connected=false;


static void connected(struct bt_conn *conn, uint8_t conn_err)
{
	int err;
	struct bt_conn_info info;
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (conn_err) {
		printk("Failed to connect to %s (%u)\n", addr, conn_err);

		if (conn == central_conn) {
			bt_conn_unref(central_conn);
			central_conn = NULL;

			scan_start();
		}

		return;
	}

     is_connected = true;
	printk("Connected: %s\n", addr);

	bt_conn_get_info(conn, &info);

	if (info.role == BT_CONN_ROLE_CENTRAL) {
		dk_set_led_on(CENTRAL_CON_STATUS_LED);

		err = bt_conn_set_security(conn, BT_SECURITY_L2);
		if (err) {
			printk("Failed to set security (err %d)\n", err);

			gatt_discover(conn);
		}
	} 
}




static void disconnected(struct bt_conn *conn, uint8_t reason)
{




	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));



	printk("Disconnected: %s (reason %u)\n", addr, reason);

	if (conn == central_conn) {
		dk_set_led_off(CENTRAL_CON_STATUS_LED);

		bt_conn_unref(central_conn);
		central_conn = NULL;
     


		//scan_start();
 printk("press button1 to restart scanning\n");
  flag=1;

	} 
}









static void security_changed(struct bt_conn *conn, bt_security_t level,
			     enum bt_security_err err)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (!err) {
		printk("Security changed: %s level %u\n", addr, level);
	} else {
		printk("Security failed: %s level %u err %d\n", addr, level,
			err);
	}

	if (conn == central_conn) {
		gatt_discover(conn);
	}
}

BT_CONN_CB_DEFINE(conn_callbacks)={
	.connected=connected,
	.disconnected=disconnected,
	.security_changed=security_changed
};



static struct bt_scan_device_info *dev_info = NULL;



static void scan_filter_match(struct bt_scan_device_info *device_info,
			      struct bt_scan_filter_match *filter_match,
			      bool connectable)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(device_info->recv_info->addr, addr, sizeof(addr));

	printk("Filters matched. Address: %s connectable: %s\n",
		   addr, connectable ? "yes" : "no");

		   dev_info = device_info;
}

static void scan_connecting_error(struct bt_scan_device_info *device_info)
{
	printk("Connecting failed\n");
}

static void scan_connecting(struct bt_scan_device_info *device_info,
			    struct bt_conn *conn)
{
	
	central_conn = bt_conn_ref(conn);
}

//
static void scan_filter_no_match(struct bt_scan_device_info *device_info,
				 bool connectable)
{
	int err;
//	 struct bt_conn *conn;
	char addr[BT_ADDR_LE_STR_LEN];
	//static struct bt_scan_device_info *dev_info = NULL;

	if (device_info->recv_info->adv_type == BT_GAP_ADV_TYPE_ADV_DIRECT_IND) {
		bt_addr_le_to_str(device_info->recv_info->addr, addr,
				  sizeof(addr));
		printk("Direct advertising received from %s\n", addr);
		dev_info = device_info;
		
		bt_scan_stop();
/*
		err = bt_conn_le_create(device_info->recv_info->addr,
					BT_CONN_LE_CREATE_CONN,
					device_info->conn_param, &conn);

		if (!err) {
			//
			central_conn = bt_conn_ref(conn);
			bt_conn_unref(conn);
		}
*/
	}
}








BT_SCAN_CB_INIT(scan_cb, scan_filter_match,scan_filter_no_match,
		scan_connecting_error, scan_connecting);



static void scan_init(void)
{
	int err;

	struct bt_scan_init_param param = {
		.scan_param = NULL,
		.conn_param = BT_LE_CONN_PARAM_DEFAULT,
		.connect_if_match = 1
	};

	bt_scan_init(&param);
	bt_scan_cb_register(&scan_cb);

	err = bt_scan_filter_add(BT_SCAN_FILTER_TYPE_UUID, BT_UUID_HRS);
	if (err) {
		printk("Scanning filters cannot be set (err %d)\n", err);
	}

	err = bt_scan_filter_enable(BT_SCAN_UUID_FILTER, false);
	if (err) {
		printk("Filters cannot be turned on (err %d)\n", err);
	}
}






static void button_readval1(void)
{
	int err;
	printk("Button1 pressed\n");
	err=scan_start();
	if(err){
		return;
	}
	printk("scanning started\n");
}

static void button_readval2(void)
{
	if (dev_info != NULL){
		struct bt_conn *conn;
		int err;


		


		err = bt_conn_le_create(dev_info->recv_info->addr,
					BT_CONN_LE_CREATE_CONN,
					dev_info->conn_param, &conn);
			

		if (!err) {
			//
			central_conn = bt_conn_ref(conn);
			bt_conn_unref(conn);
			printk("connection initiated\n");
		}
		else
		{
			printk("failed to initiate connection(err %d)\n",err);
		}
	}
	else
	{
		printk("no device information\n");
	}
//printk("button2 pressed:)\n");

}
	

//

static void button_readval3(void)
{
	printk("button3 pressed:)\n");
	int err;
	printk("reading heart rate value\n");
	err=bt_hrs_client_sensor_location_read(&hrs_c,hrs_sensor_location_read_cb);
	if(err){
		printk("heart rate read call error : %d\n",err);
	}
}

static void button_readval4(void)
{
	printk("button4 pressed:)\n");
	printk("Enabaling notification\n");
	int err;
	err=bt_hrs_client_measurement_subscribe(&hrs_c,hrs_measurement_notify_cb);
	if(err){
		printk("heart rate notification error: %d\n",err);
	}
}

static void button_handler(uint32_t button_state, uint32_t has_changed)
{
	uint32_t button = button_state & has_changed;

	if(button & KEY_READVAL1_MASK)
	{
		button_readval1();
		
	}


	
	if(button & KEY_READVAL2_MASK)
	{
	//	button_readval2();
	}



	
	if(button & KEY_READVAL3_MASK)
	{
		button_readval3();
	}
	
	if(button & KEY_READVAL4_MASK)
	{
		button_readval4();
	}

}



void main(void)
{
	int err;
printk("starting bluetooth central heart rate example\n");

err=bt_hrs_client_init(&hrs_c);
	if(err)
	{
		printf("heart rate service client failed to init(err %d)\n",err);
		return;
	}

err=bt_enable(NULL);
	if(err){
		printk("bluetooth init failed(err %d)\n",err);
		return;
	}
 
printk("bluetooth initialed\n");


if(IS_ENABLED(CONFIG_SETTINGS)){
	settings_load();
}
//

scan_init();



	err = bt_conn_auth_cb_register(&auth_callbacks);
	if (err) {
		printk("Failed to register authorization callbacks.\n");
		return;
	}

	/*err = dk_leds_init();
	if (err) {
		printk("LEDs init failed (err %d)\n", err);
		return;
	}*/

	//
/*
err=bt_scan_start(BT_SCAN_TYPE_SCAN_ACTIVE);
if(err){
	printk("scanning failed to start(err %d)\n",err);
	return;
}
*/


//printk("scanning succesfully started\n");
	/*err = bt_conn_auth_info_cb_register(&conn_auth_info_callbacks);
	if (err) {
		printk("Failed to register authorization info callbacks.\n");
		return;
	}*/

	//



	

	
     
	 	


	
   err=dk_buttons_init(button_handler);
	if(err)
	{
		printk("failed to initialize buttons(err %d)\n",err);
		return;
	}
	
	


	
	//printk("Hello World! %s\n", CONFIG_BOARD);
}

