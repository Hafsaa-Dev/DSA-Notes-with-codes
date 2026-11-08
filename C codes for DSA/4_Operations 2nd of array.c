#include<iostream>
       // Code for traversal                               
void display(int arr[],int n){
	
	for(int i = 0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	}
        //  Code for deletion
void indexDeletion(int arr[],int size,int index){
	
	for(int i = index; i < size-1; i++){
	arr[i] = arr[i+1] ;
	}
}

int main(){
	
	int arr[100] = {7,8,12,27,88};
	int size = 5,  index = 3;
	display(arr,size);
	
	indexDeletion(arr,size,index);
	
	size-=1;
		display(arr,size);
	
	return 0;
}
