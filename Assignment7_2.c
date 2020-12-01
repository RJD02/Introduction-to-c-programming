/*
 * You are given a sequence of integers terminated with a -1. The -1 is
 * not part of the input sequence.
 *
 *
 * Next, you are given a positive number N.
 *
 * You have to create a linked list with the input sequence of integers
 * as entries. You can use the following structure.
 *
 * struct node{
 *      int data;
 *      struct node *next;
 * };
 *
 *
 * Now, you have to delete all but the last N elements from the linked
 * list, and print the resulting list. (i.e. The resulting list will
 * consist of only the last N elements from the list.)
 *
 *
 * If N is longer than the length of the linked list, you must print -1.
 *
 * While printing, the entries of the list must be separated by a single
 * space.
 *
 * Sample Input
 * ------------
 * 3 4 5 6 -1
 * 1
 *
 * Sample Output
 * -------------
 * 6
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int         data;
   struct Node *next;
};

typedef struct Node Node;

struct List
{
   Node *head;
   Node *tail;
};

typedef struct List List;

void init(List *a)
{
   a->head = NULL;
   a->tail = NULL;
}


int isEmpty(List *a)
{
   return(a->head == NULL);
}


void addNode(List *a, int n)
{
   Node *temp;

   temp       = (Node *)malloc(sizeof(Node));
   temp->data = n;
   temp->next = NULL;
   if (isEmpty(a))
   {
      a->head = temp;
      a->tail = temp;
   }
   else
   {
      a->tail->next = temp;
      a->tail       = a->tail->next;
   }
}


int length(List a)
{
   if (isEmpty(&a))
   {
      return 0;
   }
   int  count = 0;
   Node *temp;
   temp = (Node *)malloc(sizeof(Node));
   temp = a.head;
   while (temp != NULL)
   {
      count++;
      temp = temp->next;
   }
   return count;
}


void display(List a)
{
   if (isEmpty(&a))
   {
      return;
   }
   Node *temp;
   temp = (Node *)malloc(sizeof(Node));
   temp = a.head;
   while (temp != NULL)
   {
      printf("%d ", temp->data);
      temp = temp->next;
   }
}


void deleteFirst(List *a, int n)
{
   int len = length(*a);

   if (isEmpty(a))
   {
      return;
   }
   if (n > len)
   {
      printf("-1");
      a->head = NULL;
      return;
   }
   int  count = 0;
   Node *temp;
   temp = (Node *)malloc(sizeof(Node));
   temp = a->head;
   len  = len - n;
   while (count < len)
   {
      temp = temp->next;
      count++;
   }
   a->head = temp;
}


int main()
{
   List a;

   init(&a);
   int now;
   scanf("%d", &now);
   if (now == -1)
   {
      printf("-1");
      return 0;
   }
   while (now != -1)
   {
      addNode(&a, now);
      scanf("%d", &now);
   }
   int d;
   scanf("%d", &d);
   deleteFirst(&a, d);
   display(a);
   return 0;
}
