#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head1 = NULL;
struct node* head2 = NULL;

void insert(struct node** head, int item)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = item;
    newNode -> next = *head;
    (*head) = newNode;
}

int compareLinkedList(struct node* head1, struct node* head2)
{
    int f = 0;
    while(head1 != head2)
    {
        if(head1 -> data != head2 -> data)
        {
            f = 1;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return f;
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
    insert(&head1, 12);
    insert(&head1, 62);
    insert(&head1, 71);
    
    insert(&head2, 12);
    insert(&head2, 62);
    insert(&head2, 7);
    
    int s = compareLinkedList (head1, head2);
    
    if(s > 0)
    {
        printf("Both linked lists are not identical");
    }
    else
    {
        printf("Both linked lists are identical");
    }
    
    return 0;
}