/**************************************************************************
 File name:  listdriverpublic.c
 Author:     Computer Science, Pacific University
 Date:
 Class:
 Assignment:
 Purpose:
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../include/list.h"

/**************************************************************************
 Function: 	 	success

 Description: print a success message

 Parameters:	szStr - the message to print
 Returned:	 	none
 *************************************************************************/
static void success (char * szStr)
{
	printf ("SUCCESS: %s\n", szStr);
}

/**************************************************************************
 Function: 	 	failure

 Description: print a failure message

 Parameters:	szStr - the message to print
 Returned:	 	none
 *************************************************************************/
static void failure (char * szStr)
{
	printf ("FAILURE: %s\n", szStr);
	exit (EXIT_FAILURE);
}

/****************************************************************************
 Function: 	 	assert

 Description: if the expression is true, assert success; otherwise, assert
 	 	 	 	 	 	 	failure

 Parameters:	szStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void assert (bool bExpression, char *pTrue, char *pFalse)
{
	if (bExpression)
	{
		success (pTrue);
	}
	else
	{
		failure (pFalse);
	}
}
/**************************************************************************
 Function: 	 	printList

 Description: Prints a list of integers for debugging purposes.

 Parameters:	sTheList - the list of integers to be printed

 Returned:	 	none
 *************************************************************************/
static void printIntList (List sTheList)
{
  // TODO: write this
}
/**************************************************************************
 Function: 	 	printCharList

 Description: Prints a list of chars for debugging purposes.

 Parameters:	sTheList - the list of chars to be printed

 Returned:	 	none
 *************************************************************************/
static void printCharList (List sTheList)
{
  // TODO: write this
}
/**************************************************************************
 Function: 	 	main

 Description: test all the functionality of the list

 Parameters:	none
 Returned:	 	none
 *************************************************************************/

int main ()
{
	List sTheList;
	int i, intValue;
	int numValues;
	int count;
	char *szData = "CS300";
	char charValue;

	puts ("Driver Start");

	srand (12);

	// run everything twice so you call
	// create after terminate!
	for (count = 0; count < 2 ; ++count)
	{
		lstCreate (&sTheList);
		success ("List Created");

		assert( 0 == lstSize (&sTheList), "The list size is 0",
				"The list size is not 0");

		assert( lstIsEmpty (&sTheList), "The list is empty",
				"The list is not empty");

		numValues = 10;
		for (i = 0; i < numValues; ++i)
		{
			lstInsertAfter (&sTheList, &i, sizeof (int));

			if( i+1 != lstSize (&sTheList) )
			{
				assert( i+1 == lstSize (&sTheList), "The list size correctly sized",
					"The list size is wrong");
			}
		}

		lstFirst (&sTheList);

		for (i = 0; i < numValues; ++i)
		{
			lstPeek(&sTheList, &intValue, sizeof(int));
			if (i != intValue)
			{
				assert( i == intValue, "Peek returns the correct value (int)",
						"Peek return the incorrect value (int)");
			}
			lstNext (&sTheList);
		}

		assert( ! lstIsEmpty (&sTheList), "The list is NOT empty",
				"The list is empty");

		assert( numValues == lstSize (&sTheList), "The list size is 10 ",
				"The list size is not 10");

		// For debugging purposes only
		// printIntList (sTheList);

		lstTerminate (&sTheList);
	}


  // Part B
  /*
  lstCreate(&sTheList);
  i = 7;

	lstInsertAfter (&sTheList, &i, sizeof (int));
  i = 8;
  lstInsertAfter (&sTheList, &i, sizeof (int));
  i = 9;
  lstUpdateCurrent (&sTheList, &i, sizeof (int));

  i = 0;
  lstPeek(&sTheList, &i, sizeof(int));
 	assert( i == 9, "Current was updated",
				"Current was NOT updated");
  
  lstDeleteCurrent (&sTheList, &i, sizeof (int));

  i = 0;
  lstPeek(&sTheList, &i, sizeof(int));
 	assert( i == 7, "Delete worked",
				"Delete might not have worked");

  lstTerminate (&sTheList);

	lstCreate(&sTheList);
  i = 7;
	lstInsertBefore (&sTheList, &i, sizeof (int));
  i = 8;
  lstInsertBefore (&sTheList, &i, sizeof (int));
  lstFirst(&sTheList);
  i = 0;

  lstPeek(&sTheList, &i, sizeof(int));
 	assert( i == 8, "lstFirst is correct",
				"lstFirst is NOT correct");
  lstLast(&sTheList);
  i = 0;

  lstPeek(&sTheList, &i, sizeof(int));
 	assert( i == 7, "lstLast is correct",
				"lstLast is NOT correct");
  */
 
	puts ("Driver End");
	return EXIT_SUCCESS;
}
