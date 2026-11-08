#include<stdio.h>
#include<stdlib.h>
                    // // Stack using Array: (Peek Operation)
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
        // Peek Func:
int peek(struct stack*s,int i){
	int arrayInd = s->top-i+1;
	if(arrayInd<0){
		printf("Not valid position!\n");
		return -1;
	}
	else{
		return s->arr[arrayInd];
	}
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

        s->size = 6;
        s->top = -1;

        s->arr = (int *)malloc(s->size * sizeof(int));
        printf("Stack is successfully created!\n");
 

	// Push Operation:
     push(s,17);
     push(s,22);
     push(s,31);
     push(s,45);
     push(s,59);
     push(s,68);
     // push(s,0);
     
    for(int j=1; j<= s->top+1 ; j++){
    	printf("The value at position %d is %d.\n",j,peek(s,j));
 }
	 system("pause");

    return 0;
}
