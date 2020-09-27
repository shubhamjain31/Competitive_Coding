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

void postOrder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d ", root -> data);
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
    
    printf("Inorder Traversal:\n");
    inOrder(root);
    
    printf("\n\n");
    printf("Preorder Traversal:\n");
    preOrder(root);
    
    printf("\n\n");
    printf("Postorder Traversal:\n");
    postOrder(root);
    return 0;
}