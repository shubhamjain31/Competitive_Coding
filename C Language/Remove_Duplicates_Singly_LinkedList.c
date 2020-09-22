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

void removeDuplicates(struct node* ptr)
{
    ptr = head;
    struct node* temp;
    if(ptr == NULL)
    {
        return;
    }
    while(ptr -> next != NULL)
    {
        if(ptr -> data == ptr -> next -> data)
        {
            temp = ptr -> next -> next;
            free(ptr -> next);
            ptr -> next = temp;
        }
        else
        {
            ptr = ptr -> next;
        }
    }
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
    printf("Linked List before duplicate removal\n");
    linkedListTraversal(head);
    
    removeDuplicates(head);
    printf("\n\nLinked List after duplicate removal\n");
    linkedListTraversal(head);
    return 0;
}