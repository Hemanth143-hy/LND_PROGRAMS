#include"header.h"
//void mergesort(int a[],int i,int j);
//void merge(int a[],int i1,int j1,int i2,int j2);
int main() {
        int a[30],n,i;
        printf("Enter no of elements:");
        scanf("%d",&n);
        printf("Enter array elements:");
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        mergesort(a,0,n-1);
        printf("\nSorted array is :");
        for(i=0;i<n;i++)
        printf("%d ",a[i]);
        return 0;
}
