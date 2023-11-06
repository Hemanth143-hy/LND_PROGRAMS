#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket, bytes_read;
    struct sockaddr_rc server_address = {0};
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Initialize Bluetooth communication
    client_socket = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    if (client_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set server address
    server_address.rc_family = AF_BLUETOOTH;
        server_address.rc_bdaddr = *BDADDR_ANY;

//    str2ba("5C:F3:70:66:95:A5", &server_address.rc_bdaddr);
    server_address.rc_channel = (uint8_t)5;// Use channel 1

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(client_socket);
        exit(1);
    }

    // Establish the chat session
    printf("Connected to the server. Start typing messages:\n");
    while (1) {
        printf("You: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        bytes_read = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("Server: %s", buffer);
        }
    }

    // Terminate the connection
    close(client_socket);
    return 0;
}


