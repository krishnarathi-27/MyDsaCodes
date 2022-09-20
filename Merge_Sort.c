#include<stdio.h>
#include<stdlib.h>

void Merge(int *A,int *temp,int l1,int u1,int l2,int u2)
{
    int i = l1,k = l1,j = l2;

    while(i<=u1 && j<=u2)
    {
        if(A[i]<A[j])
        temp[k++] = A[i++];
        else
        temp[k++] = A[j++];
    }

    while(i<=u1)
    {
        temp[k++] = A[i++];
    }

    while(j<=u2)
    {
        temp[k++] = A[j++];
    }
}

void copy(int *a,int *t,int l,int h)
{
    for(int i=l;i<=h;i++)
    a[i] = t[i];
}
void MergeSort(int *A,int l,int u)
{
    int mid,t[10];
    if(l<u)
    {
        mid = (l+u)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,u);
        Merge(A,t,l,mid,mid+1,u);
        copy(A,t,l,u);
    }
}
void printArray(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
}


int main()
{
    int n;
    printf("Enter the size of the array:- ");
    scanf("%d",&n);
    int a[n],i;

    printf("Enter elements in the array\n");

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    MergeSort(a,0,n);
    printArray(a,n);
    return 0;
}