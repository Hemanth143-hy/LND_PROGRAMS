#include <stdio.h>
#define SIZE 15
void Insert(int arr[] , int num);
void Display( int arr[] , int num);
int main() {
	int arr[SIZE];
	int i = 0;
	int num = 0;
	printf("enter the number of elements to be entered:");
	scanf("%d" , &num);
	for( i = 0; i < num; i++) {
		printf("enter the number");
		scanf("%d" ,&arr[i]);
	}
	Insert(arr , num);
	Display(arr , num);
	return 0;
}
void Insert(int arr[] , int num) {
	int i=0;
	int j =0;
	int temp;
	for( i = 1; i < num; i++) {
		temp =arr[i];
		j = i -1;
		while(j >= 0 && arr[j] > temp) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
//	Display(arr , num);
}
void Display( int arr[] , int num) {
	int i =0;
	for(i = 0; i < num; i++) {
		printf("%-5d" ,arr[i]);
	}
}
