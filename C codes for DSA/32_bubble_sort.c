#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)  // For number of passes
    { 
        printf("Working on pass number %d\n",i+1);
        for (int j = 0; j < n-1-i; j++)
        { // For comparison in each pass
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }

    }
}
int main()
{
    int A[] = {21, 37, 11, 6, 78, 59};
    int n = 6;
    printArray(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Function to sort the array
    printArray(A, n); // Printing the array after sorting
    return 0;
}