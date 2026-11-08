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

int main(){
    // constructing the root node:
    // struct Node* p;
    // p = (struct Node*)malloc(sizeof(struct Node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;
    // // constructing the second node:
    // struct Node* p1;
    // p1 = (struct Node*)malloc(sizeof(struct Node));
    //  p1->data = 4;
    // p1->left = NULL;
    // p1->right = NULL;
    // // constructing the third node:
    // struct Node* p2;
    // p2 = (struct Node*)malloc(sizeof(struct Node));
    //  p1->data = 8;
    // p2->left = NULL;
    // p2->right = NULL;
    

    // constructing the nodes using functions:
    struct Node* p = createNode(2);
    struct Node* p1 = createNode(4);
    struct Node* p2 = createNode(8);
    // linking the root node with left and right children:
    p->left = p1;
    p->right = p2;
    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
// 	int data;
// 	struct Node* left;
// 	struct Node* right;
// };
// struct Node* createNode(int data)
// {
// 	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
// 	n->data=data;
// 	n->left=NULL;
// 	n->right=NULL;
	
// 	return n;
// }
// void LinkNode(struct Node* p,struct Node* c1,struct Node* c2)
// {
// 	p->left=c1;
// 	p->right=c2;
// }
// int traverse(struct Node* tree)
// {
// 	return tree->data;
// }
// int main()
// {
// 	struct Node* p=createNode(13);
// 	struct Node* p1=createNode(16);
// 	struct Node* p2=createNode(113);
// 	LinkNode(p,p1,p2);
// 	printf("%d\n",traverse(p));
// 	printf("%d \n",traverse(p->left));
// 	printf("%d \n",traverse(p->right));
// 	return 0;
		
// }