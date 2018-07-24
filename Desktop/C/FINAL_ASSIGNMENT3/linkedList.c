#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
list->frontSentinel = (struct Link *) malloc(sizeof(struct Link));
	assert(list->frontSentinel != 0);
	list->backSentinel = (struct Link *) malloc(sizeof(struct Link));
	assert(list->backSentinel);
	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;
	list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	struct Link *prev_link = link->prev;
	struct Link *new_link = (struct Link *) malloc(sizeof(struct Link));
	assert(list);
	new_link->value = value;
	new_link->next = link;
	new_link->prev = prev_link;
	link->prev = new_link;
	prev_link->next = new_link;
	list->size++;
	}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	struct Link *prev_link = link->prev;
	struct Link *next_link = link->next;
	assert(list);
	prev_link->next = next_link;
	next_link->prev = prev_link;
	free(link);
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDelistue = malloc(sizeof(struct LinkedList));
	init(newDelistue);
	return newDelistue;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the delistue.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the delistue.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the delistue.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the delistue.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the delistue.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the delistue.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the delistue is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	return list->size == 0;
}

/**
 * Prints the values of the links in the delistue from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
  assert(!linkedListIsEmpty(list));
  struct Link* tmp = list->frontSentinel->next;
  while(tmp != list->backSentinel) {
  printf("%d ", tmp->value);
  tmp = tmp->next;
  }
  printf("\n");
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	if(!linkedListIsEmpty(list))
	{
		struct Link *current = list->frontSentinel->next;
		while(current->next != NULL)
		{
			if(current->value == value)
			{
				return 1;
			}
			current = current->next;
		}
	}
	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	if (!linkedListIsEmpty(list)) {
		struct Link* currentLink = list->frontSentinel->next;
		while (currentLink->next != NULL) {
				if (currentLink->value == value) 
				{
					removeLink(list, currentLink); 
				}
					currentLink = currentLink->next;
			}
	}
}
