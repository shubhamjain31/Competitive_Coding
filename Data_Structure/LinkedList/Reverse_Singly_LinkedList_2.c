//Reverse a linked list without actually reversing

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};


void linkedListTraversal(struct node* ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

void reverseLinkedList(struct node* ptr)
{
    if(ptr == NULL)
    {
        return;
    }   
    reverseLinkedList(ptr -> next);
    printf("%d ", ptr->data);
}


int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    
    // Allocate memory for nodes in the linked list in Heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    
    // Link first and second nodes
    head -> data = 37;
    head -> next = second;
    
    second -> data = 62;
    second -> next = third;
    
    third -> data = 26;
    third -> next = fourth;
    
    fourth -> data = 93;
    fourth -> next = NULL;
    
    printf("List before reversing\n");
    linkedListTraversal(head);
    
    printf("\n\nList after reversing\n");
    reverseLinkedList(head);
    return 0;
}