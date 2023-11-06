#include <stdio.h>
#define SIZE 50
void Quick_Sort(int arr[] , int start , int end);
int Partition(int arr[] ,int start, int end); 
void Print(int arr[] , int num);
int main()
{
	int arr[SIZE];
	int num;
	int i;
	printf("enter the no of elements:");
	scanf("%d",&num);
	for(i =  0; i < num; i++) {
		scanf("%d",&arr[i]);
	}
	Quick_Sort(arr , 0 , num-1);
	Print(arr , num); 
}
void Quick_Sort(int arr[] , int start , int end) 
{
	if(start < end) {
		int p;
		p = Partition(arr , start, end);
		Quick_Sort(arr , start , (p-1));
		Quick_Sort(arr , (p+1) , end);
	}
}
int Partition(int arr[] , int start , int end) {	
	int pivot = arr[end];
	int pindex = start;
	int i;
	int temp;
	for( i = start; i < end ; i++) {	
		if(arr[i] <= pivot) {	
			temp = arr[i];
			arr[i] = arr[pindex];
			arr[pindex] = temp;
			pindex++;
		}
	}
	temp = arr[end];
	arr[end] = arr[pindex];
	arr[pindex] = temp;
	return pindex;
}
void Print(int arr[] , int num) {	
	int i = 0;
	for( i = 0; i < num ; i++) {	
		printf("%d\t",arr[i]);
	}
} 	
