/* CS261- Assignment 1 - Q.0*/
/* Name: Amy Sage
 * Date: 4/17/2018
 * Solution description: Pointer manipulation
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
     /*Print the value of iptr*/
     printf("The value of iptr is %i\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("The address pointed to by iptr is %p\n", (void*) iptr);
     /*Print the address of iptr itself*/
     printf("The address of iptr itself is %p\n", (void*) &iptr);
     /*Change the value of iptr itself*/
     *iptr = 100;
}

int main(){
    srand(time(NULL));
    /*declare an integer x and initialize it randomly to a value in [0,10] */
    int x = rand() % 11;
    /*Print the address of x*/
    printf("The address of x before foo is called is %p\n", (void*) &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*Print the value of x*/
    printf("The value of x after foo is called is %i\n", x);
    /*Answer the question */
    /*Yes, the value of x is different than the value printed at first
    because fooA alters the value stored at the address held in iptr(which is the address of x),
    thereby changing the value of x*/
    return 0;


}
