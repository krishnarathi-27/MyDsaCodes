#include<stdio.h>

void InsertionSort(int *A,int n)
{
    int i,j,x;
    
    for(i=1;i<n;i++)
    {
        j = i-1;
        x = A[i];
        while(j>=-1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
          A[j+1] = x;
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
    int a[8];
    printf("Enter 8 elements of the array\n");
    for(int i=0;i<8;i++)
    scanf("%d",&a[i]);

    InsertionSort(a,8);
    printArray(a,8);
    return 0;
}