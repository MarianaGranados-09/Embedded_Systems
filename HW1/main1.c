/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
/*
Create a C program that, given an integer,
prints the number of ones it contains in binary 9-> 1001b.
=> 2 bits “1”. 7-> 111 -> 3 bits ‘1’.
*/
int main()
{
    int number;
    int bin[10];
    int ones = 0;
    printf("Enter a number: \n");
    scanf("%d", &number);
    int i = 0; 
    while (number > 0) {
        bin[i] = number % 2; // remainder stored in the array
        if (bin[i] == 1) {
            ones++;
        }
        number = number / 2; // Division
        i++; // increment loop
    }
    
    printf("Number of ones: %d", ones); //outputs how many 1 bits are in number
    return 0;
}

