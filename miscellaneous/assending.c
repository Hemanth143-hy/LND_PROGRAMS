#include<stdio.h>
int array_asc_order(int *array, int size) 
{
	int num;
	int num1;
	int temp;
	for (num = 0; num < 5; ++num) {
	for(num1 = num + 1; num1 < size; ++num1) {
	if (array[num] > array[num1]) {
 	temp = array[num];
 	array[num] = array[num1];
 	array[num1] = temp;
		 	}         
		}
 	}
	printf("Number arranged in ascending order:");
 	for (num = 0; num < size; ++num)
 	printf("%d ", array[num]);
}
int main()\
 {
 	int num;
	int size;
 	int array[30];
 	printf("Enter the size of array:");
 	scanf("%d", &size);
 	printf("Enter the elements:");
	for (num = 0; num < size; ++num)
		scanf("%d", &array[num]);
	array_asc_order(array,size);
	return 0;
}


