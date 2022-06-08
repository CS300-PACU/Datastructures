/**************************************************************************
 File name:		  pqueue.h
 Author:        CS, Pacific University
 Date:          10/18/17
 Class:         CS300
 Assignment:    Priority Queue Implementation
 Purpose:       This file defines the constants, data structures, and
                function prototypes for implementing a priority queue data
                structure.
 *************************************************************************/

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <stdbool.h>
#include "../../ListADT/include/list.h"


//*************************************************************************
// User-defined types
//*************************************************************************

typedef struct PriorityQueueElement
{
	int priority;
	void* pData;
} PriorityQueueElement;
typedef PriorityQueueElement* PriorityQueueElementPtr;


typedef struct PriorityQueue *PriorityQueuePtr;
typedef struct PriorityQueue
{
	List sTheList;
} PriorityQueue;

//*************************************************************************
//										Allocation and Deallocation
//*************************************************************************
extern void pqueueCreate (PriorityQueuePtr psQueue);
// results: If PQ can be created, then PQ exists and is empty


extern void pqueueTerminate (PriorityQueuePtr psQueue);
// results: If PQ can be terminated, then PQ no longer exists and is empty

//*************************************************************************
//									Checking number of elements in priority queue
//*************************************************************************

extern int pqueueSize (const PriorityQueuePtr psQueue);
// results: Returns the number of elements in the PQ

extern bool pqueueIsEmpty (const PriorityQueuePtr psQueue);
// results: If PQ is empty, return true; otherwise, return false


//*************************************************************************
//									Inserting and retrieving values
//*************************************************************************

extern void pqueueEnqueue (PriorityQueuePtr psQueue, const void *pBuffer,
										int size, int priority);
// requires: psQueue is not full
// results: Insert the element into the priority queue based on the
//          priority of the element.

extern void *pqueueDequeue (PriorityQueuePtr psQueue, void *pBuffer,
														int size, int  *pPriority);

// requires: psQueue is not empty
// results: Remove the element from the front of a non-empty queue

//*************************************************************************
//													Peek Operations
//*************************************************************************

extern void *pqueuePeek (PriorityQueuePtr psQueue, void *pBuffer, int size,
								 int *priority);
// requires: psQueue is not empty
// results: The priority and value of the first element is returned through
//					the argument list
// IMPORTANT: Do not remove element from the queue

extern void pqueueChangePriority (PriorityQueuePtr psQueue,
																	int change);
// results: The priority of all elements is increased by the amount in

#endif /* PQUEUE_H_ */

