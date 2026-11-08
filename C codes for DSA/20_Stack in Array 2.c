#include<stdio.h>
#include<stdlib.h>
                    // Stack using Array: (Push and Pop Operations)
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
         // Push Func:
void push(struct stack *ptr,int val){
	if(isFull(ptr)){
		printf("Stack Overflow!Cannot push %d to the stack:\n",val);
	}
	else{
		ptr->top++;
		ptr->arr[ptr->top] = val;
	}
}
         // Pop Func:
int pop(struct stack *ptr){
	if(isEmpty(ptr)){
		printf("Stack Underflow!Cannot pop from the stack:\n");
		return -1;
	}
	else{
		int val = ptr->arr[ptr->top];
		ptr->top--;
		return val;
	}
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

        s->size = 6;
        s->top = -1;

        s->arr = (int *)malloc(s->size * sizeof(int));
        printf("Stack is successfully created!\n");
       
    // Check if stack is empty...
    	printf("Before Pushing,Empty!: %d\n",isEmpty(s));
	
	// Check if stack is full...
    	printf("Before Pushing,Full!: %d\n",isFull(s));

	// Push Operation:
     push(s,1);
     push(s,2);
     push(s,3);
     push(s,4);
     push(s,5);
     push(s,6);
     //push(s,7);  //stack overflow beacuse the size of array is 6:
     
     
     printf("After Pushing,Empty!: %d\n",isEmpty(s));
     printf("After Pushing,Full!: %d\n",isFull(s));
     
     printf("Popped %d from the stack\n",pop(s)); // Last In First Out:

     system("pause");

    return 0;
}
