/**************************************************************************
 File name:		  queue.h
 Author:        CS, Pacific University
 Date:
 Class:         CS300
 Assignment:    Airport Simulation
 Purpose:       This file defines the constants, data structures, and
                function prototypes for implementing a queue data
                structure using your existing Priority Queue.
 *************************************************************************/


#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>
#include "../../PriorityQueueADT/include/pqueue.h"

//*************************************************************************
// User-defined types
//*************************************************************************
typedef struct Queue *QueuePtr;
typedef struct Queue
{
	PriorityQueue sTheQueue;
} Queue;

/**************************************************************************
*										Allocation and Deallocation
**************************************************************************/
extern void queueCreate (QueuePtr psQueue);
// results: If Q can be created, then Q exists and is empty

extern void queueTerminate (QueuePtr psQueue);
// results: If Q can be terminated, then Q no longer exists and is empty

/**************************************************************************
*									Checking number of elements in queue
**************************************************************************/
extern int queueSize (const QueuePtr psQueue);
// results: Returns the number of elements in the Q

extern bool queueIsEmpty (const QueuePtr psQueue);
// results: If Q is empty, return true; otherwise, return false

/**************************************************************************
*									Inserting and retrieving values
**************************************************************************/
extern void queueEnqueue (QueuePtr psQueue, const void *pBuffer, int size);
// requires: psQueue is not full
// results: Insert the element into the FIFO queue.

extern void *queueDequeue (QueuePtr psQueue, void *pBuffer, int size);
// requires: psQueue is not empty
// results: Remove the element from the front of a non-empty queue

/**************************************************************************
*													Peek Operations
**************************************************************************/
extern void *queuePeek (QueuePtr psQueue, void *pBuffer, int size);
// requires: psQueue is not empty
// results: The value of the first element is returned through the
//					argument list
// IMPORTANT: Do not remove element from the queue

#endif /* QUEUE_H_ */
