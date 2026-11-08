#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int get_height(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}

struct Node *create_node(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int maxGet(int a, int b)
{
    return a > b ? a : b;
}
int getBalancedFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return get_height(n->left) - get_height(n->right);
}

struct Node *right_rotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = maxGet(get_height(y->left), get_height(y->right)) + 1;
    x->height = maxGet(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

struct Node *left_rotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = maxGet(get_height(y->left), get_height(y->right)) + 1;
    x->height = maxGet(get_height(x->left), get_height(x->right)) + 1;

    return y;
}
struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return create_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);

    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + maxGet(get_height(node->left), get_height(node->right));
    int bf = getBalancedFactor(node);

    // LL Case
    if (bf > 1 && key < node->left->key)
    {
        return right_rotation(node);
    }

    // RR Case
    if (bf < -1 && key > node->right->key)
    {
        return left_rotation(node);
    }

    // LR Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = left_rotation(node->left);
        return right_rotation(node);
    }

    // RL Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = right_rotation(node->right);
        return left_rotation(node);
    }
    return node;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrder(root);
    return 0;
}