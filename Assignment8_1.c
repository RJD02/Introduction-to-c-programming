/*
 *
 * In this question, you have to write code to remove the first node in a doubly linked list containing a specified number. The code to create the linked list is already given. The main() function calls a function removeData(head,tail,n) to remove the first node containing n from the linked list.

Complete the code by writing the missing function. You can also write additional functions which you may need.

Input Format
You will be given a positive number N in the first line.

This will be followed by a line containing N integers.

This will be followed by an integer M.

Output format
The output will be the list after deleting M. Note that you do not have to add any additional code to print the list - once you code the removeData() function, the code will print the contents of the remaining list.


#include <stdio.h>

#include <stdlib.h>



struct DoublyLinkedList{

	int data;

	struct DoublyLinkedList *prev;

	struct DoublyLinkedList *next;

};



/*

 --------------------------

  Create a new node

 --------------------------


struct DoublyLinkedList *createNode(int n)

{

	struct DoublyLinkedList *newNodeptr;

	newNodeptr = (struct DoublyLinkedList*)

		malloc (sizeof(struct DoublyLinkedList));

	newNodeptr->data = n;

	newNodeptr->prev = NULL;

	newNodeptr->next = NULL;

	return newNodeptr;

}



/*

 --------------------------------

 add a node at the end of a doubly linked list.

 Tailptr is the address of the pointer to the end of the current list.

 After adding the node, tail points to the new node inserted.

 --------------------------------


void appendNode ( struct DoublyLinkedList **tailptr, int n )

{

	struct DoublyLinkedList *newNode;

	newNode = createNode ( n );

	newNode->prev=*tailptr;



	(*tailptr)->next = newNode;



	*tailptr=newNode;

}



void initializeList (

	struct DoublyLinkedList **headptr,

	struct DoublyLinkedList **tailptr,

	int n)

{

	struct DoublyLinkedList *newNode;

	newNode=createNode(n);

	*headptr=newNode;

	*tailptr=newNode;

	return;

}



void printList(

	struct DoublyLinkedList *head,

	struct DoublyLinkedList *tail)

{

	struct DoublyLinkedList *curr=head;



	while ( curr != NULL ){

                if(curr->next!=NULL)

		printf("%d,",curr->data);

                else printf("%d",curr->data); 

		curr = curr->next;

	}



	return;

}



/*

 --------------------------------

 remove the node that ptr points to.

 After removing the first node, we should reset head.

 After removing the last node, we should reset tail.

 --------------------------------


int main()

{

	int n;

	int i=0;

	int m;

	struct DoublyLinkedList *head, *tail;



	scanf("%d",&n);



	if ( n <= 0 ){

		return 0;

	}



	scanf("%d",&m);

	initializeList(&head,&tail,m);





	for(i=1;i<n;i++){ /* read the remaining elements 

		scanf("%d",&m);

		appendNode(&tail,m);

	}

  	scanf("%d",&n);

	removeData ( &head, &tail, n );

	printList(head,tail);

	return 0;

}
*/

#include<stdio.h>
#include <stdlib.h>

#define sf(n) scanf("%d", &n)
#define pf(n) printf("%d,",(int)n)
#define mew printf("\n")

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

typedef struct Node Node;

struct List {
	Node* head;
	Node* tail;
};

typedef struct List List;

void init(List *a) {
	a -> head = a -> tail = NULL;
}

int isEmpty(List a) {
	return (a.head == NULL);
}

void append(List *a, int n) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp -> data = n;
	if(isEmpty(*a)) {
		a -> head = temp;
		a -> tail = temp;
		return ;
	}
	a -> tail -> next = temp;
	a -> tail = a -> tail -> next;
	a -> tail -> next = NULL;
}

void printList(List a) {
	if(isEmpty(a)) {
		pf(0);
	}
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = a.head;
	while(temp != NULL) {
		if(temp -> next != NULL)
			pf(temp -> data);
		if(temp -> next == NULL)
			printf("%d", temp -> data);
		temp = temp -> next;
	}
}

void deleteNode(List *a, int n) {
	if(isEmpty(*a)) return ;
	if(a -> head -> data == n) {
		a -> head = a -> head -> next;
		return ;
	}
	// if(a -> tail -> data == n) {
	// 	a -> tail = a -> tail -> prev;
	// 	a -> tail -> next = NULL;
	// 	return ;
	// }
	Node* temp = (Node*)malloc(sizeof(Node));
	Node* prev = (Node*)malloc(sizeof(Node));
	temp = a -> head;
	while(temp != NULL && temp -> data != n) {
		prev = temp;
		temp = temp -> next;
	}
	if(temp == NULL) return;
	prev -> next = temp -> next;
}

void pop(List *a) {
	if(isEmpty(*a)) {
		return ;
	}
	a -> tail = a -> tail -> prev;
	a -> tail -> next = NULL;
}

void push(List *a, int n) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp -> data = n;
	if(isEmpty(*a)) {
		a -> head = temp;
		a -> tail = temp;
		return ;
	}
	a -> tail -> next = temp;
	a -> tail = a -> tail -> next;
	a -> tail -> next = NULL;

}

int length(List a) {
	if(isEmpty(a)) return 0;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = a.head;
	int count = 0;
	while(temp != NULL) {
		count++;
		temp = temp -> next;
	}
	return count;
}

int main() {
	List a;
	init(&a);
	int n;
	sf(n);
	for(int i = 0; i < n;i++) {
		int m;
		sf(m);
		push(&a, m);
	}
	int key;
	sf(key);
	deleteNode(&a, key);
	printList(a);
	return 0;
}
