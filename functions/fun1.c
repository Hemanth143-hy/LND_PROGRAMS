#include <stdio.h>
#include<string.h>
int arrprint(int arr[]);
//int arrprint1(int arr[]);
//int arrprint2(int arr[]);
int main() {
	int arr[10];
	int i;
	printf("enter the elements:");
	for(i = 0 ; i < 10 ; i++) {
	scanf("%ls",&arr[i]);
	}
	arrprint(arr);
//	arrprint1(arr);
//	arrprint2(arr);
}
int arrprint(int arr[]) {
	int i;
	for(i = 9; i >= 0; i--) {
		printf(" the reverse :%c",arr[i]);
	}
}
int arrprint1(int arr[]) {
	int i;
	for(i = 0; i < 10 ; i++) {
		printf(" normal :%d\n",arr[i]);
	}
}
int arrprint2(int arr[]) {
	int i;
	for(i = 0; i < 10; i++) {
		printf("%d\n",arr[i]);
	}
}

