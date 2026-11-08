#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node *root)
{ 
    static struct Node* prev =NULL;
    if (root != NULL)
    {
       if (!isBST(root->left))
       {
        return 0;
       }
       if (prev !=NULL && root->data <= prev->data )
       {
        return 0;
       }
       prev = root;
       return isBST(root->right);
       
    }
    else{
        return 1;
    }
}

struct Node*search(struct Node*root,int key){
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if(root->data > key){
        return search(root->left,key);
    }
    else {
        return search(root->right,key);
    }
    
    
}
int main()
{

    // constructing the nodes using functions:
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
    // Structure Of Tree:
    //        5
    //      /   \   
    //     3     6
    //    / \                      
    //   1   4

    // linking the root node with left and right children:
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Function Call:
    struct Node*n =search(p,4);
    if (n != NULL)
    {
        printf("Found: %d",n->data);
    }
    else{
        printf("Element not found!");
    }
    
    return 0;
}