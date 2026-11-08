#include<stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int * A,int n){
    int indexOFMin, temp;
      printf("Running Selection sort...\n");
      for (int i = 0; i < n-1; i++)
      {
        indexOFMin = i;
        for (int j = i+1; j < n; j++)
        {
            if( A[j] < A[indexOFMin]){
            indexOFMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOFMin];
        A[indexOFMin] = temp;
        
      }
      
}
int main(){
    int A[] = {2,0,3,1,7,5};
    int n = 6;
     printf("Before Sorting\n");
    printArray(A,n);
    selectionSort(A,n);
     printf("After Sorting\n");
    printArray(A,n);
    return 0;
}