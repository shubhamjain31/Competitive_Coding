#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

void linkedListTraversal(struct node* ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
   
    //Allocate memory for nodes in linked list in Heap
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    
    //Link head and first nodes
    head -> data = 42;
    head -> next = first;
    
    //Link first and second nodes
    first -> data = 68;
    first -> next = second;
    
    //Link second and third nodes
    second -> data = 18;
    second -> next = third;
    
    //Terminate the list at the third node
    third -> data = 2;
    third -> next = NULL;
    
    linkedListTraversal(head);
    return 0;
}