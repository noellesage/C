/*
 * This is the file in which you'll write the functions required to 
implement
 * a stack using two queues.  Make sure to add your name and 
@oregonstate.edu
 * email address below:
 *
 * Name: Amy Sage
 * Email: sageam@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TYPE int

int value = 0;
//****QUEUE data structures-- original given for linkedList implementation*****
struct link
{
   TYPE value;
   struct link *next;
};

struct listQueue
{
   struct link *firstLink;
   struct link *lastLink;
};

void listQueueInit(struct listQueue *q)
{
   struct link *lnk = (struct link *) malloc(sizeof(struct link));
   assert(lnk != 0); /* lnk is the sentinel */
   lnk->next = 0;
   q->firstLink = q->lastLink = lnk;
}


/*
 * This function creates a new queue. Parts of the create include 
allocating
 * the memory, initializing all of the values and returning a pointer to 
the newly
 * created queue.
 */
struct listQueue * listQueueCreate()
{
    struct listQueue *newNode = (struct listQueue *)malloc(sizeof(struct listQueue));
    newNode->firstLink = newNode->lastLink = NULL;
    return newNode;
	
}
void listQueueAddBack(struct listQueue *q, TYPE e)
{
   struct link *lnk = (struct link *) malloc(sizeof(struct link));
   assert(lnk != 0);      
   lnk->value = e;
   lnk->next = 0;
   q->lastLink->next = lnk; 
   q->lastLink = lnk;
}

int listQueueIsEmpty(struct listQueue *q)
{
   return q->firstLink == q->lastLink;
}

TYPE listQueueFront(struct listQueue *q)
{
   assert(!listQueueIsEmpty(q));
   return q->firstLink->next->value;
}

void listQueueRemoveFront(struct listQueue *q)
{
   struct link *lnk = q->firstLink->next;
   assert(!listQueueIsEmpty(q));
   if(q->firstLink->next->next == 0) 
   {
       q->lastLink = q->firstLink;
   }

   q->firstLink->next = lnk->next; 
   free(lnk);
}


struct linkedListStack
{
   struct listQueue * q1;
   struct listQueue * q2;
   int size;
};


void linkedListStackInit(struct linkedListStack * s)
{
   s->size = 0;

   s->q1 = (struct listQueue *) malloc(sizeof(struct listQueue));
   s->q2 = (struct listQueue *) malloc(sizeof(struct listQueue));  
 
   listQueueInit(s->q1);      

   listQueueInit(s->q2);  
}

/*
* This function creates the linked list stack. It allocates the memory and 
calls the
* initialization function to initialize all of the values. It then returns 
the stack.
*/
struct linkedListStack * linkedListStackCreate(){
    struct linkedListStack* newNode = malloc(sizeof(struct linkedListStack));
    linkedListStackInit(newNode);
    return newNode;

}


void linkedListStackFree(struct linkedListStack *s)
{  
   s->size = 0;
   free(s->q1);
   free(s->q2);  
}

void linkedListStackPush(struct linkedListStack *s, TYPE d)
{  

   listQueueAddBack(s->q2, d);
   while(!listQueueIsEmpty(s->q1))
   {
       listQueueAddBack(s->q2, listQueueFront(s->q1));
       listQueueRemoveFront(s->q1);
   }

   struct listQueue *q = s->q1;
   s->q1 = s->q2;
   s->q2 = q;
   s->size++;
}


TYPE linkedListStackTop(struct linkedListStack *s)
{
   if(listQueueIsEmpty(s->q1))
   {
       return -1;
   }
   TYPE value = listQueueFront(s->q1);
   return value;
}

void linkedListStackPop(struct linkedListStack *s)
{
   if(listQueueIsEmpty(s->q1))
       return;
   listQueueRemoveFront(s->q1);
   s->size--;  
}

int linkedListStackIsEmpty(struct linkedListStack *s)
{
   return (s->size == 0);
}

/*
 * Main is used to test the stack ADT.
 */
int main(int argc, char* argv[])
{
	struct linkedListStack *stack = linkedListStackCreate();

	//Test Stack
	//Push 4 values onto the stack
	printf("Pushing the value: 1\n");
	linkedListStackPush(stack, 1);
	printf("Pushed.\n\n");

	printf("Pushing the value: 2\n");
	linkedListStackPush(stack, 2);
	printf("Pushed.\n\n");

	printf("Pushing the value: 3\n");
	linkedListStackPush(stack, 3);
	printf("Pushed.\n\n");

	printf("Pushing the value: 4\n");
	linkedListStackPush(stack, 4);
	printf("Pushed.\n\n");



	//Print value at the top and then remove it
	printf("Value at the top of stack %d now being popped. \n",linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	printf("Value at the top of stack: %d now being popped. \n", linkedListStackTop(stack));  
	linkedListStackPop(stack);
	printf("Value popped.\n\n");

	//Try to pop when the stack is empty prints error:
	printf("Trying to pop empty stack:\n");

	linkedListStackPop(stack);

	
	//Push and Pop alternating
	printf("Pushing the value: 10\n");
	linkedListStackPush(stack, 10);
	printf("Pushed.\n\n");

	printf("Pushing the value: 11\n");
	linkedListStackPush(stack, 11);
	printf("Pushed.\n\n");

	printf("One more pop:\n");
	linkedListStackPop(stack);
	printf("Value at the top of stack: %d\n", 
linkedListStackTop(stack));

	linkedListStackFree(stack);

	return 0;

}




