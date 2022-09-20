#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int *A,int n)
{
    int i,j,k;
    for(i = 0;i<n;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
            k = j;
        }

        swap(&A[k],&A[i]);
    }
}
void printArray(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}


int main()
{
    int a[8],i;

    printf("Enter 8 elements in the array\n");

    for(i=0;i<8;i++)
    scanf("%d",&a[i]);

    SelectionSort(a,8);
    printArray(a,8);

    return 0;
}