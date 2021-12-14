#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head;

void create()
{
    int item;
    cout << "Enter the item " << endl;
    cin >> item;
    struct Node *p;
    p=new struct Node;
    p->data=item;
    p->next=NULL;
    head=p;   
}

void insertAtTail()
{
    int item;
    cout << "Enter the item to be inserted at end" << endl;
    cin >> item;
    struct Node *ptr;
    ptr=new struct Node;
    ptr->data=item;
    ptr->next=NULL;

    struct Node *temp;
    temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}
void insertAtBegin()
{
   int item;
   cout << "Enter the item to be inserted at begin" << endl;
   cin >> item;
   struct Node *ptr;
   ptr =(struct Node *) malloc(sizeof (struct Node));
   ptr->data=item;
   ptr->next=head;
   head=ptr;

}
void insertAtPosition()
{
    struct Node *p;
    p=new struct Node;
    int item;
    cout << "\nEnter the item to be inserted at begin" << endl;
    cin >> item;
    p->data=item;
    p->next=NULL;
    struct Node *ptr;
    ptr=head;
    int key;
    cout << "Enter the node data after which node is to be inserted" << endl;
    cin >> key;
    while(ptr!=NULL)
    {
        if(key == ptr->data)
        {
            p->next=ptr->next;
            ptr->next=p;
            break;
        }
        ptr=ptr->next;
    }
}
void deletionAtBegin()
{
   if(head==NULL)
   cout << "Linked List is empty , Underflow " << endl;
   
       struct Node *ptr;
       ptr=head;
       head=ptr->next;
       delete ptr;
       cout << "\nNode deleted from begining " << endl;
   
}
void deleteAtEnd()
{
    if(head==NULL)
    cout << "Linked List is empty , Underflow" << endl;
    
        struct Node *ptr,*ptr1;
        ptr=head;
        while(ptr->next!=NULL)
        {
                ptr1=ptr;
             ptr=ptr->next;
        }
     
        ptr1->next=NULL;
        delete ptr;
        cout << "Node from ending is deleted " << endl;
}
void deleteAtPosition()
{
    int item;
    if(head==NULL)
    cout << "Linked list is empty , Underflow " << endl;
    cout << "Enter the node data which you want to delete" << endl;
    cin >> item;
    struct Node *ptr , *ptr1;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->next->data==item)
        {
        ptr1=ptr->next;
        ptr->next=ptr->next->next;
        free(ptr1);
        break;

        }
    ptr=ptr->next;
    }
    cout << "Node has been deleted " << endl;
}
void reverse()
{
    struct Node *currentNode, *prevNode;
    if(head!=NULL)
    {
        prevNode=head;
        currentNode=head->next;
        head=head->next;
        prevNode->next=NULL;

        while(head!=NULL)
        {
            head=head->next;
            currentNode->next=prevNode;
            prevNode=currentNode;
            currentNode=head;
        }
        head=prevNode;
        cout << "LinkedList reversed successfully " << endl;

    }
}
void display()
{
    struct Node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout << ptr->data  << " -> "<< " " ;
        ptr=ptr->next;
    }
    cout << "NULL" << endl;
}


int main()
{
   
    int choice;
    do
    {
       cout << "1.Create The Link List \n2.Insert element at the head \n3.Insert element at the end"<< endl ;
       cout <<  "4.Insert element  at any specific position\n5.Delete Element at the beginning" << endl;
       cout << "6.Delete element at the end \n7.Delete element at the specific position \n8.Reverse linked list" << endl;
       cout << "9.Display the linked list" << endl;
       cout << "Enter  your choice " << endl;
       cin >> choice;

       switch(choice)
       {
           case 1 : create();
                    break;
           case 2 : insertAtBegin();
                    break;
           case 3 : insertAtTail();
                    break;
           case 4 : insertAtPosition();
                    break;
           case 5 : deletionAtBegin();
                    break;
           case 6 : deleteAtEnd();
                    break;
           case 7 : deleteAtPosition();
                    break;
           case 8 : reverse();
                    break;
           case 9: display();
                    break;
           default : cout << "You have entered wrong choice " << endl;
                    break;


       }

    }while(1);

    return 0;
}