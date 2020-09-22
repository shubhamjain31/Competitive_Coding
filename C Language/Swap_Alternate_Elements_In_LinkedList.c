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

void SwapAlternateElement(struct node* ptr)
{
    
    ptr = head;
    int x;
    if(ptr == NULL)
    {
        return;
    }
    while(ptr != NULL && ptr -> next != NULL)
    {
        x = ptr -> data;
        ptr -> data = ptr -> next -> data;
        ptr -> next -> data = x;
        ptr = ptr -> next -> next;
    }
}


int main()
{
   
    createList(19);
    createList(70);
    createList(43);
    createList(6);
    createList(28);
    createList(8);
    createList(1);
    printf("Linked List before swapping\n");
    linkedListTraversal(head);
    
    SwapAlternateElement(head);
    printf("\n\nLinked List after swapping\n");
    linkedListTraversal(head);
    return 0;
}