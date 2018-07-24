/* CS261- Assignment 1 - Q.3*/
/* Name: Amy Sage
 * Date: 4/17/18
 * Solution description: sorted students based on their scores
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     struct student temp_students;
     for(int i = 0; i < n - 1; i++) //bubble
     {
         for(int k = 0; k < (n-1-i); k++)
         {
             if(students[k].score > students[k+1].score)
             {
                 temp_students = students[k];
                 students[k] = students[k+1];
                 students[k+1] = temp_students;
             }
         }
     }
}

int main(){
    /*Seed rand*/
    srand(time(NULL));
    /*Declare an integer n and assign it a value.*/
    int n = 5;
    /*Allocate memory for n students using malloc.*/
    struct student *array = (struct student*)malloc(sizeof(struct student)*n);
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    for(int i = 0; i < n; i++)
    {
      array[i].score = rand() % 101;
      int tempId = (rand() % n) + 1; //between 1 and n inclusive
      //check uniqueness
      int repeat = 1;
      while(repeat) {
        repeat = 0;
        for(int k = 0; k < n; k++)
        {
          if (array[k].id == tempId)
          {
            tempId = (rand() % n) + 1; //between 1 and n inclusive
            repeat = 1;
          }
        }
      }
      array[i].id = tempId;
    }
    /*Print the contents of the array of n students.*/
    printf("Unsorted student scores:\n");
    for(int i = 0; i < n; i++)
    {
      printf("ID: %i Score: %i\n", array[i].id, array[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(array, n);
    /*Print the contents of the array of n students.*/
    printf("Sorted student scores:\n");
    for(int i = 0; i < n; i++)
    {
      printf("ID: %i Score: %i\n", array[i].id, array[i].score);
    }
    free(array);
    return 0;
}

