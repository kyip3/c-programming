/*!
\file linklist.c
\author kyip
\par Implementation of linklist
\date 5 Apr 2023
\brief
This file contains the implementation of the following functions for the linklist
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct Node *first = 0;

/**
 * @brief To create a node
 * @param n The value of the data
 * @return Return the new node
 */
struct Node* makeNode(int n)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief To create a linklist
 * @param A An array of int data to create
 * @param n The size of the array
 */
void create(int A[], int n)
{
    struct Node *t = NULL;
    
    if(first != NULL)
    {
        printf("Linklist not created.\nThere is already an exsiting linklist");
        return;
    }
    
    if(A)
    {
        for(int i = 0; i < n; ++i)
        {
            if(i == 0)
            {
                first = makeNode(A[i]);
                t = first;
            }
            else
            {
                t->next = makeNode(A[i]);
                t = t->next;
            }
        }
    }
}
/**
 * @brief To return the size of the linklist (recursive implementation)
 * @param p The first pointer of the array
 * @return return the size of the linklist
 */
int rCount(struct Node *p)
{
    if(p == NULL) //terminating function
        return 0;
    else
        return rCount(p->next) + 1; //count function
}

/**
 * @brief To return the size of the linklist
 * @param p The first pointer of the array
 * @return return the size of the linklist
 */
int count(struct Node *p)
{
    int count = 0;
    while(p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

/**
 * @brief Return the sum of all element data in the linklist
 * @param p The first pointer of the array
 * @return return the sum of all element data
 */
int sum(struct Node *p)
{
    if(p == NULL) //terminating function
        return 0;
    else
        return sum(p->next) + p->data; //sum function
}

/**
 * @brief Find the max data in the linklist (linear)
 * @param p The first pointer of the array
 * @return return the max data
 */
int max(struct Node *p)
{
    int max = INT32_MIN;
    
    while(p)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    
    return max;
}

/**
 * @brief Find the max data in the linklist (recursively)
 * @param p The first pointer of the array
 * @return return the max data
 */
int rMax(struct Node *p)
{
    int x = 0;
    
    if(p == NULL) //terminating function
        return INT32_MIN;

    x = rMax(p->next); // call recursively
    
    if(x > p->data)
        return x;
    else
        return p->data;
    
}

/**
 * @brief To print out all element in the linklist (recursively)
 * @param p The first pointer of the array
 */
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}
/**
 * @brief To search a value in linklist (linear)
 * @param p The first pointer of the array
 * @param key the value to search
 * @return return the address of node if found, else return nul
 */
struct Node* search(struct Node* p, int key)
{
    while(p != NULL)
    {
        if(p->data == key)
            return p;
        else
            p = p->next;
    }
    return NULL; //not found
}
/**
 * @brief To search a value in linklist (recursively)
 * @param p The first pointer of the array
 * @param key the value to search
 * @return return the address of node if found, else return nul
 */
struct Node* rSearch(struct Node* p, int key)
{
    if(p == NULL)
        return 0;
    
    if(key == p->data)
        return p;
    
    return rSearch(p->next, key);
}

/**
 * @brief To add a new node to the front of the linklist
 * @param key the value to search
 */
void addToFront(int key)
{
    struct Node *newNode = makeNode(key);
    newNode->next = first;
    first = newNode;
}

/**
 * @brief To add a new node to the front of the linklist
 * @param key the value to search
 */
void addToEnd(int key)
{
    struct Node *newNode = makeNode(key);
    //tranverse till the end
    struct Node* temp = first;
    
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
/**
 * @brief To free up all the memory for the linklist
 */
void freeLinklist(void)
{
    struct Node* temp;
    while(first)
    {
        temp = first;
        first = first->next;
        free(temp);        
    }
    first = NULL;
}

/**
 * @brief helper function for createSortedList
 * @see void createSortedList(int A[], int n)
 * @param key Element to be inserted into a sorted list
 */
void sortInsert(int key)
{
    struct Node *p = first;
    
    //keep moving next node until it reached the biggest
    while(key > p->data && p->next != NULL)
        p = p->next;
    
    //p is already the biggest at the start, so add new node to the front
    if(p == first)
    {
        addToFront(key);
    }
    //p is the smallest, so add new node to the back
    else if(p->next == NULL)
    {
        p->next = makeNode(key);
    }
    //insert new node in the middle
    else
    {
        struct Node* newNode = makeNode(key);
        newNode->next = p->next;
        p->next = newNode;
    }
}
/**
 * @brief To create a sorted linklist
 * @param A Array if int elements
 * @param n The size of array
 */
void createSortedList(int A[], int n)
{
    if(first != NULL)
    {
        printf("Linklist not created.\nThere is already an exsiting linklist");
        return;
    }
    
    if(A)
    {
        int i = 0;
        while(i < n)
        {
            if(first == NULL)
            {
                first = makeNode(A[i]);
            }
            else
            {
                sortInsert(A[i]);
            }
            
            ++i;
        }

    }
}
