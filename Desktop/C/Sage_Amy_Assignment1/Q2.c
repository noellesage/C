/* CS261- Assignment 1 - Q.2*/
/* Name: Amy Sage
 * Date: 4/17/18
 * Solution description: Pointer value manipulation 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    *a = *a+1;
    /* Decrement  b */
    *b = *b-1;
    /* Assign a+b to c */
    c = (*a) + (*b);

    /* Return c */
    return c;
}

int main(){
    srand(time(NULL));
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand() % 11;
    int y = rand() % 11;
    int z = rand() % 11;
    /* Print the values of x, y and z */
    printf("The values before foo is called are x=%i y=%i z=%i\n", x, y, z);
    /* Call foo() appropriately, passing x,y,z as parameters */
    int c = foo(&x, &y, z);
    /* Print the values of x, y and z */
    printf("The values after foo is called are x=%i y=%i z=%i\n", x, y, z);
    /* Print the value returned by foo */
    printf("The value returned by foo is: %i\n", c);

    return 0;
}
