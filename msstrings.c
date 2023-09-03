#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH  10
#define STR_SIZE 16

void print_arr_ptr(char **arr, int arr_size){
   for(int i=0; i<arr_size; i++){
      printf("%d:- %s.\n", i, arr[i]);
      //print(arr[i]);
   }
   printf("\n");
}

//functions for merge sort
char **slice(char **arr, int start, int end); //slices array into halves
void merge(char **result, char **left, char **right, int leftLen, int rightLen); //merges the extracted arrays
void mergeSort(char **arr, int len); //
void printArray(char **arr, int len);
int getStrings();

char **arr = NULL;
int arr_size = 0;

int main(void)

{
   // int lis[LENGTH] = {1,9,2,8,3,7,4,6,5,0};
    getStrings(); //function to get inputted user strings**
    printf("The unsorted strings are: ");
    print_arr_ptr(arr, arr_size);
    mergeSort(arr, arr_size); //pass array of numbers to sort, as well as length
    printf("The sorted strings are: ");
    printArray(arr, arr_size);

    for(int o=0;o<arr_size;o++)
        free(arr[o]);
    free(arr);

    return 0;
}
//1. takes an array, a starting index and an ending index as parameters

//2. dynamically allocates memory for a new array called result, and
//3. copies elements from the original array from the specified start to end-1

char **slice(char **arr, int start, int end) //1.
{
    char **result =malloc((end - start) * sizeof(char *)); //2.
    int i;
    for (i = start; i < end; i++)
    {
        result[i - start] = arr[i]; //3.
    }
    return result; //returns the newly created array
}

//takes two sorted arrays 'left' and 'right', their lengths
//and an empty array 'result' where the merged result is stored
void merge(char **result, char **left, char **right, int leftLen, int rightLen)
{
    int i = 0, j = 0, k=0;
    //iterates both 'left' and 'right' arrays, comparing elements
    //and copying them into the 'result' array in sorted order
    while(i < leftLen && j < rightLen) //loop continues until all elements from
    //left and right array are sorted
    {
        //strcmp returns less than, equal to, or greater than zero if s1 is less than, matches or greater than s2
        //respectively strcmp(s1,s2)

       // if (left[i] < right[j]) //if left array element is less than right array element
        //then puts left[i] in result array
        if(strcmp(left[i], right[j]) <= 0)
        {

           // result[i + j] = left[i];
           strcpy(result[k], left[i]);
            i++;
        }
        else
        {
            //the right array element is smaller, so right[j] is added
            //to the result array
            //result[i + j] = right[j];
            strcpy(result[k], right[j]);
            j++;
        }
        k++;
    }
    //after the loop, some remaining elements in either the left or right
    //array may remain, so they are copied to the result array using
    //2 additional for loops
    while(i < leftLen)
    {
        //result[i + j] = left[i];
        strcpy(result[k], left[i]);
        i++;
        k++;
    }
    while(j < rightLen)
    {
        //result[i + j] = right[j];
        strcpy(result[k], right[j]);
        j++;
        k++;
    }
    //free memory from left and right array
    //no longer needed
    //free(left);
    //free(right);
}

//mergeSort recursively divides the input array into two halves until
//the base case is reacher

//it uses the slice function to create left and right subarrays, then it
//recursively applies 'mergeSort' to both subarrays and merges them using
//the merge function
void mergeSort(char **arr, int len)
{
    if (len <= 1)
    {
        return;
    }
    int mid = len/2;
    char **left = slice(arr, 0, mid);
    char **right = slice(arr, mid, len);
    mergeSort(left, mid);
    mergeSort(right, len - mid);
    printf("Left: ");
    printArray(left, mid);
    printf("Right: ");
    printArray(right, len - mid);

    merge(arr, left, right, mid, len - mid);

    free(left);
    free(right);
}


//prints array
void printArray(char **arr, int len)
{
    int i = 0;
    printf("[");
    for(; i < len; i++)
    {
        printf("%s, ", arr[i]);
    }
    printf("]\n");
}

int getStrings()
{
    arr_size = 4;

    //ask for memory
    //char **arr = NULL;
    arr = malloc(arr_size*sizeof(char *));
    for(int i=0;i<arr_size;i++)
    {
        arr[i] = malloc(STR_SIZE*sizeof(char));
    }

    int i=0;
    while(fgets(arr[i], STR_SIZE, stdin)){ //memory direc, string size, and buffer
      arr[i][strlen(arr[i])-1] = '\0'; //replacing enter with EOF

      if (i>= arr_size-1){
         //printf("Reallocating more memory, now: %d, after: %d\n", arr_size, arr_size*2);
         arr = realloc(arr, arr_size*2*sizeof(char *));
         for(int j=arr_size;j<arr_size*2;j++){
            arr[j] = malloc(STR_SIZE*sizeof(char));
         }
         arr_size = arr_size*2;
      }

      i++;
   }

   return arr_size;
}
