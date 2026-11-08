#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j); 

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quickSort(int *A, int low, int high)
{
    int partition_index; // index of pivot after partition

    if (low < high)
    {
        partition_index = partition(A, low, high);
        // printArray(A,6);
        quickSort(A, low, partition_index - 1);  // sort left sub array
        quickSort(A, partition_index + 1, high); // sort right sub array
    }
}
int main()
{
    int A[] = {2, 0, 3, 1, 7, 5};
    int n = 6;
     printf("Before Sorting\n");
    printArray(A, n);
    quickSort(A,0,n-1);
     printf("After Sorting\n");
    printArray(A, n);
    return 0;
}