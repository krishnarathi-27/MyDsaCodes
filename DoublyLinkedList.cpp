#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*head;

void create(int item , struct Node *&temp)
{
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=item;
    temp->next=NULL;
    temp->prev=NULL;
}

void InsertAtTail()
{
    int item;
    cout << "Enter the data to insert at the  tail of the linked list" << endl;
    cin >> item;
    struct Node *newNode;
    create(item,newNode);

    struct Node *ptr;
    ptr=head;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->prev=ptr;
}

void InsertAtBegin()
{
    int item;
    cout << "Enter the data to insert at the head of the linked list " << endl;
    cin >> item;
    struct Node *newNode;
    create(item,newNode);

    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void InsertAtPos(int p)
{
    int item;
    cout << "Enter the data to insert at the specific position of the linked list " << endl;
    cin >> item;
    struct Node *newNode;
    create(item,newNode);

    int count=0;
    struct Node *ptr;
    ptr=head;
    while(ptr->next!=NULL)
    {
       count++;
       if(count==p)
       {
           ptr->prev->next=newNode;
           newNode->prev=ptr->prev;
           newNode->next=ptr;
           ptr->prev=newNode;
       }
       ptr=ptr->next;
    }
}
void DeleteAtTail()
{
    if(head==NULL)
    cout << "There are no nodes to delete" << endl;

    struct Node *ptr,*ptr1;
    ptr=head;
    while(ptr->next!=NULL)
    {
         ptr1=ptr;
         ptr=ptr->next;
    }
    ptr1->next=NULL;
    ptr->prev=NULL;
    cout << "Deleted Node from tail" << endl;
    free(ptr);

}

void DeleteAtBegin()
{
    if(head==NULL)
    cout << "There are no nodes to delete" << endl;

    struct Node *ptr;
    ptr=head;
    ptr->prev=NULL;
    head=ptr->next;
    cout << "Deleted node from begin " << endl;
    free(ptr);
}

void DeleteAtPos(int p)
{
    if(head==NULL)
    cout << "There are no nodes available" << endl;

    struct Node *ptr;
    ptr=head;

    int count=0;
    while(ptr!=NULL)
    {
        count++;
        if(count==p)
        {
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            cout << "Node is deleted" << endl;
            delete ptr;
            break;
        }
        ptr=ptr->next;
        
    }
}
void reverse()
{
    struct Node *current,*temp;
    temp=NULL;
    current=head;
    while(current!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
    
        current=current->prev;
    }
   if(temp!=NULL)
   head=temp->prev;
    cout << "Reversed Successfully" << endl;
}
void display()
{
    struct Node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout << ptr->data << " -> " ;
        ptr=ptr->next;
    }
    cout << "NULL" << endl;
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
        cout << "8.Reverse the linked list \n9.Display the linked list" << endl;
        cout << "Enter your choice" << endl;
          cin >> choice;

          switch(choice)
          {
              case 1 :  {   int item;
                        cout << "Enter the element for the first node" << endl;
                        cin >> item;
                        create(item,t);
                        head=t;
                        }
                        break;
              case 2 : InsertAtTail();
                       break;
              case 3 : InsertAtBegin();
                       break;
              case 4 : {
                          int position;
                          cout << "Enter the position to insert " << endl;
                          cin >> position;
                          InsertAtPos(position);
                       }
                        break;
              case 5 :  DeleteAtTail();
                        break;
              case 6 :  DeleteAtBegin();
                        break;
              case 7 : {
                          int position;
                          cout << "Enter the position to delete " << endl;
                          cin >> position;
                          DeleteAtPos(position);
                       }
                       break;
              case 8 : reverse();
                       break;
              case 9 : display();
                       break;
              default : cout << "You have entered wrong choice " << endl;
                       break;
                
          }
    }while(1);
   
    
    
    return 0;
}