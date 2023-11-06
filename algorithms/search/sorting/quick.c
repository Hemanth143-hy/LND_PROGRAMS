#include<stdio.h>  
void quicksort(int arr[25],int first,int last) {  
int i; 
int j; 
int pivot;   
int temp;   
if (first < last){         
pivot = first;
i = first;
j = last;
while (i < j) {
while (arr[i] <= arr[pivot] && i < last)
                 i++;
                 while (arr[j] > arr[pivot])
               j--;
             if (i < j) {
                     temp = arr[i];
                    arr[i] = arr[j];
                     arr[j] = temp;
                }         }
  temp = arr[pivot];
       arr[pivot] = arr[j];
      arr[j] = temp;      
 quicksort(arr,first,j-1);
       quicksort(arr,j+1,last);
    }
 }
int main(){
     int i;
     int arr[25];
     int size;
 printf("Enter how many elements : ");
 scanf("%d", &size);
 printf("Enter  elements: ");
    for(i = 0;i < size; i++)
       scanf("%d",&arr[i]);
    quicksort(arr,0,size-1);
   printf("Order of Sorted elements: ");
    for(i = 0; i < size; i++)
      printf(" %d", arr[i]);
    return 0;
}
