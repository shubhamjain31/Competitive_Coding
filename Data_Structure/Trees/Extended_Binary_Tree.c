#include<stdio.h>
#define bool int

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//Creating a new node
struct node* createNode(int item)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = item;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

//Function for inorder traversal
void traverse(struct node* root)
{
    if(root != NULL)
    {
        traverse (root -> left);
        printf("%d ", root -> data);
        traverse (root -> right);
    }
    else
    {
        //Making external nodes 
        root = createNode(-1);
        printf("%d ", root -> data);
    }
}

//Insert data in left child node
struct node* insertLeft(struct node* root, int item)
{
    root -> left = createNode(item);
    return root -> left;
}


//Insert data in right child node
struct node* insertRight(struct node* root, int item)
{
    root -> right = createNode(item);
    return root -> right;
}

int main()
{
    struct node* root = createNode(2);
    insertLeft(root, 5);
    insertRight(root, 7);
    insertLeft(root -> left, 8);
    insertRight(root -> left, 82);
    insertLeft(root -> right, 10);
    
    traverse(root);
    return 0;
}