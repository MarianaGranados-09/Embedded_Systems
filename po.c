#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    int *pa; //pa is a pointer to an int
    
    pa = &a[0]; //sets pa to point to element zero of a;
    //pa contains the address of a[0]
    
    x = *pa; //copies the contents of a[0] into x
    x1 = *(pa+1); //refers to the contents of a[1], 
    
    //since the name of an array is a synonym for the location of the
    //initial element, the assignment pa = &a[0] can also be written as
    pa = a;
    //a[i] can also be written as *(a+i)
    return 0;
}
