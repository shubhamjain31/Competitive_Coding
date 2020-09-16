#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * prev;
    struct node * next;
};

void linkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    struct node *last;
    //printf("Traversal in forward direction \n");
    while (ptr != NULL) 
    {
        printf("%d ", ptr -> data);
        last = ptr;
        ptr = ptr -> next;
    }
    /*printf("\n");
    printf("Traversal in backward direction \n");
    while (last != NULL) 
    {
        printf("%d ", last -> data);
        last = last -> prev;
    }*/
}

struct node* insertAtFirst(struct node* head, int data)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = 20;
    ptr -> prev = NULL;
    
    ptr -> next = head;
    head -> prev = ptr;
    head = ptr;
    return head;
}

struct node* insertAtEnd(struct node* head, int data)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    struct node* p = head;
    ptr -> data = data;
    ptr -> prev = NULL;
    
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    ptr -> prev = p -> next;
    p -> next = ptr;
    return head;
}

struct node* insertAtIndex(struct node* head, int data, int index)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    struct node* p = head;
    ptr -> data = data;
    ptr -> prev = NULL;
    int i = 0;
    
    while(i != index-1)
    {
        p = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    p -> next -> prev = ptr;
    ptr -> prev = p;
    p -> next = ptr;
    
    return head;
}

struct node* insertNode(struct node* head, struct node* prevNode, int data)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    
    ptr -> prev = prevNode;
    prevNode -> next -> prev = ptr;
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
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

    printf("\nLinked list before insertion\n");
    linkedListTraversal(head);
    //head = insertAtFirst(head, 65);
    //head = insertAtIndex(head, 33, 1);
    //head = insertAtEnd(head, 92);
    head = insertNode(head, second, 57);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}