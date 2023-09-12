/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

void pivot(int *arr, int len);

int main()
{
    int a[LENGTH];
    printf("Merge Sort algorithm: \n");
    printf("Enter an array of 10 numbers: \n");
    for(int i=0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
  
    printf("The unsorted array is: \n");
    for(int i=0; i < 10; i++)
    {
        printf("%d\n", a[i]);
    }
    
    //implement quick sort to sort the array
    pivot(a, LENGTH);
    
}

void pivot(int *arr, int len)
{

    if(len <= 1)
    {
        return;
    }
    int pivotIndex = len-1;
    int pivotNum = arr[pivotIndex];
    
    int *rightArr = (int *)malloc((len)*sizeof(int));
    int *leftArr = (int *)malloc((len)*sizeof(int));
    int piv = -1;
    int j = 0, k = 0;
    printf("The pivot is %d\n", pivotNum);
    for(int i=0; i<len - 1; i++)
    {
        if(arr[i] > pivotNum)
        {
            //if element in arr[i] is greater than pivot
            //put in right array
            rightArr[j] = arr[i];
            j++;
            
        }
        else
        {
            //if element in arr[i] is less than pivot
            //put in left array
            
            leftArr[k] = arr[i];
            k++;
        }
    }
    
    printf("Left array < pivot \n");
    for(int i=0; i < k; i++)
    {
        printf("%d\t", leftArr[i]);
    }
    printf("\n");
    printf("Right array > pivot \n");
    for(int i=0; i < j; i++)
    {
        printf("%d\t", rightArr[i]);
    }
    
    
    if(j > 1) //if size of rightArr is less or equal to one, stop recursion
       pivot(rightArr, j);
    else if(j == 1) //if size of rightArr is equal to one, return to array
    {
        rightArr[len - 1] = rightArr[0];
        
    }
    if(k > 1)
        pivot(leftArr, k);
    else if(k == 1)
    {
        leftArr[len - 1] = leftArr[0];
        
    }
     
    free(leftArr);   
    free(rightArr);
}



