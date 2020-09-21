//Solved this by Floyd's Cycle-Finding Algorithm or Fast and Slow Pointer method

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
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

void detectLoopInLinkedList(struct node* p)
{
    struct node* fast;
    struct node* slow;
    fast = p;
    slow = p;
    while(slow && fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
        {
            printf("\n\nLinked list contains a loop\n");
            RemoveLoopInLinkedList(slow, p);
            return;
        }
    }
    printf("\n\nNo loop in linked list\n");
}

//loopNode value come from above function
void RemoveLoopInLinkedList(struct node* loopNode, struct node* ptr)
{
    struct node* p;
    struct node* q;
    p = loopNode;
    q = loopNode;
    int loopLen = 1;
    
    while(p -> next != q)
    {
        p = p -> next;
        loopLen++;
    }
    printf("\nNumber of loops contains is %d\n",loopLen);
    
    p = head;
    q = head;
    for(int i = 0; i<loopLen; i++)
    {
        q = q -> next;
    }
    while(q -> next != p -> next)
    {
        p = p -> next;
        q = q -> next;
    }
    q -> next = NULL;
}

int main()
{
   
    createList(92);
    createList(30);
    createList(36);
    createList(2);
    createList(12);
    printf("Linked List is\n");
    linkedListTraversal(head);
    
    //Create loop in linked list . Set next pointer of last node to second node from head.
    head->next->next->next->next->next = head -> next;
    
    detectLoopInLinkedList(head);
    
    printf("\nLinked List after removing loop \n"); 
    linkedListTraversal(head);
    return 0;
}