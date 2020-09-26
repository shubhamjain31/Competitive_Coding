#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//Create a new Node
struct node* createNode(item)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = item;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

//Inorder traversal
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

//Preorder traversal
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

//Postorder traversal
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

//Insert on the left of the node
struct node* insertLeft(struct node* root, int item)
{
    root -> left = createNode(item);
    return root -> left;
}

//Insert on the right of the node
struct node* insertRight(struct node* root, int item)
{
    root -> right = createNode(item);
    return root -> right;
}


int main()
{
    struct node* root = createNode(2);
    insertLeft(root, 12);
    insertRight(root, 3);
    
    insertLeft(root->left, 5);
    insertRight(root->left, 6);
    
    printf("Inorder traversal \n");
    inOrder(root);
    
    printf("\n\n");
    printf("Preorder traversal \n");
    preOrder(root);
    
    printf("\n\n");
    printf("Postorder traversal \n");
    postOrder(root);
    return 0;
}