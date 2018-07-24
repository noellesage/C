/* CS261- Assignment 1 - Q.1*/
/* Name: Amy Sage
 * Date: 4/17
 * Solution description: allocate array of students and find min, max, average of scores
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *stud = (struct student*)malloc(sizeof(struct student)*10);
     /*return the pointer*/
     return stud;
}

void generate(struct student* students){
     /*Generate random and unique ID and random scores for ten students,
     ID being between 1 and 10, scores between 0 and 100*/
     for(int i = 0; i < 10; i++)
     {
     students[i].score = rand() % 100;
     int tempId = (rand() % 10) + 1; //between 1 and n inclusive
    //check uniqueness
    int repeat = 1;
    while(repeat) 
    {
        repeat = 0;
        for(int k = 0; k < 10; k++)
        {
            if (students[k].id == tempId)
            {
                tempId = (rand() % 10) + 1; //between 1 and n inclusive
                repeat = 1;
            }
        }
    }
    students[i].id = tempId;
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (int i = 0; i < 10; i++)
    {
      printf("ID: %i Score: %i\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min, max, avg;
     max = students[0].score;
     min = students[0].score;
     for(int i = 0; i < 10; i++)
     {
       if(students[i].score > max)
       {
         max = students[i].score;
       }
       if(students[i].score < min)
       {
         min = students[i].score;
       }
       avg += students[i].score;
     }
     avg /= 10;
     printf("The minimum is: %i\n", min);
     printf("The maximum is: %i\n", max);
     printf("The average is: %i\n", avg);
}

void deallocate(struct student* stud){
     if(stud == NULL);
	{
	   return;
	}
     free(stud);
}

int main(){
    srand(time(NULL));
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
