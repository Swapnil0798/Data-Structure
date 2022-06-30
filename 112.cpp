#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
 
 typedef int BOOL;

 struct node
 {
     int data;
     node*next;
     node*prev;
 
 }
 typedef struct node NODE;
 typedef struct node* PNODE;
 class doubly linkedlist
 {
   private:
     PNODE head;
     public:
     doubly linkedlist();
     ~doubly linkedlist();

     BOOL insertfirst(int);
     BOOL insertlast(int);
     BOOL insertatposition(int);

     inline void display();
     inline void count();

     BOOL deletefirst();
     BOOL deleteatposition();
     BOOL deletelast();
     
 };
 doubly linkedlist::doublylinkedlist()
 {
     head=NULL;
 }
 doubly linkedlist::~doublylinkedlist()
 {
     PNODE temp=head;
     if(head!=NULL)
     {
         while(head!=NULL)
         {
             head=head->next;
             delete temp;
             temp=head;
         }
     }
 }
 
 BOOL dobly linkedlist::insertfirst(int ino)
 {
     PNODE newn =NULL;
     newn=new NODE;
     if(newn==NULL)
     {
         return FALSE;
     }
     newn->next=NULL;
     newn->prev=NULL;
     newn->data=no;
     if(head==NULL)
     {
         head=newn;
     }
     else
     {
         head->prev=newn;
         newn->next=head;
         head=newn;
     }
     return TRUE;
 }
 BOOL doublylinkedlist::insertatposition(int no,int pos)
 {
     if(head==NULL)||(pos>count()+1)||(pos<=0)
     {
         return FALSE;
     }
     if(pos==1)
     {
         return(insertfirst(no));
     }
     else if(pos==(count())+1)
     {
         return(insertlast(no));
     }
     else
     {
         PNODE newn=NULL,temp=head;
         newn=newn NODE;
         if(newn==NULL)
         {
             return FALSE;
         }
         newn->next=NULL;
         newn->prev=NULL;
         newn->data=no;
         for(int i=1;i<=(pos-1);i++)
         {
             temp=temp->next;
         }
         newn->next=temp->next;
         temp->next->prev=newn;
         newn->prev=temp;
         temp->next=newn;

     }
     return TRUE;
 }
BOOL doubly linkedlist::deletefirst()
{
    PNODE temp=head;
    if(head==NULL)
    {
        return FALSE;
    }
    else
    {
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
    return TRUE;
}

BOOL doubly linkedlist::deletelast()
{
    if(head==NULL)
    {
        return FALSE;
    }
    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
    }
    else
    {
       PNODE temp=head;
       while((temp->next)!=NULL)
       {
           temp=temp->next;
       }
       temp->prev->next=NULL;
       delete temp
    }
    return TRUE;
}
BOOL doubly linkedlist::deleteatposition(int pos)
{
   if((head==NULL)||(POS>count())||(pos<=0))
   {
       return FALSE;
   }
   else if(pos==1)
   {
       datetefirst();
   }
   else if(pos==(count()))
   {
       deletelast();
   }
   else
   {
     PNODE temp=head;
     for(int i=1;i<(pos-2);i++)
     {
         temp=temp->next;
     }
     temp->next=temp->next->next;
     delete temp->next->prev;
     temp->next->prev=temp;
     
   }
   return TRUE;
}