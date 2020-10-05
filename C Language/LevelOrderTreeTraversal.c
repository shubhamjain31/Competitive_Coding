#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> left = NULL;
    ptr -> right = NULL;
    return ptr;
}

struct node** createQueue(int *front, int *rear)
{
    struct node** queue = (struct node**)malloc(MAX*sizeof(struct node*));
    *front = *rear = 0;
    return queue;
}

void enQueue(struct node** queue, int *rear, struct node* newNode)
{
    queue[*rear] = newNode;
    (*rear)++;
}

struct node* deQueue(struct node** queue, int *front)
{
    (*front)++;
    return queue[*front-1];
}

//Display the Dequeue
void levelOrderTree(struct node* root)
{
    int front, rear;
    struct node** queue = createQueue(&front, &rear);
    struct node* temp = root;
    while(temp)
    {
        printf("%d ", temp -> data);
        
        if(temp -> left)
        {
            enQueue(queue, &rear, temp -> left);
        }
        
        if(temp -> right)
        {
            enQueue(queue, &rear, temp -> right);
        }
        
        temp = deQueue(queue, &front); 
    }
}

int main()
{
    struct node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> right -> right = newNode(5);
    
    printf("Level order traversal of binary tree is:\n");
    levelOrderTree(root);
    
    return 0;
}