/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
/*
Create a C program that prints the sum of all the digits of a positive integer. 
Ex 1234 -> 1+2+3+4 = 10.
*/
int main()
{
    int number, i, sum = 0, newnum;
    //register of number
    printf("Enter an integer: \n");
    scanf("%d",&number);
   
    //calculate size of int spaces to occupy in string
    int sz = (int)((ceil(log10(number))+1)*sizeof(char));
    //string of sz size
    char str[sz];
    //int to string
    sprintf(str, "%d", number);
    //print out string
    printf("My number is: %s\n", str);
    //print out size of string
    printf("Size of number: %ld \n", sizeof(str)-1);
    for(i=0;i<sz-1;i++)
    {
        //printf("%c\n", str[i]);
        newnum = str[i] - '0';
        sum = sum + newnum;
    }
    
    printf("The sum is of each number of %d is: %d", number, sum);
    
    return 0;
}

