/* CS261- Assignment 1 - Q.4*/
/* Name: Amy Sage
 * Date: 4/17/2018
 * Solution description: Convert underscore array to camel case
 */
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/

char toUpperCase(char ch){
    return ch-'a'+'A';
}

void camelCase(char* word){
    /*Convert to camelCase*/
    int i=0;
    while(word[i]!='\0')
    {
        //if underscore 
        if(word[i]=='_')
        {
            int j=i+1;
            //make next char uppercase
            word[j] = toUpperCase(word[j]);
            //move everything left
            while(word[j]!='\0')
            {
                word[j-1]=word[j];
                j++;
            }
            word[j-1]='\0';
        }
    i++;
    }
}

int main()
{
    /*Read the string from the keyboard */
    char array[100];
    printf("Enter a word: ");
    scanf("%s",array);
    int i=0;
    int valid=1;
    //check if valid string or not
    while(array[i]!='\0')
    {
        if((array[i]<'a' || array[i]>'z' ) && array[i]!='_' )
        {
            valid = 0;
            break;
        }
        i++;
    }
    //invalid string
    if(valid==0)
    {
        printf("Invalid array");
    }
    else //valid
    {
        camelCase(array);
        printf("%s",array);
    }
    return 0;

}

