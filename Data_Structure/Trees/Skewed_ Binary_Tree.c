#include<stdio.h>

//Basic struct of Tree 
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

//Print the node in inorder format, when insertion is complete
void traverse (struct node* root)
{
    if(root != NULL)
    {
        traverse(root -> left);
        printf("%d ", root -> data);
        traverse(root -> right);
    }
}

//Check if the tree is skewed
int isSkewedBT(struct node* root)
{
    //check if node is NULL or is a leaf node 
    if(root == NULL || (root -> left == NULL && root -> right == NULL))
    {
        return 1;
    }
    
    //check if node has two children
    if(root -> left && root -> right)
    {
        return 0;
    }
    else
    {
        return isSkewedBT(root -> left);
    }
    return isSkewedBT(root -> right);
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

    /* Our BST will look like this 
               10 
              /  \ 
            12    13 
                 /  \ 
               14    15     
              /  \  /  \ 
             21  22 23  24  */

    struct node* root = createNode(10);
    insertLeft(root, 12);
    insertRight(root, 13);
    insertLeft(root -> right, 14);
    insertRight(root -> right, 15);
    insertLeft(root -> right -> left, 21);
    insertLeft(root -> right -> right, 22);
    insertRight(root -> right -> right, 24);
    insertRight(root -> right -> left, 23);
    
    //printing the return value of tree
    printf("%d", isSkewedBT(root));
    return 0;
}