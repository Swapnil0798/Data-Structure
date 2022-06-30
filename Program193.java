import java.lang.*;
import java.util.*;

class node
{
   public int data;
   public node next;
}

class SinglyLL
{
  public node Head;
  public int Count;

  public SinglyLL()
  {
    Head=null;
    Count=0;
  }

  public void Insertfirst(int no)
  {
    node newn=new node();
    newn.data=no;
    newn.next=null;

    if(Head==null)
    {
        Head=newn;

    }
    else
    {
        newn.next=Head;
        Head=newn;
    }
    Count++;
  }
  
  public void Insertlast(int no)
  {
    node newn=new node();
    newn.data=no;
    newn.next=null;

    if(Head==null)
    {
        Head=newn;

    }
    else
    {
        node temp=Head;
        while(temp.next!=null)
        {
            temp=temp.next;
        }
        temp.next=newn;
    }
    Count++;
  }

  public void Display()
  {
    node temp=Head;

    System.out.println("Element of linked list are:");
    while(temp!=null)
    {
        System.out.print("|"+temp.data+"|->");
        temp=temp.next;
    }
    System.out.println("NULL");
  }

  public int countNode()
  {
    return Count;
  }

  public void Deletefirst()
  {
    if(Count==0)
    {
        return;
    }
    else if(Count==1)
    {
        Head=null;
    }
    else
    {
       node temp=Head;
       Head=Head.next;
       temp=null;
    }
    Count--;
  }

  public void Deletelast()
  {
    if(Count==0)
    {
        return;
    }
    else if(Count==1)
    {
        Head=null;
    }
    else
    {
       node temp=Head;
       while(temp.next.next!=null)
       {
        temp=temp.next;
       }
       temp.next=null;
    }
    Count--;
  }

  public void  Insertatpos(int no,int pos)
  {
    if((pos<1)||(pos>Count+1))
    {
      return;
    }
    else if(pos==1)
    {
        Insertlast(no);
    }
    else
    {
        node newn=new node();
        newn.data=no;
        newn.next=null;

        node temp=Head;

        for(int i=1;i<pos-1;i++)
        {
          temp=temp.next;
        }
        newn.next=temp.next;
        temp.next=newn;

        Count++;
    }
  }
  
  public void  Deleteatpos(int pos)
  {
    if((pos<1)||(pos>Count))
    {
      return;
    }
    else if(pos==Count)
    {
        Deletefirst();
    }
    else
    {
        node temp=Head;

        for(int i=1;i<pos-1;i++)
        {
          temp=temp.next;

        }
        temp.next=temp.next.next;
        Count++;
    }
  }
}


class Program193
{
    public static void main(String arg[])
    {
      SinglyLL obj=new SinglyLL();

      obj.Insertfirst(51);
      obj.Insertfirst(21);
      obj.Insertfirst(11);

      obj.Insertlast(101);
      obj.Insertlast(111);
      obj.Insertatpos(55,4);
      obj.Display();

      obj.Deleteatpos(4);
      obj.Display();
  
      obj.Deletefirst();
      obj.Deletelast();

      obj.Display();
      System.out.println("number of count node are: "+obj.countNode());
      

    }
}
/*
  
*/