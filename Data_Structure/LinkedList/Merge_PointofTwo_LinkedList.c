//Solved this by Floyd's Cycle-Finding Algorithm or Fast and Slow Pointer method

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
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

int countNodes(struct node* head)
{
    int cnt = 0;
    while(head != NULL)
    {
        cnt++;
        head = head -> next; 
    }
    return cnt; 
}

struct node* findPointOfMerge4(struct node* h1, struct node* h2)
{ 
    int cnt1 = countNodes(h1);
    int cnt2 = countNodes(h2);
    if(cnt1>cnt2)
    {
        for(int i=0; i<cnt1-cnt2; i++)
        h1 = h1->next; 
    }
    else
    {
        for(int i=0; i<cnt2-cnt1; i++)
        {
            h2 = h2->next;
        } 
    }
    while(h1 != h2)
    {
        h1 = h1->next;
        h2 = h2->next;
    } 
    return h1; 
}

int main()
{
    struct node *p;
    struct node *q;
    
    createList(&head1, 3);
    p = head1;
    createList(&head1, 4);
    createList(&head1, 6);
    createList(&head1, 7);
    createList(&head1, 8);
    createList(&head1, 9);
    printf("Linked List 1 is\n");
    linkedListTraversal(head1);
    
    printf("\n");
    
    createList(&head2, 5);
    q = head2;
    createList(&head2, 7);
    createList(&head2, 8);
    createList(&head2, 2);
    createList(&head2, 1);
    createList(&head2, 10);
    
    printf("\n");
    q -> next = p;
    
    printf("Linked List 2 is\n");
    linkedListTraversal(head2);
    
    printf("\n\nNumber of nodes: %d",countNodes(head1));
    
    struct node* result = findPointOfMerge4(head1, head2);
    if(result != NULL)
    {
        printf("\n\nMerge Point: %d",result -> data); 
    }
    else
    {
        printf("\n\nNot Merging");
    }
    //linkedListTraversal(head);
    return 0;
}