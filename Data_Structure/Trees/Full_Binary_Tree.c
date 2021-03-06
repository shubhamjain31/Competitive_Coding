#include<stdio.h>
#include<stdbool.h>

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

//Check if the tree is full
bool isFullBinaryTree(struct node* root)
{
    if(root == NULL)
    {
        return true;
    }
    if(root -> left == NULL && root -> right == NULL)
    {
        return true;
    }
    if((root -> left) && (root -> right))
    {
        return(isFullBinaryTree(root -> left) && isFullBinaryTree(root -> right));
    }
    return false;
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
    
    if(isFullBinaryTree(root))
    {
        printf("It is a Full Binary Tree");
    }
    else
    {
        printf("It is not a Full Binary Tree");
    }
    
    return 0;
}