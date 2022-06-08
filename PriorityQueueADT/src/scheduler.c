/**************************************************************************
 File name:  scheduler.c
 Author:     
 Date:
 Class:
 Assignment:
 Purpose:
 *************************************************************************/
#include "../include/pqueue.h"
#include <stdio.h>
#include <stdlib.h>

#define NUMB_PQS 2

typedef struct Process
{
  int processID;
} Process;


/****************************************************************************
 Function:    	addProc

 Description: 	Add a process to the PQ

 Parameters:  	psPQ - the PQ to add to
                procID - the process ID of the process
                runtime - the initial runtime of the process
 
 Returned:    	None
 ****************************************************************************/
void addProc(PriorityQueuePtr psPQ, int procID, int runtime)
{
 
}

/****************************************************************************
 Function:    	printProcess

 Description: 	Print a process to the screen

 Parameters:  	psProc - the process to print
                runtime - the runtime to print
 
 Returned:    	None
 ****************************************************************************/
void printProcess(Process *psProc, int runtime)
{
  printf("ProcessID: %d Runtime: %d", psProc->processID, runtime);
}

/****************************************************************************
 Function:    	printTop

 Description: 	Print the process on the top of the PQ

 Parameters:  	psPQ - the PQ 
 
 Returned:    	None
 ****************************************************************************/
void printTop(PriorityQueuePtr psPQ)
{
}

/****************************************************************************
 Function:    	runProcess

 Description: 	Run the process on the top of the PQ for the specified time
                Reinsert the process into the PQ with the new runtime

 Parameters:  	psPQ - the Priority Queue
                runtime - the runtime to add
 
 Returned:    	None
 ****************************************************************************/
void runProcess(PriorityQueuePtr psPQ, int runtime)
{

}

/****************************************************************************
 Function:    	terminateProcess

 Description: 	Terminate the process on the top of the PQ
                Remove the process from the PQ

 Parameters:  	psPQ - the Priority Queue

 Returned:    	None
 ****************************************************************************/
void terminateProcess(PriorityQueuePtr psPQ)
{
}

/****************************************************************************
 Function:    	boost

 Description: 	Add the specified runtime to all processes in the PQ

 Parameters:  	psPQ - the Priority Queue
                value - the runtime to add to all processes
 
 Returned:    	None
 ****************************************************************************/
void boost(PriorityQueuePtr psPQ, int value)
{
}

/****************************************************************************
 Function:    	emptyPQ

 Description: 	Call terminateProcess() for each process in the PQ

 Parameters:  	psPQ - the Priority Queue
 
 Returned:    	None
 ****************************************************************************/
void emptyPQ(PriorityQueuePtr psPQ)
{
}

/****************************************************************************
 Function:    	loadProcesses

 Description: 	Load processes from a file into the PQ.

 Parameters:  	psPQ - the PQ to add to
 
 Returned:    	None
 ****************************************************************************/
void loadProcesses(PriorityQueuePtr psPQ)
{
  FILE *pFile;
  int runtime;
  Process sProc;

  pFile = fopen("data/processes.dat","r");
	while(!feof(pFile))
	{
		fscanf(pFile, "%d %d",&sProc.processID, &runtime);

    // TODO: Add the process to the PQ!


	}
	fclose(pFile);
}

/****************************************************************************
 Function:    	main

 Description: 	Simulate a process scheduler!

 Parameters:  	None
 
 Returned:    	None
 ****************************************************************************/
int main()
{
  PriorityQueue sPQ;
  int i, value;
  int runtime, procID;
  FILE *pFile, *pActions;
  Process sProc;
  char action;

  pqueueCreate(&sPQ);
  loadProcesses(&sPQ);
  
  pActions = fopen("data/actions.dat","r");
	while(!feof(pActions))
	{
		fscanf(pActions, "%c",&action);

    switch(action)
    {
      case 'A':
        fscanf(pActions, "%d %d ", &procID, &runtime);
        addProc(&sPQ, procID, runtime);
        break;
      case 'B':
        fscanf(pActions, "%d", &value);
        boost(&sPQ, value);
        break;
      case 'P':
        printTop(&sPQ);
        break;
      case 'R':
        fscanf(pActions, "%d ", &runtime);
        runProcess(&sPQ, runtime);
        break;
      case 'T':
        terminateProcess(&sPQ);
        break;
    }
  }
  fclose(pActions);

  emptyPQ(&sPQ);

  return EXIT_SUCCESS;
  
}