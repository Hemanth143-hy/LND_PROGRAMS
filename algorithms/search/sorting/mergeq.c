#include<stdio.h>
void mergesort(int array[],int start , int end)
{
	int mid;
	if(start < end) {
	mid = (start+end)/2;
	mergesort(array , start, mid); //left side array
	mergesort(array , mid+1 , end); //right side array
	merge(array , start , mid  , end); //used to merge
	}
}

void merge(int array[] , int start , int mid  , int end)
{
	int i;
	int j;
	int k;
	int n1 = mid - start+1;
	int n2 = end - mid;
	int leftarr[n1],rightarr[n2];
	for(int i = 0; i < n1;i++)
	leftarr[i]=array[start+i]; 
	for(int j = 0; j < n2;j++)
	rightarr[j] = array[mid +1 + j];
	i = 0;
	j = 0;
	k = start;
	while(i < n1 && j < n2) {
		if(leftarr[i] <= rightarr[j]) {	
			array[k] = leftarr[i];
			i++;
		}
		else {
			array[k] = rightarr[j];
			j++;
		}
		k++;
	}	
	while(i < n1)
	{
		array[k]=leftarr[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		array[k] = rightarr[j];
		j++;
		k++;
	}	
}
	
int main()
{
	int array[30];
	int number;
	int i = 0;
	printf("enter no of elements:");
	scanf("%d",&number);
	printf("enter the elements to the array:");
	for(i = 0; i < number ; i++)
		scanf("%d",&array[i]);
		mergesort(array, 0 , number-1);
		printf("\n Sorted array is:");
		for (i = 0; i < number; i++)
		printf("%d " , array[i]);
		return 0;
}
/*
void mergesort(int array[] , int start , int end)
{
	int mid;
	if(start < end) {
	mid = (start+end)/2;
	mergesort(array , start, mid); //left side array
	mergesort(array , mid+1 , end); //right side array
	merge(array , start , mid  , end); //used to merge
	}
}
void merge(int array[] , int start , int mid , int end)
{
	int i;
	int j;
	int k;
	int n1 = mid - start+1;
	int n2 = end-mid;
	int leftarr[n1],rightarr[n2];
	for(int i = 0; i < n1;i++)
	leftarr[i]=array[start+i];
	for(int j = 0; j < n2;j++)
	rightarr[j] = array[mid + 1+ j];
	i = 0;
	j = 0;
	k = start;
	while(i < n1 && j < n2) {
		if(leftarr[i] <= rightarr[i]) {	
			array[k] = leftarr[i];
			i++;
		}
		else {
			array[k] = rightarr[j];
			j++;
		}
		k++;
	}	
	while(i < n1)
	{
		array[k]=leftarr[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		array[k] = rightarr[j];
		j++;
		k++;
	}	
}
*/			
