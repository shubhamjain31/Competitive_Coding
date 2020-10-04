#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(struct node** head, int item)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = item;
    newNode -> next = *head;
    (*head) = newNode;
}

void NodeValue(struct node* head,int n)
{
    int i = 0;
    while(head != NULL && i<n)
    {
        head = head -> next;
        i++;
    }
    printf("%d ",head -> data);
}

void linkedListTraversal(struct node* head)
{
    while(head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
}

int main()
{
    insert(&head, 12);
    insert(&head, 62);
    insert(&head, 71);
    insert(&head, 3);
    insert(&head, 41);
    
    int n = 2;
    
    NodeValue(head, n);
    
    return 0;
}