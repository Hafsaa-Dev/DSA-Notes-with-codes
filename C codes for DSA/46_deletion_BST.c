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
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct Node *search_Iter(struct Node *root, int key)
{

    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

struct Node *insert(struct Node *root, int key)
{
    struct Node *prev;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, Already in BST!");
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct Node *inOrderPredecessor(struct Node*root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct Node *deletion(struct Node *root, int value)
{
    struct Node *inPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // Search for the node to be deleted:
    if (value < root->data)
    {
       root->left = deletion(root->left, value);
    }
    else if (value > root->data)
    {
       root->right = deletion(root->right, value);
    }
    // Deletion strategy when the node is found:
    else
    {
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = deletion(root->left, inPre->data);
    }

    return root;
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
    inOrder(p);
    deletion(p,5);
    printf("\n");
    // printf("|Data is %d |",p->data);
    inOrder(p);

    return 0;
}