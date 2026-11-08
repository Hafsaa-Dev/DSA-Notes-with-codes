#include<stdio.h>
#include<stdlib.h>
                     // Peek Operation:
struct Node{
    int data;
    struct Node*next;
};
    struct Node *top = NULL;
// Declared a Traversal Function:
void linkedListTraversal(struct Node*ptr){
	
	while(ptr!=NULL){
		printf("Element: %d\n",ptr->data);
		ptr = ptr->next;	
	}
}
      
int isEmpty(struct Node*top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct Node *top){
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Node*push(struct Node*top,int x){
    struct Node * n  = (struct Node*)malloc(sizeof(struct Node));
    if(isFull(top)){
        printf("Stack Overflow!\n");
    }
    else{
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int peek(int pos){
     struct Node *ptr = top;
     for(int i = 0; (i<pos-1 && ptr!=NULL);i++){
          ptr = ptr->next;
     }
     if(ptr!=NULL){
        return ptr->data;
     }
     else{
        return -1;
     }


}
int main(){

    top=push(top,7);
    top=push(top,14);
    top=push(top,28);
    linkedListTraversal(top);

    for(int i=1; i<4;i++){
    printf("Value at position %d is %d\n",i,peek(i));
    }
    return 0;
}