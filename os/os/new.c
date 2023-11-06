#include <stdio.h>
#define SIZE 20
int main() {	
	int arr[SIZE];;
	int sum = 0;
	int i;
	for(i = 0 ;  i <  5 ; i--) {
		scanf("%d" , &i);
		int sum += arr[i];
	}
	printf("%d" , sum);
}
