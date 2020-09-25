//Convert a string to a singly linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data;
    struct node * next;
};

struct node *head = NULL;

//Function to print the data present in all the nodes 
void linkedListTraversal(struct node* ptr)
{
    ptr = head;
    while(ptr != NULL)
    {
        printf("%c ", ptr -> data);
        ptr = ptr -> next;
    }
}

//Function to add a new node to the Linked List 
struct node* createNode(char data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;	
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
    printf("Enter a string:");
    scanf("%s",s);
    
    head = stringToLinkedList(head, s);
    printf("Linked List is\n");
    linkedListTraversal(head);
 
    return 0;
}