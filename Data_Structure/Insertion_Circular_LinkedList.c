#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void linkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next; 
    }while (ptr != head);
}

struct node* insertAtFirst(struct node* head, int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head -> next;
    while(p -> next != head)
    {
        p = p -> next;
    }
    
    p -> next = ptr;
    ptr -> next = head;
    head = ptr;
    return head;
}

struct node* insertAtIndex(struct node* head, int data, int index)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node* p = head;
    int i = 0;
    
    while(i != index-1)
    {
        p = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

struct node* insertAtEnd(struct node* head, int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head -> next;
    while(p -> next != head)
    {
        p = p -> next;
    }
    
    p -> next = ptr;
    ptr -> next = head;
    return head;
}

struct node* insertNode(struct node* head, struct node* prevNode, int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
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
    fourth -> next = head;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    //head = insertAtFirst(head, 65);
    //head = insertAtIndex(head, 33, 2);
    //head = insertAtEnd(head, 46);
    head = insertNode(head, second, 57);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}