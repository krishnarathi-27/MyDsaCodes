#include<stdio.h>
#include<stdlib.h>
#define size 4

int array[size],front = -1 ,rear = -1;

int isFull()
{
    if((front == rear +1) || (front ==0 && rear == size-1))
    return 1;
return 0;
}

int isEmpty()
{
    if(front == -1)
    return 1;
return 0;
}

void insertRear()
{
    if(isFull())
    {
    printf("Queue is Full\n");
    return;
    }
    else
    {
        int item;
        printf("Enter the item to insert\n");
        scanf("%d",&item);
        if(front == -1) 
        front = 0;
        rear = (rear +1)%size;
        array[rear] = item;
        printf("Element inserted at rear end is : %d",item);
    }

}

void insertFront()
{
    if(isFull())
    {
        printf("Queue is Full\n");
        return;
    }
    else
    {
    int element;
    printf("\nEnter the element to insert at front end\n");
    scanf("%d",&element);
    if(front == -1)
    {
      rear = 0;
      front = 0;
    }
    else if(front == 0)
       front = size -1;
    else
       front = front -1;
    array[front] = element;

    }

}

void deleteFront()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty\n");
        return;
    }

    else
    {
       int item = array[front];
        if(front == rear)
        front = rear = -1;
        else
        front = (front + 1) % size;
        printf("Deleted Element from front end is %d",item);
    }
}

void deleteRear()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty\n");
        return;
    }
    else
    {
        int item = array[rear];
        if(front == rear)
        front = rear = -1;
        else if(rear == 0)
        rear = size -1;
        else
        rear = rear -1;
    }
}

void display()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty\n");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",array[i]);
    }
    
    printf("\n");
}

int main()
{

    
     int choice;
     do
     {
         printf("\n1.To insert Element at rear end \n2.To insert element at front end\n");
         printf("3.Delete element at rear end \n4.Delete element at front end \n5.Display elements in queue\n");
         printf("\nEnter your choice\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1 : insertRear();
                      break;
             case 2 : insertFront();
                      break;
             case 3 : deleteRear();
                      break;
             case 4 : deleteFront();
                      break;
             case 5 : display();
                      break;
            default : printf("You have entered worng choice\n");
                      break;
         }
     } while (1);
     
    return 0;
}