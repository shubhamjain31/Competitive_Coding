//Remove Duplicates from Sorted Singly Linked List

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

struct node* findNthNode(struct node* ptr, int key)
{
    ptr = head;
    int n = 0;
    struct node* p = head;
    if(ptr == NULL)
    {
        return;
    }
    while(ptr)
    {
        ptr = ptr -> next;
        n++;
    }
    if(n >= key)
    {
        ptr = head;
        for(int i= 0; i<n-key; i++)
        {
            ptr = ptr -> next;
        }
    }
    return ptr;
}


int main()
{
   
    createList(92);
    createList(70);
    createList(70);
    createList(36);
    createList(28);
    createList(28);
    createList(12);
    printf("Linked List is\n");
    linkedListTraversal(head);
    
    struct node* result = findNthNode(head, 4);
    printf("\n\nKth node from the end is %d\n", result -> data);
    return 0;
}