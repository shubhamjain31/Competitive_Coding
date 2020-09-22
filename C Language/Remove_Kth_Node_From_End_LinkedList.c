//Remove Duplicates from Sorted Singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node *head = NULL;

void linkedListTraversal(struct node* ptr)
{
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

void createList(int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;	
    head = ptr;
}

struct node* removeNthNode(struct node* ptr, int key)
{
    //find the nth node from end
    ptr = head;
    int n = 0;
    if(ptr == NULL)
    {
        return;
    }
    while(ptr)
    {
        ptr = ptr -> next;
        n++;
    }
    if(n >= key)
    {
        ptr = head;
        for(int i= 0; i<n-key; i++)
        {
            ptr = ptr -> next;
        }
    }
    
    //remove the nth node from end
    struct node* p = head;
    struct node* q = head -> next;
    while((q -> data != ptr -> data) && (q -> next != NULL))
    {
        p = p -> next;
        q = q -> next;
    }
    if(q -> data == ptr -> data)
    {
        p -> next = q -> next;
        free(q);
    }
    return head;
}


int main()
{
   
    createList(92);
    createList(70);
    createList(70);
    createList(36);
    createList(28);
    createList(28);
    createList(12);
    printf("Linked List before removal\n");
    linkedListTraversal(head);
    
    printf("\n\nLinked List after removal\n");
    head = removeNthNode(head, 4);
    linkedListTraversal(head);
    return 0;
}