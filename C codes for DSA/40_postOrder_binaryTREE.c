#include<stdio.h>
#include<malloc.h>

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node* createNode(int data){
     struct Node* p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void postOrder(struct Node*root){
    if(root !=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    

    // constructing the nodes using functions:
    struct Node* p = createNode(4);
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(6);
    struct Node* p3 = createNode(5);
    struct Node* p4 = createNode(2);
    // Structure Of Tree:
    //        4
    //      /   \   
    //     1     6
    //    / \                      
    //   5   2 

    // linking the root node with left and right children:
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4; 
    
    // Function Call:
    postOrder(p);

    return 0;
}