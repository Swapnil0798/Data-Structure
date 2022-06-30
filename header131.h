#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DublyCLL
{
  private:
           PNODE head;
           PNODE tail;
           int countnode;
  public:
          DublyCLL();
          void insertfirst(int);
          void insertlast(int);
          void insertatpos(int,int);
          void deletefirst();
          void deletelast();
          void deleteatpos(int);

          int count();
          void display();
};