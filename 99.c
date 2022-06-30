//singly linked list
/*
insertfirst
isertlast
insertatposition

deletefirst
deletelast
deleteatposition

display
count
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    
    struct node*next;
};
/*
1: allocate memory for node
2:initialise the node
3:check whether ll is enpty or not
4: if ll is empty the node is the first
5:if ll contain atleasr one node in it then store the address of preous node in the next pointer of new node

*/
typedef struct node NODE;
typedef struct node*PNODE;
typedef struct node**PPNODE;
///////////////DATE : 11/05/2022 ///////////////////////////
void insertfirst(PPNODE Head,int ino)
{
    PNODE newn=NULL;
    newn=((PNODE)malloc(sizeof(NODE)));
    newn->data=ino;
    newn->next=NULL;
    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        newn->next=*Head;
        *Head=newn;
    }

}
int main()
{
    PNODE first =NULL;//struct node * first=NULL;
     
    insertfirst(&first,101);
    insertfirst(&first,51);
    insertfirst(&first,21);
    insertfirst(&first,11);
    return 0;
}
/*
rules:
1 : use only dynaic allocation
2 : dont write ant technical syntax
3 : dont use any global variable
4 :be careful while manupulating the first pointer
5 :pass the first pointer directely if the function is not going to modify the ll(display,count)
5 :pass the address of first pointer directely if the function is not going to modify the ll(inserfirst,insertlast,insrtadpos,deletefirst,deletelast.,deletepos)

*/