#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

void linkedListTraversal(struct node* ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

void reverseLinkedList(struct node** ptr)
{
    struct node* p = *ptr;
    struct node* q = NULL;
    while(p != NULL)
    {
        q = p -> prev;
        p -> prev = p -> next;
        p -> next = q;
        p = p -> prev;
    }
    if(q != NULL)
    {
        *ptr = q -> prev;
    }
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
    head -> prev = NULL;
    head -> data = 7;
    head -> next = second;

    // Link second and third nodes
    second -> prev = head;
    second -> data = 11;
    second -> next = third;

    // Link third and fourth nodes
    third -> prev = second;
    third -> data = 41;
    third -> next = fourth;

    // Terminate the list at the third node
    fourth-> prev = third;
    fourth -> data = 66;
    fourth -> next = NULL;
    
    printf("Linked List before reversing\n");
    linkedListTraversal(head);
    
    reverseLinkedList(&head);
    printf("\n\nLinked List after reversing\n");
    linkedListTraversal(head);
    return 0;
}