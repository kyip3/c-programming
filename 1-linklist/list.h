/*!
\file list.c
\author kyip
\par Implementation of linklist
\date 5 Apr 2023
\brief
This file contains the interface of the following functions for the linklist
*/

#ifndef LIST_H
#define LIST_H

/**
 * @brief struct Node to store int data and a pointer next
 */
struct Node
{
    int data;
    struct Node *next;
};

//simply declare a variable without assigning memory.
//extern indicates that this variable is delcared in somewhere else (.c)
//if not will have linker error
extern struct Node *first;

//to create a node with value
struct Node* makeNode(int n);

//To create a linklist
void create(int A[], int n);

//Return the size of linklist (linear and recursive implementation examples)
int rCount(struct Node *p);
int count(struct Node *p);

//Return sum of all elements
int sum(struct Node *p);

//Return the max element in the list (linear and recursive implementation examples)
int max(struct Node *p);
int rMax(struct Node *p);

//To print the linklist
void display(struct Node *p);

//To search for a value in a linklist (linear and recursive implementation examples)
struct Node* search(struct Node* p, int key);
struct Node* rSearch(struct Node* p, int key);

//To insert a node in the list at Front
void addToFront(int key);

//To insert a node in the list at End
void addToEnd(int key);

void freeLinklist(void);

#endif /* linklist_h */
