#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define STRNUM 10
#define STR_SIZE 128

void print_arr_ptr(char **arr, int arr_size){
   for(int i=0; i<arr_size; i++){
      printf("%d:- %s.\n", i, arr[i]);
      //print(arr[i]);
   }
   printf("\n");
}


void merge_sort(char **a, int len); //accepts the array and its length
void merge_sort_recursion(char **a, int l, int r); //recursive step of the algorithm, where we cont.
//divide the array into smaller arrays
void merge_sorted_arrays(char **a, int l, int m, int r); //merge two sorted portions of the array

int main()
{

    int arr_size = 4;
    char **arr = NULL;
    arr = malloc(arr_size*sizeof(char *));

     for(int y=0;y<arr_size;y++){
      arr[y] = malloc(STR_SIZE*sizeof(char));
   }

   int i=0;
   while(fgets(arr[i], STR_SIZE, stdin)){
      arr[i][strlen(arr[i])-1] = '\0';

      if (i>= arr_size-1){
         arr = realloc(arr, arr_size*2*sizeof(char *));
         for(int t=arr_size;t<arr_size*2;t++){
            arr[t] = malloc(STR_SIZE*sizeof(char));
         }
         arr_size = arr_size*2;
      }

      i++;
   }
   printf("Finished reading strings. The unsorted strings are: \n");

   print_arr_ptr(arr, i);

    printf("Merge sort algorithm starting...\n");
    printf("\n");
    merge_sort(arr, i);

    printf("The sorted strings are: \n");
    print_arr_ptr(arr, i);
    printf("\n");
    for(int j = 0; j < arr_size; j++)
    {
        free(arr[j]);
    }
    free(arr);

    printf("\n");
    return 0;
}

//merge_sort recibe el array de cadenas y la longitud del array
void merge_sort(char **a, int len)
{
    merge_sort_recursion(a, 0, len-1); //merge_sort_recursion recibe el array de cadenas, la posicion 0
    //indicando la primera cadena y la posicion len-1, que indica la ultima cadena del array

}

//merge_sort_recursion ejecuta el algoritmo, recibe primero el array de cadenas, despues un valor low y high
//tambien se puede entender como valor left y right, que corresponden a la seccion izquierda y seccion derecha del array
void merge_sort_recursion(char **a, int l, int r)
{
    //mientras left sea menor a right
    if(l < r) //keeps dividing the arrays r less than r
    {
        
        int m = l + (r - l) / 2; //finding the middle part of the array
        merge_sort_recursion(a, l,  m); //applying merge_sort_recursion-keeps calculating l and r until l < r
        //(breaking the array and the resultant arrays in half over and over again, hence divide and conquer)
        merge_sort_recursion(a, m + 1, r); 
        //printing arrays

        merge_sorted_arrays(a, l, m, r); //merge arrays
    }

}

void merge_sorted_arrays(char **a, int l, int m, int r)
{
    int leftlen = m - l + 1; //length of left portion of array
    int rightlen = r - m; //length of right portion of array

    char *temp_left[leftlen];
    char *temp_right[rightlen];

    int i, j, k;
    for(int o=0; o<leftlen; o++)
    {
        //creating memory for temporary left half array:
        temp_left[o] = malloc(STR_SIZE * sizeof(char));
        strcpy(temp_left[o], a[l + o]);
        //temp_left[i] =  a[l + i]; //the temporary array takes the values of the first half of the array
    }
    for(int p=0; p<rightlen; p++)
    {
        //creating memory for the temp. right half array
        temp_right[p] = malloc(STR_SIZE * sizeof(char));
        strcpy(temp_right[p], a[m + 1 + p]);
        //temp_right[i] = a[m + 1 + i]; //the temporary array takes value of the second half of the array
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
        if((i < leftlen) && (j >= rightlen || strcmp(temp_left[i], temp_right[j]) <= 0))
        {
            strcpy(a[k], temp_left[i]);
            //**a[k] = **temp_left[i];
            i++;
        }
        else{
            //assign the current element of the right temp array to the a array
            strcpy(a[k], temp_right[j]);
            //**a[k] = **temp_right[j];
            j++;
        }

    }
    
    for (int i = 0; i < leftlen; i++)
    {
        free(temp_left[i]);
    }
    for (int j = 0; j < rightlen; j++)
    {
        free(temp_right[j]);
    }
    

}
