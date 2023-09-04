#include <stdio.h>
#include <stdlib.h>

void merge_sort(int a[], int len); //accepts the array and its length
void merge_sort_recursion(int a[], int l, int r); //recursive step of the algorithm, where we cont.
//divide the array into smaller arrays
void merge_sorted_arrays(int a[], int l, int m, int r); //merge two sorted portions of the array

int main()
{
    printf("Merge sort algorithm starting...\n");
    int array[] = {9,4,8,1,7,0,3,2,5,6};
    int len = 10;
    merge_sort(array, len);
    for(int i=0;i<len;i++)
    {
        printf("%d", array[i]);
    }

    printf("\n");
    return 0;
}

void merge_sort(int a[], int len)
{
    merge_sort_recursion(a, 0, len-1);

}

void merge_sort_recursion(int a[], int l, int r)
{

    if(l < r) //keeps dividing the arrays r less than r
    {
        int m = l + (r - 1) / 2; //finding the middle part of the array
        merge_sort_recursion(a, l,  m); //applying merge_sort_recursion
        //(breaking the array and the resultant arrays in half over and over again, hence divide and conquer)
        merge_sort_recursion(a, m + 1, r);
        merge_sorted_arrays(a, l, m, r); //merge arrays
    }

}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
    int leftlen = m - l + 1; //length of left portion of array
    int rightlen = r - m; //length of right portion of array

    int temp_left[leftlen];
    int temp_right[rightlen];

    int i, j, k;
    for(int i=0; i< leftlen; i++)
    {
        temp_left[i] =  a[l + i]; //the temporary array takes the values of the first half of the array
    }
    for(int i=0; i<rightlen; i++)
    {
        temp_right[i] = a[m + 1 + i]; //the temporary array takes value of the second half of the array
    }

    //three counter variables helping us index the three arrays
    //k index the actual array we are sorting - a

    //finds the next element from either temp arrays to copy into the array at index k
    //i and j indexes into the temporary arrays

    //i temp_left
    //j temp_right
    for(i = 0, j = 0, k = l; k <= r; k++)
    {
        //if i is less than the left array length and j is equal or bigger than right array length or the current element
        //in the right array is equal or bigger than the current element in the left array, then asssign the current element
        //of the left array to the a array using the k variable to index the a array
        if((i < leftlen) && (j >= rightlen || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++;
        }
        else{
            //assign the current element of the right temp array to the a array
            a[k] = temp_right[j];
            j++;
        }

    }

}









