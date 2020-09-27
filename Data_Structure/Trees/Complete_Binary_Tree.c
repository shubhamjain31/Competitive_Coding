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

//Count the number of nodes 
int countNumNodes(struct node *root) 
{ 
    if(root == NULL) 
    {
        return (0);
    } 
    return(1 + countNumNodes(root->left) + countNumNodes(root->right));
 }

//Check if the tree is complete
bool isCompleteBinaryTree(struct node* root, int index, int countNumNodes)
{
    if(root == NULL)
    {
        return true;
    }
    if(index >= countNumNodes)
    {
        return false;
    }
    return(isCompleteBinaryTree(root -> left, 2*index+1, countNumNodes) && isCompleteBinaryTree(root -> right, 2*index+2, countNumNodes));
}

struct node* insertLeft(struct node* root, int item)
{
    root -> left = createNode(item);
    return root -> left;
}

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
    insertRight(root -> right, 29);
    
    int newCount = countNumNodes(root);
    int index = 0;
    
    if(isCompleteBinaryTree(root, index, newCount))
    {
        printf("It is a Complete Binary Tree");
    }
    else
    {
        printf("It is not a Complete Binary Tree");
    }
    
    return 0;
}