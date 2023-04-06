
#include "list.h"
#include <stdio.h>


void testSimpleLinklist(void)
{
    printf("A linklist implementation in C\n");
    
    int A[5] = {1,2,13,4,5};
    
    create(A,5);
    
    display(first);
    
    int size = rCount(first);
    
    printf("\nSize of the list is %d \n",size);
    
    printf("\nSum of all list is %d \n",sum(first));

    printf("\nMax number in the list is %d \n",max(first));
    
    struct Node *p = search(first,13);
    if(p)
        printf("\nSearching a element %d \n",p->data);
    else
        printf("\nUnable to searching a element %d \n",13);
    
    
    addToFront(0);
    printf("\nInsert node at the front of the list\n");
    display(first);
    
    
    addToEnd(200);
    printf("\nInsert node at end of the list\n");
    display(first);
    
    freeLinklist();
}

void testSortedLinkList(void)
{
    int A[] = {44,22,11,55,33};
    createSortedList(A, 5);
    display(first);
    freeLinklist();
}
int main(int argc, const char * argv[])
{
    testSimpleLinklist();
    
    testSortedLinkList();

    
    return 0;
}
