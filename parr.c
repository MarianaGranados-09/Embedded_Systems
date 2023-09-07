#include <stdio.h>
#include <stdlib.h>

int strleng(char *s);

int main()
{
    char array[10] = {'a','b','c','d','e'};
    printf("%d", strlen(array));
    return 0;
}

int strleng(char *s)
{
    int n;
    //since s is a pointer, incrementing it is perfectly legal
    //s++ has no effect on the character string in the function that
    //called strlen, but merely increments private copy of a pointer
    for(n = 0; *s != '\0'; s++)
    {
        n++;
    }
    return n;
}

//char s[] and char *s are equivalent
