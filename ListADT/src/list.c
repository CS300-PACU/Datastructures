/**************************************************************************
 File name:		list.c
 Author:      
 Date:        
 Class:       
 Assignment:  
 Purpose:     
 *************************************************************************/

#include "../include/list.h"
#include <stdlib.h>
#include <stdio.h>

/****************************************************************************
 Function:    	processError

 Description: 	Print an error message to the screen and exit.
                DO NOT EDIT THIS FUNCTION
                DO NOT CALL DIRECTLY
                Invoke via reportError;

 Parameters:  	szFile - the filename that generated the error
                line - the line in the file that generated the error
 
 Returned:    	None
 ****************************************************************************/
void processError(const char* szFile, const int line)
{
  fprintf(stderr, "ERROR: %s: %d\n", szFile, line);
  fflush(NULL);
  exit(EXIT_FAILURE);
}
