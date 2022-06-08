/**************************************************************************
 File name:  tinyDB.c
 Author:     
 Date:
 Class:
 Assignment:
 Purpose:
 *************************************************************************/

#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Part
{
  unsigned int partNumber;
  double price;
} Part;

/****************************************************************************
 Function:    	find

 Description: 	Find a part in the database

 Parameters:  	psTheList - the list to search
                partNumber - the part number to search for
                psItem - return the found part
 
 Returned:    	true if the part is found, false otherwise
 ****************************************************************************/
bool find(ListPtr psTheList, int partNumber, Part *psItem)
{
  bool bFound = false;

  return bFound;
}

/****************************************************************************
 Function:    	printPart

 Description: 	Print a part to the screen

 Parameters:  	psItem - the part to print
 
 Returned:    	None
 ****************************************************************************/
void printPart(const Part *psItem)
{
  printf("Part Number: %d\tPrice: $%.2f\n", psItem->partNumber, psItem->price);
}

/****************************************************************************
 Function:    	print

 Description: 	Find and print a part to the screen, or print an error

 Parameters:  	psTheList - the list to search
                partNumber - the part number to search for
 
 Returned:    	None
 ****************************************************************************/
void print(ListPtr psTheList, int partNumber)
{
  
}

/****************************************************************************
 Function:    	buy

 Description: 	Find a part and determine the cost of buying
                a quantity. Print a message the the screen

 Parameters:  	psTheList - the list to search
                partNumber - the part number to search for
                quantity - the quantity to buy
 
 Returned:    	None
 ****************************************************************************/
void buy(ListPtr psTheList, int partNumber, int quantity)
{
  
}

/****************************************************************************
 Function:    	listAll

 Description: 	Print all the parts on the screen

 Parameters:  	psTheList - the list to print
 
 Returned:    	None
 ****************************************************************************/
void listAll(ListPtr psTheList)
{
  
}

/****************************************************************************
 Function:    	delete

 Description: 	Delete a part from the list

 Parameters:  	psTheList - the list to delete from
                partNumber - the part number to delete
 
 Returned:    	None
 ****************************************************************************/
void delete(ListPtr psTheList, int partNumber)
{

}

/****************************************************************************
 Function:    	loadDB

 Description: 	Read a file and load parts into the list

 Parameters:  	psTheList - the list to load
 
 Returned:    	None
 ****************************************************************************/
void loadDB(ListPtr psTheList)
{
  FILE *pDB;
  Part sItem;

  pDB = fopen("data/items.dat","r");
	while(!feof(pDB))
	{
		fscanf(pDB, "%d %lf",&sItem.partNumber, &sItem.price);

    // TODO: INSERT PART INTO LIST
    
	}
	fclose(pDB);
}

/****************************************************************************
 Function:    	main

 Description: 	Load parts and process database actions

 Parameters:  	None
 
 Returned:    	EXIT_SUCCES
 ****************************************************************************/
int main()
{
  FILE *pActions;
  Part sItem;
  List sTheDB;
  char action;
  int partNumber;
  int quantity;

  lstCreate(&sTheDB);
  loadDB(&sTheDB);
  pActions = fopen("data/actions.dat","r");
	while(!feof(pActions))
	{
		fscanf(pActions, "%c",&action);

    switch(action)
    {
      case 'P':
        fscanf(pActions, "%d", &partNumber);
        print(&sTheDB, partNumber);
        break;
      case 'B':
        fscanf(pActions, "%d %d", &partNumber, &quantity);
        buy(&sTheDB, partNumber, quantity);
        break;
      case 'L':
        listAll(&sTheDB);
        break;
      case 'D':
        fscanf(pActions, "%d", &partNumber);
        delete(&sTheDB, partNumber);
        break;
    }
  }
  fclose(pActions);

  return EXIT_SUCCESS;
}
