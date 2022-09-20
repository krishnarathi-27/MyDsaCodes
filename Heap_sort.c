#include<stdio.h>

void insert(int A[],int n)
{
    int i=n,temp;
    temp = A[i];

    while(i>1 && temp>A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int delete(int A[],int n)
{
    int i,j,x,value;
    value = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = value;
    i=1 ; j = i*2;
    
    while(j<n-1)
    {
        if(A[j+1] > A[j])
        j = j+1;
        if(A[i] < A[j])
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] =  temp;
            i=j;
            j = 2*j;
        }
        else
          break;
    }

   return value;
}
int main()
{
    int array[] = {0,10,20,30,25,5,40,35};

    for(int i=2;i<=7;i++)
    {
        insert(array,i);
    }

    for(int i=1;i<=7;i++)
      printf("%d ",array[i]);

      printf("\n");

   for(int i=7;i>1;i--)
    delete(array,i);

      for(int i=1;i<=7;i++)
      printf("%d ",array[i]);

      printf("\n");


    return 0;
}