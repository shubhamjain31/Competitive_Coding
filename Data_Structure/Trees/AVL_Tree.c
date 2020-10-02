#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

//Calculate height
int height(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root -> height;
}

//Function to get maximum of two integers
int max(int a, int b)
{
    return (a>b)?a:b;
}

//Create a node
struct node* createNode(int item)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = item;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> height = 1;
    return newNode;
}

//Right rotate
struct node* rightRotation(struct node* y)
{
    struct node* x = y -> left;
    struct node* temp = x -> right;
    
    //Perform rotation 
    x -> right = y;
    y -> left = temp;
    
    //Update heights 
    y -> height = max(height(y -> left), height(y -> right) +1);
    x -> height = max(height(x -> left), height(x -> right) +1);
    
    return x;
}

//Left rotate
struct node* leftRotation(struct node* x)
{
    struct node* y = x -> right;
    struct node* temp = y -> left;
    
    //Perform rotation
    y -> left = x;
    x -> right = temp;
    
    //Update heights 
    x -> height = max(height(x -> left), height(x -> right) +1);
    y -> height = max(height(y -> left), height(y -> right) +1);
    
    return y;
}

//Get the balance factor
int getBalance(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return height(root -> left) - height(root -> right);
}

//Insert node
struct node* insertNode(struct node* root, int item)
{
    //Find the correct position to insertNode the node and insertNode it
    if(root == NULL)
    {
        return createNode(item);
    }
    if(item < root -> data)
    {
        root -> left = insertNode(root -> left, item);
    }
    else if(item > root -> data)
    {
        root -> right = insertNode(root -> right, item);
    }
    else
    {
        return root;
    }
    
    //Update the balance factor of each node and Balance the tree
    root -> height = 1 + max(height(root -> left), height(root -> right));
    
    //Get Balance factor of node root
    int balance = getBalance(root);
    
    //LL case
    if(balance > 1 && item < root -> left -> data)
    {
        return rightRotation(root);
    }
    
    //RR case
    if(balance < -1 && item > root -> right -> data)
    {
        return leftRotation(root);
    }
    
    //LR case
    if(balance > 1 && item > root -> left -> data)
    {
        root -> left = leftRotation(root -> left);
        return rightRotation(root);
    }
    
    //RL case
    if(balance < -1 && item < root -> right -> data)
    {
        root -> right = rightRotation (root -> right);
        return leftRotation(root);
    }
    return root;
}

//Find the inorder successor
struct node* minValueNode(struct node* root)
{
    struct node* current = root;
    while(current != NULL)
    {
        current = current -> left;
    }
    return current;
}

//Deleting a node
struct node* deleteNode(struct node* root, int item)
{
    //Find the node and delete it
    if(root == NULL)
    {
        return root;
    }
    if(item < root -> data)
    {
        root -> left = deleteNode(root -> left, item);
    }
    else if(item > root -> data)
    {
        root -> right = deleteNode(root -> right, item);
    }
    else
    {
        if((root->left == NULL) || (root -> right == NULL))
        { 
            struct node *temp = root->left ? root->left : root->right; 
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
                free(temp);
            }
        }
        else
        {
            struct node* temp = minValueNode (root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data); 
        }
    }
    if(root == NULL)
    {
        return root;
    }
    
    //Update the balance factor of each node and balance the tree
    root -> height = 1 + max(height(root -> left), height(root -> right)); 
    int balance = getBalance(root); 
    if(balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotation(root);
    }
    if(balance > 1 && getBalance(root -> left) < 0)
    {
         root -> left = leftRotation(root -> left); 
        return rightRotation(root);
    } 
    if(balance < -1 && getBalance(root -> right) <= 0) 
    {    
       return leftRotation(root);
    }
    if(balance < -1 && getBalance(root -> right) > 0)
    { 
        root -> right = rightRotation(root -> right); 
        return leftRotation(root); 
    }
    return root;
}

//Print the tree
void traverse(struct node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root -> data); 
        traverse(root -> left);
        traverse(root -> right); 
    } 
}

int main()
{
    struct node* root = NULL;
    
    root = insertNode(root, 2); 
    root = insertNode(root, 1); 
    root = insertNode(root, 7); 
    root = insertNode(root, 4); 
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    
    printf("Inorder Traverse: \n");
    traverse(root);
    
    root = deleteNode(root, 8);
    printf("\n\nAfter deletion: \n"); 
    traverse(root);
    return 0;
}