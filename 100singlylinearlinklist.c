#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Insertfirst(PPNODE head,int no)
{
   PNODE newn=NULL;  
   newn=(PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;
   
   if(*head==NULL)
   {
     *head=newn;
   }
   else
   {
     newn->next=*head;
     *head=newn; 
   }

}

void Insertlast(PPNODE head,int no)
{
   PNODE newn=NULL;  
   PNODE temp=NULL;
   newn=(PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;

   if(*head==NULL)
   {
     *head=newn;
   }
   else
   {
     PNODE temp=*head;
     while(temp->next!=NULL)
    {
      temp=temp->next;
    } 
    temp->next=newn;

   }

}

void display(PNODE head)
{
  printf("element are linkedlist are:\n");
  while(head!=NULL)
  {
    printf("| %d |->",head->data);
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


void deletefirst(PPNODE head)
 {
   PNODE temp=NULL;
   if(*head==NULL)
   {
     return;
   }
   else
   {
     PNODE temp=*head;
     *head=temp->next;
     free(temp);       
   }
  
 }
 
void deletelast(PPNODE head)
 {
   PNODE temp=NULL;
   if(*head==NULL)
   {
     return;
   }
  else if((*head)->next==NULL)
   {
     free(*head);
     *head=NULL;
   }
   else
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
 void Insertatposition(PPNODE head,int no,int pos)
 {
   int size=0;
   size=count(*head);
   PNODE newn=NULL; 
   PNODE temp=NULL; 

 if((pos<1)||(pos>(size+1)))     /////////filter////////
   {
     printf("position is invalid\n");
     return;
   }
if(pos==1)
  {
    Insertfirst(head,no);
  }
else if(pos==(size+1))
 {
  Insertlast(head,no);
 }
else
{
  
   newn=NULL;
   newn=(PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;

   temp=*head;

   for(int icnt=1;icnt<(pos-1);icnt++)
   {
     temp=temp->next;
   }

     newn->next=temp->next;
     temp->next=newn;
}
 }
void deleteatposition(PPNODE head,int pos)
{

  int size=0;
   size=count(*head);
   PNODE temp=NULL;
   PNODE tempdet=NULL; 

 if((pos<1)||(pos>size))     /////////filter////////
   {
     printf("position is invalid\n");
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

   for(int icnt=1;icnt<(pos-1);icnt++)
   {
     temp=temp->next;
   }

tempdet=temp->next;
temp->next=temp->next->next;
free(tempdet);
}
}
//////////////////////////////////////
//date 16/05/2022 t0 17/05/2022
////////////////////////////////////
int main()
{
    int ret=0;
    PNODE first= NULL;

   Insertfirst(&first,101);
   Insertfirst(&first,51); 
   Insertfirst(&first,21); 
   Insertfirst(&first,11);
   
   Insertatposition(&first,131,3);
   Insertatposition(&first,122,4);
   display(first);
   ret=count(first);
   printf("number of node are: %d\n",ret);

   deleteatposition(&first,3);
   deleteatposition(&first,4);

   display(first);
   ret=count(first);
   printf("number of node are: %d\n",ret);

   Insertfirst(&first,1);
   display(first);
   ret=count(first);
   printf("number of node are: %d\n",ret);

   Insertlast(&first,111);
   Insertlast(&first,121);
   display(first);
   ret=count(first);
   printf("number of node are: %d\n",ret);

   deletefirst(&first);
   deletefirst(&first);
   display(first);
   ret=count(first);
   printf("number of node are: %d\n",ret);

   
   deletelast(&first);
   display(first);
   ret=count(first);
   printf("number of node are: %d\n",ret);

  
  return 0;
}

