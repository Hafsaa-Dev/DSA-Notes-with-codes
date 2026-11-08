#include<stdio.h>
#include<stdlib.h>
                    // Stack using Array: (Empty or full)
struct stack{
	int size;
	int top;
	int *arr;
};

int isEmpty(struct stack *ptr){
	if(ptr->top == -1){
	    return 1;	
	}
	else{
	    return 0;	
	}
}

int isFull(struct stack *ptr){
	if(ptr->top == ptr->size-1){
	    return 1;	
	}
	else{
	    return 0;	
	}
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

        s->size = 6;
        s->top = -1;

        s->arr = (int *)malloc(s->size * sizeof(int));
        
        // Put elements manually
        s->arr[0] = 11;
        s->arr[1] = 22;
        s->arr[2] = 33;
        s->arr[3] = 44;
        s->arr[4] = 55;
        s->arr[5] = 66;
        
         s->top = 5;
         
    // Check if stack is empty...
    
    if(isEmpty(s)){
    	printf("Stack is Empty!\n");
	}
	
    else{
    	printf("Stack is not Empty!\n");
    	
	}
	
	// Check if stack is full...
	if(isFull(s)){
    	printf("Stack is Full!\n");
	}
	
    else{
    	printf("Stack is not Full!\n");
    	
	}
     
     system("pause");

    return 0;
}
