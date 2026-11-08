#include<iostream>

       // Code for Binary search!
	                                
int binarySearch(int arr[],int size,int element){
	
	int low, high,mid;
	low = 0, high= size-1;
	
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==element){
			return mid;
		}
		if(arr[mid]<element){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return -1;
}
int main(){
	int arr[]={21,40,80,93,342,590,664,748,1000,1500,2100};
	int size= sizeof(arr)/sizeof(int);
	int element = 748;
	
	int searchIndex = binarySearch(arr,size,element);
	
	printf("The element %d found at index %d...\n",element,searchIndex);
	
	return 0;
}
