#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int item)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = item;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void inOrder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root -> left);
    printf("%d ", root -> data);
    inOrder(root -> right);
}

struct node* lca(struct node* root, int x, int y)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    //if both n1 and n2 are smaller than root, then LCA lies in left
    if(root -> data > x && root -> data > y)
    {
        return lca(root -> left, x, y);
    }
    
    //if both n1 and n2 are greater than root, then LCA lies in right
    if(root -> data < x && root -> data < y)
    {
        return lca(root -> right, x, y);
    }
    return root;
}

int main()
{
    struct node* root = createNode(2);
    root -> left = createNode(3);
    root -> right = createNode(5);
    root -> left -> left = createNode(13);
    root -> right -> left = createNode(50);
    root -> left -> right = createNode(22);
    root -> right -> left = createNode(42);
    
    printf("Inorder Traversal:\n");
    inOrder(root);
    
    int x = 3, y = 5;
    struct node* t = lca(root, x, y);
    printf("\n\nLCA of %d and %d is %d \n", x, y, t->data);
 
    return 0;
}