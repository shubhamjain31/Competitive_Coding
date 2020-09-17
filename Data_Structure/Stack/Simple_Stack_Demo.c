#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node *head = NULL;

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next; 
    } 
}

struct node * insertAtEnd(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;

    while(p -> next!=NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

void insert(int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    if(head == NULL){
        head = ptr;
        head->next = NULL;  
        return;
    }
    head = insertAtEnd(head, data);
    
}

int main(){
    
    insert(8);
    insert(2);
    insert(6);
    insert(4);
    linkedListTraversal(head);
    
    return 0;
}