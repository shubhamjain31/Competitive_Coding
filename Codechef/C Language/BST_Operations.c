#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

//Basic struct of Tree 
struct node
{
    int data, p;
    struct node* left;
    struct node* right;
};

struct node*ptr = NULL;

//Creating a new node
struct node* createNode(int item, int p)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = item;
    newNode -> p = p;               //position
    newNode -> left = NULL;
    newNode -> right = NULL;
    printf("%d\n",newNode -> p);
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
struct node* insert(struct node* root, int item, int p)
{
    //Return a new node if the tree is empty
    if(root == NULL)
    {
        return createNode(item, p);
    }
    
    //Traverse to the right place and insert the node
    if(root -> data > item)
    {
        root -> left = insert(root -> left, item, 2*p);
    }
    else
    {
        root -> right = insert(root -> right, item, 2*p+1);
    }
    return root;
}

//Find the inorder successor
struct node *minValueNode(struct node *root)
{
    struct node *current = root;
    //Find the leftmost leaf 
    while(current && current -> left != NULL)
    {
        current = current -> left; 
    }
    return current;
}

//Deleting a node
struct node* delete(struct node* root, int item)
{
    static int flag;
    //Return if the tree is empty
    if(root == NULL)
    {
        return root;
    }
    
    //Find the node to be deleted
    if(root -> data > item)
    {
        root -> left = delete(root -> left, item);
    }
    else if(root -> data < item)
    {
        root -> right = delete(root -> right, item);
    }
    
    else
    {
        //If the node has two children
        struct node* t;
        if(root -> left && root -> right)
        {
           printf("%d\n",root -> p);
           flag = 5;
           t = minValueNode(root -> right);

           // Place the inorder successor in position of the node to be deleted 
           root -> data = t -> data;
           // Delete the inorder successor 
           root -> right = delete(root -> right, t -> data); 
           //If the node is with only one child or no 
        }
        else
        {
            if(flag != 5)
            {
               printf("%d\n",root -> p);
            }
            else
            {
               flag = 3;
            }
           
            if(root -> left)
              t = root -> left;
            else
              t = root -> right;
             
            free(root);
            return t; 
        }
    }
    return root;
}

int main()
{

    struct node* root = NULL;
    int cases;
    scanf("%d",&cases);
    for(int i=0; i<2*cases; i++)
    {
        char ch;
        int num;
        scanf("%c %d",&ch,&num);
        if(ch=='i'){
            root = insert(root,num,1);
        }   
        if(ch=='d'){
            root = delete(root,num);
        }
    }
    
    // printf("\nTree is\n"); 
    // traverse(root);
    return 0;
}