#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int n)
{
    int i, j;
    // Find the maximum element in A:
    int max = maximum(A, n);
    // Create the count array:
    int *count = (int *)malloc((max + 1) * sizeof(int));
    // Initialize the array elements to zero:
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    // Increment the corresponding index in the couny array:
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0; // Counter for count array
    j = 0; // Counter for main array
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int A[] = {2, 0, 3, 1, 7, 5};
    int n = 6;
    printf("Before Sorting\n");
    printArray(A, n);
    countSort(A,n);
    printf("After Sorting\n");
    printArray(A, n);
    return 0;
}