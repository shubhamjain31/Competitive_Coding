#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next; 
    }
}

struct node* deleteAtFirst(struct node* head)
{
    struct node* p = head;
    head = head -> next;
    free(p);
    return head;
}

struct node* deleteAtIndex(struct node* head, int index)
{
    struct node* p = head;
    struct node* q = head -> next;
    int i = 0;
    while(i < index-1)
    {
        p = p -> next;
        q = q -> next;
        i++;
    }
    p -> next = q -> next;
    free(q);
    return head;
}

struct node* deleteAtEnd(struct node* head)
{
    struct node* p = head;
    struct node* q = head -> next;
    while(q -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }
    p -> next = NULL;
    free(q);
    return head;
}

struct node* deleteNode(struct node* head, int val)
{
    struct node* p = head;
    struct node* q = head -> next;
    while(q -> data != val && q -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }
    if(q -> data == val)
    {
        p -> next = q -> next;
        free(q);
    }
    return head;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head -> data = 7;
    head -> next = second;

    // Link second and third nodes
    second -> data = 11;
    second -> next = third;

    // Link third and fourth nodes
    third -> data = 41;
    third -> next = fourth;

    // Terminate the list at the third node
    fourth -> data = 66;
    fourth -> next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    //head = deleteAtFirst(head);
    //head = deleteAtIndex(head, 2);
    //head = deleteAtEnd(head);
    head = deleteNode(head, 66);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}