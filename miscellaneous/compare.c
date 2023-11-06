#include<stdio.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

void findduplicateele(int arr[], const int size)
{
	int num;
	int num1;
	printf("Reapeating elements are ");
	for (num = 0; num < size; num++) {
		for (num1 = num + 1; num1 < size; num1++) {
			if (arr[num] == arr[num1]) {
				printf(" %d ", arr[num]);
			}
		}
	}
}
int main()
{
	int arr[] = {4,2,4,5,2,3,1};
	const int N = ARRAY_SIZE(arr);
	findduplicateele(arr, N);
	return 0;
}
                                                     
