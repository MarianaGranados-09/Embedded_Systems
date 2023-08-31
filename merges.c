#include <stdio.h>
#include <stdlib.h>
#define LENGTH  10

int* slice(int *arr, int start, int end);
void merge(int *result, int *left, int *right, int leftLen, int rightLen);
void mergeSort(int *arr, int len);
void printArray(int* arr, int len);

int main(void)

{
    int lis[LENGTH] = {1,9,2,8,3,7,4,6,5,0};
    mergeSort(lis, LENGTH);
    printArray(lis, LENGTH);
    return 0;
}
/** Make a copy of an array from start to end - 1.
Equivalent to Python's arr[start:end] */
int* slice(int *arr, int start, int end)
{
    int *result = (int *) malloc((end - start) * sizeof(int));
    int i;
    for (i = start; i < end; i++)
    {

        result[i - start] = arr[i];
    }
    return result;
}
/** Merge left and right into result, overwriting everything in result. */
void merge(int *result, int *left, int *right, int leftLen, int rightLen)
{
    int i = 0, j = 0;
    while(i < leftLen && j < rightLen)
    {
        if (left[i] < right[j])
        {
            result[i + j] = left[i];
            i++;
        }
        else
        {
            result[i + j] = right[j];
            j++;
        }
    }
    for(; i < leftLen; i++)
    {
        result[i + j] = left[i];
    }
    for(; j < rightLen; j++)
    {
        result[i + j] = right[j];
    }
    free(left);
    free(right);
}
// in-place merge sort
void mergeSort(int *arr, int len)
{
    if (len <= 1)
    {
        return;
    }
    int *left = slice(arr, 0, len / 2 );
    int *right = slice(arr, len / 2, len);
    printf("left: ");
    printArray(left, len / 2);
    printf("right: ");
    printArray(right, len - (len / 2));
    mergeSort(left, len / 2);
    mergeSort(right, len - (len / 2));
    merge(arr, left, right, len / 2, len - (len / 2));
}
/** Print an array of ints */
void printArray(int* arr, int len)
{
    int i = 0;
    printf("[");
    for(; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}
