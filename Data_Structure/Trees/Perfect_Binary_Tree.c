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

//Calculate the depth
int depth(struct node* node)
{
    int i = 0;
    while(node != NULL)
    {
        i += 1;
        node = node -> left;
    }
    return i;
}

//Check if the tree is perfect
bool isPerfectBinaryTree(struct node* root, int d, int level)
{
    if(root == NULL)
    {
        return true;
    }
    if(root -> left == NULL && root -> right == NULL)
    {
        return d = level+1;
    }
    if(root -> left == NULL || root -> right == NULL)
    {
        return false;
    }
    
    return(isPerfectBinaryTree(root -> left, d, level+1) && isPerfectBinaryTree(root -> right, d, level+1));
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

//Wrapper function 
bool isPerfect(struct node *root)
{ 
    int d = depth(root); 
    return isPerfectBinaryTree(root, d, 0); 
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
    
    if(isPerfect(root))
    {
        printf("It is a Perfect Binary Tree");
    }
    else
    {
        printf("It is not a Perfect Binary Tree");
    }
    
    return 0;
}