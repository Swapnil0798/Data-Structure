#include<stdio.h>
#include<stdlib.h>

 struct node
   {
       int data;
       struct node*next;
   };//structure declaration
   typedef struct node NODE;

int main()
{
     NODE obj;//static memory allocation
     NODE*ptr=(NODE*)malloc(sizeof(NODE));
    //dynamic memory allocation
    obj.data=11;//direct acces
    ptr.next=NULL;

    obj->data=11;//indirect accesing operator
    ptr->next=NULL;



    return 0;
}