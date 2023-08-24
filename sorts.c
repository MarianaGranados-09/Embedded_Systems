#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE   16

void print_arr_ptr(char **arr, int arr_size){
   for(int i=0; i<arr_size; i++){
      printf("%d:- %s.\n", i, arr[i]);
      //print(arr[i]);
   }
   printf("\n");
}


int main(){
   char temp[STR_SIZE] = {0};
   int arr_size = 4;

   // ask for memory
   char **arr=NULL;
   arr = malloc(arr_size*sizeof(char *));
   for(int i=0;i<arr_size;i++){
      arr[i] = malloc(STR_SIZE*sizeof(char));
   }

   int i=0;
   while(fgets(arr[i], STR_SIZE, stdin)){
      arr[i][strlen(arr[i])-1] = '\0';

      if (i>= arr_size-1){
         printf("Reallocating more memory, now: %d, after: %d\n", arr_size, arr_size*2);
         arr = realloc(arr, arr_size*2*sizeof(char *));
         for(int j=arr_size;j<arr_size*2;j++){
            arr[j] = malloc(STR_SIZE*sizeof(char));
         }
         arr_size = arr_size*2;
      }

      i++;
   }
   printf("Finished reading strings.\n");

   print_arr_ptr(arr, arr_size);

   printf("The sorted strings are: .\n");
   for(int j=0;j<arr_size-1;j++)
   {
       for(int k=0;k<i-j-1;k++)
       {
           if(strcmp(arr[k], arr[k+1]) > 0)
           {
               char temp[STR_SIZE];
               strcpy(temp, arr[k]);
               strcpy(arr[k], arr[k+1]);
               strcpy(arr[k+1], temp);
           }
       }
   }

   print_arr_ptr(arr, i);


   // free memory
   for(int i=0;i<arr_size;i++){
      free(arr[i]);
   }
   free(arr);

   return 0;
}

