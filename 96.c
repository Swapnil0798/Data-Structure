#include<stdio.h>
#include<stdlib.h>


int main()
{
 struct node
   {
       int data;
       struct node*next;
   };//structure declaration

    struct node obj;//static memory allocation
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    //dynamic memory allocation
    obj.data=11;//direct acces
    ptr.next=NULL;

    obj->data=11;//indirect accesing operator
    ptr->next=NULL;



    return 0;
}