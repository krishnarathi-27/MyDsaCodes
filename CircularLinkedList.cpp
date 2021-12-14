#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*head;
void create(int item,struct Node *&temp)
{
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=item;
    temp->next=NULL;
   
}
void insertAtTail()
{
    int item;
    cout << "Enter the item to insert at tail" << endl;
    cin >> item;
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    create(item,newNode);
    struct Node *ptr;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->next=head;
}
void insertAtbegin()
{
    int item;
    cout << "Enter the item to insert at the head " << endl;
    cin >> item;
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    create (item,newNode);
    newNode->next=head;
    struct Node *ptr;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    head=newNode;
    
}

void insertAtPosition(int p)
{
    int item,count=0;
    cout << "Enter the item to insert at position " << endl;
    cin >> item;
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    create (item,newNode);
    struct Node *ptr;
    ptr=head;
    while(ptr->next!=head)
    {
        count++;
        if(count==(p-1))
        {
            newNode->next=ptr->next;
            ptr->next=newNode;
            break;
        }
        ptr=ptr->next;
    }
    
}
void deleteAtbegin()
{
   
    if(head==NULL)
    cout << "UnderFLow" << endl;
    if(head->next==head)
    {
        head==NULL;
        free(head);
    }
     struct Node *ptr;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=head->next;
    free (head);
    head=ptr->next;
}

void DeleteAtEnd()
{
    struct Node *ptr,*ptr1;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr1=ptr;
        ptr=ptr->next;
    }
    ptr1->next=head;   //ptr1->next=ptr->next;
    free(ptr);

}

void DeleteAtPosition(int p)
{
    struct Node *ptr,*ptr1;
    ptr=head;
    int count=0;
    while(ptr->next!=head)
    {
        count++;
        if(count==(p-1))
        {
           ptr1=ptr;
           ptr=ptr->next;
           ptr1->next=ptr->next;
           free(ptr);
            break;
        }
        
    }
}
void display()
{
    struct Node *ptr;
    ptr=head;

    do
    {
        cout << ptr->data << " ";
        ptr=ptr->next;
    }while(ptr!=head);
    cout << endl;
}

int main()
{
  struct Node *t;  
     int choice;
  
    do
    {
        cout << "1.Create the linked list" << endl;
        cout << "2.Insert node at the tail \n3.Insert node at begining \n4.Insert node at specific position" << endl;
        cout << "5.Delete node at tail \n6.Delete node at the begining \n7.Delete node at spcific position" << endl;
        cout << " 8.Display the linked list" << endl;
        cout << "Enter your choice" << endl;
          cin >> choice;

          switch(choice)
          {
              case 1 :  {   int item;
                        cout << "Enter the element for the first node" << endl;
                        cin >> item;
                        create(item,t);
                        head=t;
                        t->next=head;
                        }
                        break;
              case 2 : insertAtTail();
                       break;
              case 3 : insertAtbegin();
                       break;
              case 4 : {
                          int position;
                          cout << "Enter the position to insert " << endl;
                          cin >> position;
                          insertAtPosition(position);
                       }
                        break;
              case 5 :  DeleteAtEnd();
                        break;
              case 6 :  deleteAtbegin();
                        break;
              case 7 : {
                          int position;
                          cout << "Enter the position to delete " << endl;
                          cin >> position;
                          DeleteAtPosition(position);
                       }
                       break;
            //   case 8 : reverse();
            //            break;
              case 8 : display();
                       break;
              default : cout << "You have entered wrong choice " << endl;
                       break;
                
          }
    }while(1);
    return 0;
}