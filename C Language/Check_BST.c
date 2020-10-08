#include<stdio.h>
#include<limits.h>

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

//Insert a Node
struct node* insert(struct node* root, int item)
{
    //Return a new node if the tree is empty
    if(root == NULL)
    {
        return createNode(item);
    }
    
    //Traverse to the right place and insert the node
    if(root -> data < item)
    {
        root -> left = insert(root -> left, item);
    }
    else
    {
        root -> right = insert(root -> right, item);
    }
    return root;
}

//function to determine if given binary tree is a BST or not
int checkBST(struct node* root, int min, int max)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root -> data < min || root -> data > max)
    {
        return 1;
    }
    return checkBST(root -> left, min, root -> data) && checkBST(root -> right, root -> data, max);
}

int isBST(struct node* root)
{
    return checkBST(root, INT_MIN, INT_MAX);
}

int main()
{

    /* Our BST will look like this 
                100 
               /   \ 
              60   140 
             / \   /  \ 
            40 80 120 160 */
    struct node* root = NULL;
    root = insert(root, 100);
    insert(root, 60);
    insert(root, 40);
    insert(root, 80);
    insert(root, 140);
    insert(root, 120);
    insert(root, 160);
    
    //printing the tree using inorder
    printf("Inorder traversal: \n");
    traverse(root);
    
    printf("\n\n");
    
    if(isBST(root))
    {
        printf("This is a BST");
    }
    else
    {
        printf("This is not a BST");
    }
    return 0;
}