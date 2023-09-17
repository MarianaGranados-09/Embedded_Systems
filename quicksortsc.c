#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 16 //caracteres x cadena

void quickSort(char **a, int low, int high);
void print_arr_ptr(char **arr, int arr_size){
    for(int i=0; i<arr_size; i++){
        printf("%d:- %s.\n", i, arr[i]);
        //print(arr[i]);
    }
    printf("\n");
}

char **allocate_array(int arr_size){
    char **arr=NULL; //arreglo de punteros
    arr = malloc(arr_size*sizeof(char *)); //asignamos el puntero que apunta al vector de punteros.
    for(int i=0;i<arr_size;i++){
        arr[i] = malloc(STR_SIZE*sizeof(char));
    }
    return arr;
}

char **reallocate_array(char **arr, int *arr_size){
    printf("Reallocating more memory, now: %d, after: %d\n", *arr_size, *arr_size*2);
    arr = realloc(arr, *arr_size*2*sizeof(char *));
    for(int j=(*arr_size);j<(*arr_size)*2;j++){
        arr[j] = malloc(STR_SIZE*sizeof(char));
    }
    *arr_size = *arr_size*2;
    return arr;
}

char **read_strings(char **arr, int arr_size, int *read_lines){
    int i=0;
    while(fgets(arr[i], STR_SIZE, stdin))
    {
        arr[i][strlen(arr[i])-1] = '\0';
        // reallocate if not enough memory
        if (i>= arr_size-1){
            reallocate_array(arr, &arr_size);
        }
        i++;
    }
    *read_lines = i;
    return arr;
}

void free_arr(char **arr, int arr_size){
    for(int j = 0; j < arr_size; j++)
    {
        free(arr[j]);
    }
    free(arr);
}

int main(){
    int arr_size= 4; //definimos con mem. estática el número de strings
    char **arr=allocate_array(arr_size); // ask for memory
    int read_lines=0;
    read_strings(arr, arr_size, &read_lines);
    printf("Finished reading strings. The unsorted strings are: \n");
    printf("Quicksort algorithm starting...\n\n");
    quickSort(arr, 0, read_lines-1);
    printf("The sorted strings are: \n");
    print_arr_ptr(arr, read_lines-1);
    printf("\n");
    free_arr(arr, arr_size);
    return 0;
}

void swap(char **a, char **b){
    char *t = *a;
    *a = *b;
    *b = t;
}

int partition(char **a, int low, int high){
    // Choosing the pivot
    char *pivot = a[high];
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if(strcmp(a[j], pivot) <= 0){//substraction of the characters
            // Increment index of smaller element
            i++;
            swap( &a[i], &a[j]);
        }
    }
    swap( &a[i + 1], &a[high]);
    return (i + 1);
}

/**
 * Quicksort
 *
 * @arr Array to be sorted
 * @low Starting index,
 * @high Ending index,
 *
 * @return a pointer to the sorted strings
 */
void quickSort(char **a, int low, int high){
    if (low < high) {
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(a, low, high);
        // Separately sort elements before
        // partition and after partition
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

