#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node *head = NULL;

void traverseData()
{
    struct node* ptr;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

//New node will insert before the next node
void insertData(int data)
{
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
    {
         ptr -> data = data;
         ptr -> next = NULL;
         ptr -> prev = NULL;
         head = ptr;
    }
    else
    {
         ptr -> data = data;
         ptr -> prev = NULL;
         ptr -> next = head;
         head -> prev = ptr;
         head = ptr;
     }
}

void userDefinedData()
{
    int data, noOfNode;
    printf("\nEnter the number of nodes:\n");
    scanf("%d",&noOfNode);
    printf("\nEnter the item:\n");
    for(int i=0; i<noOfNode; i++)
    {
        scanf("%d",&data);
        insertData(data);
    }
}

int main()
{
    userDefinedData();
    printf("Linked List is\n");
    traverseData();
    
    return 0;
}