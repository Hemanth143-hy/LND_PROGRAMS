#include<stdio.h>
int search()
{
	int key;
	int arr[10];
	int flag ;
	for(int i = 1; i <10; i++) {
		if (arr[i] == key) {
			return i + 1;
		}
		return -1;
	}
}
int main()
{
	int arr[10];
	int key;
	int flag;
	printf("enter the values to the array :");
	for(int i = 1; i < 10; i++)
		scanf(" %d " ,&arr[i]);

	printf("enter the value to search :"); 
	scanf("%d " , &key);
	int se = search(); 
	if (se == -1) {
			printf("element is not present");
		}else {
			printf("element is present");
		}
}

//	int search()	
/*	for(int i = 1; i <10 ;i++) {
	if(arr[i] == key) {
		flag =1;
			}	
	}	

	if(flag == 1) {
		printf("the value is found");
    }else{
		printf("the value is not found");
	return 0;
*/
