#include"header131.h"
DublyCLL::DublyCLL()
{
    head=NULL;
    tail=NULL;
    countnode=0;
}

void DublyCLL::insertfirst(int ino)
{
     PNODE newn=NULL;
    newn=new NODE;

    newn->data=ino;
    newn->next=NULL;
    newn->prev=NULL;

    if(countnode==0)// if(head==NULL&& tail==NULL)
    {
       head=newn;
       tail=newn;
    }
    else
    {
      newn->next=head;
      head->prev=newn;
      head=newn;
    }

      head->prev=tail;
      tail->next=head;
    countnode++;
    }

void DublyCLL::insertlast(int ino)
{
    
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=ino;
    newn->next=NULL;
    newn->prev=NULL;

    if(countnode==0)// if(head==NULL&& tail==NULL)
    {
       head=newn;
       tail=newn;
    }
    else
    {
       tail->next=newn;
       newn->prev=tail;
       tail=newn;
    }

     head->prev=tail;
     tail->next=head;
    countnode++;
}

void DublyCLL::insertatpos(int ino,int ipos)
{
    if(ipos<1)||(ipos>countnode+1)
    {
        cout<<"invalid position\n";
        return;
    }
    if(ipos==1)
    {
        insertfirst(ino);
    }
    else if(ipos==countnode+1)
    {
      insertlast(ino);
    }
    else
    {
        
       PNODE newn=NULL;
       newn=new NODE;

       newn->data=ino;
       newn->next=NULL;
       newn->prev=NULL;

       PNODE temp=head;
       
       for(int i=1;i<ipos-1;i++)
       {
           temp=temp->next;
       }

    newn->next=temp->next;
    newn->next->prev=newn;
    temp->next=newn;
    newn->prev=temp;

    }
    
     head->prev=tail;
     tail->next=head;
    countnode++;

}


void DublyCLL::deletefirst()
{
    if(countnode==0)
    {
        return;
    }
    else if(countnode==1)
    {
       delete head;
       head=NULL;
       tail=NULL;
    }
    else
    {
       head=head->next;
       delete tail->next; // delete head->prev
    }
    head->prev=tail;
    tail->next=head;

    countnode--;
}

void DublyCLL::deletelast()
{
    
    if(countnode==0)
    {
        return;
    }
    else if(countnode==1)
    {
       delete head;
       head=NULL;
       tail=NULL;
    }
    else
    {
        tail=tail->prev;
        delete head->next; // delete head->prev;
    }
    head->prev=tail;
    tail->next=head;

    countnode--;
}

void DublyCLL::deleteatpos(int ipos)
{
    int ino=0;
    if(ipos<1)||(ipos>countnode)
    {
        cout<<"invalid position\n";
        return;
    }
    if(ipos==1)
    {
        deletefirst();
    }
    else if(ipos==countnode)
    {
      deletelast();
    }
    else
    {
      
      PNODE newn=NULL;
       newn=new NODE;

      newn->data=ino;
      newn->next=NULL;
      newn->prev=NULL;
   
     PNODE temp=head;
     for(int i=1;i<ipos-1;i++)
    {
       temp=temp->next;
    }
     temp->next=temp->next->next;
     delete temp->next->prev;
     temp->next->prev=temp;

    countnode--;
    } 
     
}


void DublyCLL::display()
{
    int i=0;
    PNODE temp=head;
    for(i=1;i<=countnode;i++)
    {
        cout<<"|"<<head->data<<"|->";
        temp=temp->next;
    }
    cout<<"\n";
}

int DublyCLL::count()
{
    return countnode;
}
