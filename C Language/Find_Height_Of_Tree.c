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

int height(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        int left_side, right_side;
        left_side = height(root -> left);
        right_side = height(root -> right);
        if(left_side > right_side)
        {
            return left_side + 1;

        }
        else
        {
            return right_side + 1;
        }
    }
}

int main()
{
    struct node* root = createNode(2);
    insertLeft(root, 5);
    insertRight(root, 7);
    insertLeft(root -> left, 8);
    insertRight(root -> left, 4);
    insertLeft(root -> left -> left, 18);
    
    printf("Inorder Traversal:\n");
    inOrder(root);
    
    int treeHeight = height(root);
    printf("\n\nHeight of tree is: %d", treeHeight);
    return 0;
}