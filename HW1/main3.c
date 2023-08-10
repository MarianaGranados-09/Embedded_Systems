/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
Create a C program that indicates whether a string is a palindrome “ana” “12321” “good”.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char str[100];
    int sizestr;
    int i,j;
    bool palindrome = 1;
    
    //capture string 
    printf("Insert a string: \n");
    scanf("%s", str);
    
    sizestr = strlen(str);
    for(i=0,j=sizestr-1; i<j; i++, j--)
    {
        if(str[i] != str[j])
        {
            palindrome = 0;
        }
    }
    if(palindrome)
        printf("The string is a palindrome\n");
    else
        printf("The string is not a palindrome\n");

    return 0;
}
