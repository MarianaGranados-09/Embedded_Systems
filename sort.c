#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRNUM 10
#define STRSIZE 128

int main() {
    char  strings[STRNUM][STRSIZE];

    for(int i=0 ; i<STRNUM; i++)
    {
      printf("Enter your %i string: ", i+1);
      gets(strings[i]);
    }

      for (int i = 0; i < STRNUM- 1; i++)
    {
        for (int j = 0; j < STRNUM- i - 1; j++)
        {
                if(strcmp(strings[j], strings[j+1]) > 0)
                {
                     char temp[STRSIZE];
                      strcpy(temp, strings[j]);
                     // strcpy(strings[j+1], temp); //use strcpy instead
                      strcpy(strings[j],strings[j+1]);
                      strcpy(strings[j+1], temp);
                 }
        }
    }

    printf("Orden ascendente\n");
    for (int i = 0; i <STRNUM; i++) {
        printf("%s\n ", strings[i]);
    }

    printf("\n");

    return 0;
}
