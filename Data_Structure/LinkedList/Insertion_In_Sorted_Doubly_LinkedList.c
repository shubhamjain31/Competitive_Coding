//Insertion of a node to a sorted doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node *head = NULL;

void linkedListTraversal(struct node* ptr)
{
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

void createList(int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;	
    head = ptr;
}

void sortedNodeLinkedList(struct node** p, int item)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if((*p) == NULL || (*p) -> data >= item)
    {
        ptr -> data = item;
        ptr -> next = *p;
        ptr -> prev = NULL;
        (*p) -> prev = ptr;
        (*p) = ptr;
        return;
    }
    printf("%d ", (*p) -> data);
    struct node* q = *p;
    while((q -> next != NULL) && (q -> next -> data < item))
    {    
        q = q -> next;   
    }
    ptr -> data = item;
    if(q -> next != NULL)
    {
       q -> next -> prev = ptr;
    }
    ptr -> next = q -> next;
    ptr -> prev = q;
    q -> next = ptr;
}


int main()
{
   
    createList(92);
    createList(70);
    createList(36);
    createList(28);
    createList(12);
    printf("Linked List is\n");
    linkedListTraversal(head);
    
    sortedNodeLinkedList(&head, 1);
    sortedNodeLinkedList(&head, 356);
    sortedNodeLinkedList(&head, 23);
    printf("\n\nNew Linked List is\n");
    linkedListTraversal(head);
    return 0;
}