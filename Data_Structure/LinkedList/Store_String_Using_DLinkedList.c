//Convert a string to a doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node * prev;
    struct node * next;
};

struct node *head = NULL;

//Function to print the data present in all the nodes 
void linkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    struct node *last;
    while (ptr != NULL) 
    {
        printf("%c ", ptr -> data);
        last = ptr;
        ptr = ptr -> next;
    }
}

//Function to add a new node to the Linked List 
struct node* createNode(char data)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    struct node* p = head;
    ptr -> data = data; 
    ptr -> next = NULL; 
    if(head == NULL)
    {
        ptr -> prev = NULL;
    }
    else
    {
        while(p -> next != NULL)
        {
            p = p -> next; 
        } 
    ptr -> prev = p; 
    p -> next = ptr;
    }
    return ptr;
}

//Function to convert the string to the Linked List
struct node* stringToLinkedList(struct node* ptr, char s[])
{
    struct node* curr;
    ptr = createNode(s[0]);
    curr = ptr;
    for(int i=1; i<strlen(s);i++)
    {
        curr -> next = createNode(s[i]);
        curr = curr -> next;
    }
    
    return ptr;
}

int main()
{
    char s[30];
    printf("Enter a string:\n");
    scanf("%s",s);
    
    head = stringToLinkedList(head, s);
    printf("\nLinked List is\n");
    linkedListTraversal(head);

    return 0;
}