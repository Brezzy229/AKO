#include <stdio.h>
#include <stdlib.h>

void merge (int* arr, int start1, int end1 , int end2)
{
    int i,j,k;
    int n1 = end1 - start1 + 1;
    int n2 = end2 - end1     ;


    /* create temporay tab */

    int* arr1 = malloc(n1*sizeof(int));
    int* arr2 = malloc(n2*sizeof(int));

    /* copied data to temp array */

    for (i = 0; i < n1; i++)
        arr1[i] = arr[i+start1];
    for (j = 0; j < n2; j++)
        arr2[j] = arr[end1 + 1+ j];
    
    /* Merge subroutine */

    i = 0;
    j = 0; 
    k = start1;

    while (i <n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    /* copy the remaining elements of arr1[], if there are any */

    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    /* copy the remaining elements of arr1[], if there are any */

    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    free (arr1); free (arr2);
}

    /* Mersort fonction */

    void mergeSort (int* arr, int start, int end)
    {
        if (start < end)
        {
            int middle =  start + (end - start)/2;

            /* Sort first and second halves */

            mergeSort(arr, start, middle);
            mergeSort(arr, middle+1, end);

            merge(arr, start, middle, end);
        }
    }

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int *A, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main ()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, arr_size);
  
    mergeSort(arr, 0, arr_size - 1);
  
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;


}