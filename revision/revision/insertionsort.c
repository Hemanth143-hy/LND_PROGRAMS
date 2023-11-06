#include <stdio.h>
#define SIZE 50
void Insertion_Sort(int arr[] ,  int num);
int main() {
	int arr[SIZE];
	int num = 0;
	int i = 0;
	printf("enter the no of the elements:");
	scanf("%d",&num);
	for(i = 0; i < num ; i++) {
		scanf("%d",&arr[i]);
	}
	Insertion_Sort(arr , num);
	for(i = 0; i < num ; i++) {
		printf("%d\t",arr[i]);
	}
}
void Insertion_Sort(int arr[] , int num) 	{
	int i =0;
	int temp;
	int j;
	for(i = 1; i < num ; i++) {
		temp = arr[i];
		j = i - 1;
		while( j >= 0 && arr[j] >temp) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}	
