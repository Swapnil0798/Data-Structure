using namespace std;
#include<iostream>
struct node
{
    int data;
    struct node*next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class singlyCLL
{
    private:   //characteristics
   
    PNODE Head;
    PNODE Tail;

   public:  //Behaviours
    
     singlyCLL();
     void insertfirst(int no);
     void insertlast(int no);
     void insertatpos(int no,int pos);
     void deletefirst();
     void deletelast();
     void deleteatpos(int pos);
     void display();
     int count();
};

    
    singlyCLL::singlyCLL()
    {
        Head=NULL;
        Tail=NULL;
    }
   

    void singlyCLL::insertfirst(int no)
    {
      PNODE newn = NULL;

      newn=new NODE;

      newn->data=no;
      newn->next=NULL;
      if((Head==NULL)&&(Tail==NULL))  //IF ll is empty
      {
        Head=newn;
        Tail=newn;
      }
      else // if ll contain atleast one node
      {
        newn->next=Head;
        Head=newn;
      }
      Tail->next=Head;
    }

    void singlyCLL:: insertlast(int no)
    {
     
      PNODE newn = NULL;

      newn=new NODE;

      newn->data=no;
      newn->next=NULL;
      if((Head==NULL)&&(Tail==NULL))  //IF ll is empty
      {
        Head=newn;
        Tail=newn;
      }
      else // if ll contain atleast one node
      {
        Tail->next=newn;
        Tail=newn;
      }
      Tail->next=Head;
    }

    void singlyCLL::insertatpos(int no,int pos)
    {
        int isize=count();
        if((pos<1)||(pos>isize+1))
        {
           cout<<"invalid position";

            return;
        }
        if(pos==1)
        {
            insertfirst(no);
        }
        else if((pos==isize+1))
        {
            insertlast(no);
        }
        else
        {
          PNODE newn = NULL;

          newn=new NODE;

          newn->data=no;
          newn->next=NULL;
     
           PNODE temp=Head;
           int icnt=0;
           for(icnt=1;icnt<pos-1;icnt++) 
           {
               temp=temp->next;
           }
           newn->next=temp->next;
           temp->next=newn;
        }

    }

    void singlyCLL::deletefirst()
    {
        if((Head==NULL)&&(Tail==NULL)) //ll is empty
        {
            return;
        }
        else if(Head==Tail)// ll contain  1 node
        {
            delete Head;
            Head=NULL;
            Tail=NULL;
           
        }

        else // ll contain more than 1 node
        {
          Head=Head->next;
          delete Tail->next;
        }

      Tail->next=Head;

    }

    void singlyCLL::deletelast()
    {
        if((Head==NULL)&&(Tail==NULL)) //ll is empty
        {
            return;
        }

        else if(Head==Tail)// ll contain  1 node
        {
            delete Head;
            Head=NULL;
            Tail=NULL;
         }

        else
        {
            PNODE temp=Head;
            while(temp->next!=Tail)
            {
                temp=temp->next;

            }
            delete Tail;
            Tail=temp;
        }
       Tail->next=Head;
    }

    void singlyCLL::deleteatpos(int pos)
    {
        int isize=count();
        if((pos<1)||(pos>isize+1))
        {
           cout<<"invalid position";

            return;
        }
        if(pos==1)
        {
            deletefirst();
        }
        else if((pos==isize))
        {
            deletelast();
        }
        else
        {
           PNODE temp1=Head;
           int icnt=0;
           for(icnt=1;icnt<pos-1;icnt++) 
           {
               temp1=temp1->next;
           }
           PNODE temp2=temp1->next;
           temp1->next=temp2->next;
           delete temp2;
        }

    }

    void singlyCLL::display()
    {
      PNODE temp=Head;
      if((Head==NULL)&&(Tail==NULL))// ll is empty//filter
      {
          return;
      }
      do
      {
          cout<<"|"<<temp->data<<"|->";
          temp=temp->next;
      }while(temp!=Head);
      cout<<"NULL";
      cout<<endl;  
    }

    int singlyCLL::count()
    {
      int icnt=0;
      PNODE temp=Head;

      if((Head==NULL)&&(Tail==NULL))
      {
          return 0;
      }
      do
      {
       icnt++;
       temp=temp->next; 
      } while (temp!=Head);
       
        return icnt;
    }

int main()
{
    int iret=0;
  singlyCLL obj;
  obj.insertfirst(51);
   obj.insertfirst(21);
    obj.insertfirst(11);
    obj.insertfirst(1001);
    obj.insertfirst(1111);
     obj.insertlast(101);
     obj.insertlast(141);
     obj.insertlast(131);
      obj.insertlast(111);

obj.display();
obj.count();
iret=obj.count();
cout<<"number of nodes are:"<<iret<<endl;

obj.deletefirst();
obj.deletelast();
obj.insertatpos(75,4);
obj.deleteatpos(4);


obj.display();
obj.count();
iret=obj.count();
cout<<"number of nodes are:"<<iret<<endl;
 
   return 0;
}