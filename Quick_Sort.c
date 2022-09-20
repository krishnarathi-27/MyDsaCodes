#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *A,int l,int h)
{
   int pivot = A[l];
   int i = l , j = h;

   do
   {
       do
       {
           i++;
       } while (A[i]<=pivot);
       do
       {
           j--;
       } while (A[j]>pivot);
       
        if(i<j)
        swap(&A[i],&A[j]);
   }while(i<j);

   swap(&A[j],&A[l]);

   return j;
}

void QuickSort(int *A,int l,int h)
{
   int j;
   if(l<h)
   {
       j = partition(A,l,h);
       QuickSort(A,l,j);
       QuickSort(A,j+1,h);
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
    int n;
    printf("Enter the size of the array;- ");
    scanf("%d",&n);
    int a[n],i;

    printf("Enter elements in the array\n");

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    QuickSort(a,0,n);
    printArray(a,n);

    return 0;
}