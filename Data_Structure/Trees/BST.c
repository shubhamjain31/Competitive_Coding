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

//Insert a Node
struct node* insert(struct node* root, int item)
{
    //Return a new node if the tree is empty
    if(root == NULL)
    {
        return createNode(item);
    }
    
    //Traverse to the right place and insert the node
    if(root -> data > item)
    {
        root -> left = insert(root -> left, item);
    }
    else
    {
        root -> right = insert(root -> right, item);
    }
    return root;
}

//Function to check if a given node exists in a BST or not
int search(struct node* root, int item)
{
    while(root != NULL)
    {
        //Checking condition and passing right subtree & recusing
        if(item > root -> data)
        {
            root = root -> right;
        }
        
        //Checking condition and passing left subtree & recusing
        else if(item < root -> data)
        {
            root = root -> left;
        }
        else
        {
            //if the value is found return 1 
            return 1;
        }
    }
    return 0;
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
        //If the node is with only one child or no child
        if(root -> left == NULL)
        {
            struct node *temp = root -> right; 
            free(root); 
            return temp; 
        } 
        else if(root -> right == NULL)
        {
            struct node *temp = root -> left; 
            free(root);
            return temp; 
        }
        
        //If the node has two children
        struct node* temp = minValueNode(root -> right);
        // Place the inorder successor in position of the node to be deleted 
        root -> data = temp -> data; 
        // Delete the inorder successor 
        root -> right = delete(root -> right, temp -> data); 
    }
    return root;
}

int main()
{

    /* Our BST will look like this 
                100 
               /   \ 
              40   140 
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
    int item = 190;
    
    //Function to find item in the tree
    int found = search(root,item);
    if(found)
        printf("%d value is found in the tree",item);
    else
        printf("%d value is not fou6d",item);
   
    
    printf("\nAfter deleting 10\n"); 
    root = delete(root, 140);
    
    printf("\nInorder traversal: \n");
    traverse(root);
    return 0;
}