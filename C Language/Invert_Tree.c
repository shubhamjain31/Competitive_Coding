#include<stdio.h>
#include<stdlib.h>

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

void preOrder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}

struct node* invert(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    struct node* temp = root;
    invert(root -> left);
    invert(root -> right);
    
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
}

int main()
{
    struct node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> right -> right = newNode(5);
    
    printf("Before invert tree is:\n");
    preOrder(root);
    
    printf("\n\nAfter invert tree is:\n");
    invert(root);
    preOrder(root);
    
    return 0;
}