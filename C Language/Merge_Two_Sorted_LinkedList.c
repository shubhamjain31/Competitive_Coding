//Remove Duplicates from Sorted Singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void linkedListTraversal(struct node* head)
{
    while(head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
}

void createList(struct node** head, int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = *head;	
    (*head) = ptr;
}

struct node * MergeLinkedList(struct node* h1, struct node* h2)
{
    struct node *dummy = (struct node*)malloc(sizeof(struct node));
    struct node *tail = dummy;
    while(1)
    {
        if(h1 == NULL)
        {
            tail -> next = h2;
            break;
        }
        else if(h2 == NULL)
        {
            tail -> next = h1;
            break;
        }
        if(h1 -> data <= h2 -> data)
        {
				        tail -> next = h1;
				        h1 = h1 -> next;
        }
				    else
        {
				        tail -> next = h2;
				        h2 = h2 -> next;
        }
				tail = tail -> next;
    }
    return dummy -> next;
}


int main()
{
   
    createList(&head1, 33);
    createList(&head1, 27);
    createList(&head1, 20);
    createList(&head1, 14);
    createList(&head1, 8);
    createList(&head1, 3);
    printf("Linked List 1 is\n");
    linkedListTraversal(head1);
    
    printf("\n\n");
    
    createList(&head2, 37);
    createList(&head2, 29);
    createList(&head2, 22);
    createList(&head2, 18);
    createList(&head2, 10);
    createList(&head2, 5);
    
    printf("Linked List 2 is\n");
    linkedListTraversal(head2);
    struct node * head = MergeLinkedList(head1, head2);
    printf("\n\nMerged Linked List is\n");
    linkedListTraversal(head);
    return 0;
}