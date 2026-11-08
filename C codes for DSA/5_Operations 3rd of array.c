#include<iostream>

       // Code for Linear search!
	                                
int linearSearch(int arr[],int size,int element){
	
	for(int i = 0; i<size; i++){
		if(arr[i]==element){
			return i;
		}
	}
        return -1;
	
}
int main(){
	int arr[]={21,4,8,634,34,9,64,348,1,0,100};
	int size= sizeof(arr)/sizeof(int);
	int element = 9;
	
	int searchIndex = linearSearch(arr,size,element);
	
	printf("The element %d found at index %d...\n",element,searchIndex);
	
	return 0;
}
