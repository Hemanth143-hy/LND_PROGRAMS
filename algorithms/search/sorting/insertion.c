#include <stdio.h>
 /* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < 5; i++) {
	key = arr[i];
	j = i - 1;
	while (j >= 0 && arr[j] > key) {
		arr[j + 1] = arr[j];
	      j = j - 1;     }
      arr[j + 1] = key;
     }
 }

 void printArray(int arr[], int n)
 {
     int i;
    for (i = 0; i < 5; i++)
         printf("%d ", arr[i]);
     printf("\n");
 }

 int main()
 {
    int arr[5];
     int n;
    printf("Enter elements");
     for (int i = 0; i < 5; i++) {
         scanf("%d", &arr[i]);
     }
 //  int n = sizeof(arr) / sizeof(arr[0]);

     insertionSort(arr, n);
     printArray(arr, n);

     return 0;
 }

