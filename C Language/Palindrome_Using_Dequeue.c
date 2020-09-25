//Convert a string to a doubly linked list
//It is not working properly !!

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

void checkPalindrome(struct node* ptr)
{
    struct node* p = ptr->next;
    int n = 1;
    struct node* q = ptr;
    while(q -> next != NULL)
    {
        q = q -> next;
        n += 1;
    }
    
    //checking dequeue is palindrome or not
    for(int i=0; i<(n/2); i++)
    {
        if(p -> data == q -> data)
        {
            p = p -> next;
            q = q -> prev;
            break;
        }
        else
        {
            printf("\n\nString is not palindrome");
            break;
        }
        printf("\n\nString is palindrome");
    }
}


int main()
{
    char s[30];
    printf("Enter a string:\n");
    scanf("%s",s);
    
    head = stringToLinkedList(head, s);
    printf("\nLinked List is\n");
    linkedListTraversal(head);
    
    checkPalindrome(head);
    return 0;
}