#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev; //*
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void display(PNODE head)
{
  printf("data from linked list\n:");
  while(head!=NULL)
  {  
      printf("|%d|<=>",head->data);
      head=head->next;
  }
  printf("NULL\n");
}

int count(PNODE head)
{
    int icnt=0;
    while(head!=NULL)
  {
      icnt++;
     
      head=head->next;
  }
 return icnt;
}

void insertfirst(PPNODE head,int no)
{
   PNODE newn=NULL;

   newn=(PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;  //*

   if(*head==NULL)//ll is emplty
   {
     *head=newn;
   }
   else // ll contain atleast one node
   {
        newn->next=*head;
        (*head)->prev=newn; //*
        *head=newn;   
   }

}

void insertlast(PPNODE head,int no)
{
    
   PNODE newn=NULL;
    PNODE temp=NULL;
   newn=(PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;  //*


   if(*head==NULL)//ll is empty
   {
     *head=newn;
   }
   else // ll contain atleast one node
   {
     temp=*head;
     while(temp->next!=NULL)
     {
         temp=temp->next;
        
     }
      temp->next=newn;
         newn->prev=temp;  //*
     
   }
}

void deletefirst(PPNODE head)
{
    
  if(*head==NULL) //ll is empty
  {
      return;
  }
  else if((*head)->next==NULL)//single node
  {
     free(*head);
     *head=NULL;
  }

  else  //atleast more than one node
  {
    *head=(*head)->next;
    free((*head)->prev);//*
    (*head)->prev=NULL;//*
  }
 
}

void deletelast(PPNODE head)
{
   PNODE temp=NULL;
  if(*head==NULL) //ll is empty
  {
      return;
  }
  else if((*head)->next==NULL)//single node
  {

     free(*head);
     *head=NULL;
  }
  else  //atleast more than one node
  {
    temp=*head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
   free(temp->next);
    temp->next=NULL;
  }
}

 void insertatposition(PPNODE head,int no,int pos)
 {
     PNODE temp=NULL;
     PNODE newn=NULL;
     int size=0;
     int icnt=0;
     size=count(*head);

  if(pos<1||pos>(size+1))
   {
     printf("invalid position");
     return;
   }  
   if(pos==1)
   {
       insertfirst(head,no);
   }
  else if(pos==(size+1))
   {
       insertlast(head,no);
   }
   else
   {
       temp=*head;
       newn=(PNODE)malloc(sizeof(NODE));

       newn->data=no;
       newn->next=NULL;
       newn->prev=NULL;  //*

       for(icnt=1;icnt<(pos-1);icnt++)
       {
         temp=temp->next;   
       }
       newn->next=temp->next;
       temp->next->prev=newn;  //*
       temp->next=newn;
       newn->prev=temp;   //*
   }
 }

 void deleteatposition(PPNODE head,int pos)
 {
     PNODE temp=NULL;
     PNODE prev=NULL;
      int size=0;
      int  icnt=0;
     size=count(*head);

  if(pos<1||pos>size)
   {
     printf("invalid position");
     return;
   }  
   if(pos==1)
   {
       deletefirst(head);
   }
  else if(pos==size)
   {
       deletelast(head);
   }
   else
   {
       temp=*head;
      
       for(icnt=1;icnt<(pos-1);icnt++)
       {
         temp=temp->next;   
       }
      temp->next=temp->next->next;
      free(temp->next);
      temp->next->next=prev; 
      }
 }

int main()
{
    PNODE first=NULL;
    int ret=0;
    insertfirst(&first,21);
    insertfirst(&first,11);
    insertlast(&first,51);
    insertlast(&first,101);
     
    display(first);
    ret=count(first);
    printf("the linked list are in:%d",ret);

    deletefirst(&first);
    display(first);
    ret=count(first);
    printf("the linked list are in:%d",ret);

    deletelast(&first);
    display(first);
    ret=count(first);
    printf("the linked list are in:%d",ret);
    
    insertatposition(&first,75,2);
    display(first);
    ret=count(first);
    printf("the linked list are in:%d",ret);

    deleteatposition(&first,2);
    display(first);
    ret=count(first);
    printf("the linked list are in:%d",ret);
   
    return 0;
}