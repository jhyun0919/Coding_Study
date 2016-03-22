/*	****************************************************************
	**  This program is provided to the professors and students   **
	**  using "Computer Science: A Structured Approach Using C,   **
	**  Second Edition." All reprints in any form must cite this  **
	**  copyright.                                                **
    **                                                            **
	**  Copyright(c) 2001 by Brooks/Cole                          **
	**  A division of Thomson Learning                            **
	****************************************************************
*/

/*	Test driver for chronological list functions.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

/*	Global Structures */
typedef int KEY_TYPE;
typedef struct
	{
	 KEY_TYPE key;
	} DATA;
typedef struct nodeTag
	{
	 DATA             data; 
	 struct nodeTag  *link; 
	} NODE;

/*	Prototype Declarations */
#include "P14-LINK.H"
#include "P14-getData.c"

int main (void)
{
/*	Local Definitions */
	NODE  *pList;
	NODE  *pPre;
	NODE  *pCur;
	DATA   data;
	double avrg;
	int    locn;
	int    success;
	char   more;

/*	Statements */
	printf("Begin chronological list functions\n\n");
	
	/*	Build List */
	pList = buildChron("P14CHRON.DAT");
	if (!pList)
	   {
	    printf("Error building chron file\a\n");
	    exit  (100);
	   } /* if */
	   
	printf("List Built\nContents: ");
	printList (pList);
	
	printf("\nInsert data tests.\n");
	printf("Enter first integer          : ");
	scanf ("%d", &data.key);
	do
	   {
	    printf("Enter location for data:       ");
	    scanf ("%d", &locn);
	    
	    /* Determine insert position */
	    success = seekNode (pList, &pPre, &pCur, locn);
	    if (success)
	        pList = insertNode(pList, pPre, data);
	    else
	        printf("Invalid location.\a\n");
	        
	    printf("Enter an integer <-1> to stop: ");
	    scanf ("%d", &data.key);
	   } while (data.key != -1);
        
	printf("\nData Inserted\nContents: ");
	printList (pList);
	
	avrg = averageList(pList);
	printf("\nData average: %.1f\n", avrg);
	
	printf("\nDelete data tests.\n");
	do
	   {
	    pList = deleteChron (pList);
	    printf("Delete another <Y/N>: ");
	    scanf (" %c", &more);
	   } while (more == 'Y' || more == 'y');
	   
	printList (pList);
	printf("\nChronological tests complete.\n");
	return 0;
} /* main */

/*	Results:
	Begin chronological list functions

	List Built
	Contents: 
	List contains:
	111 222 333 444 555 666 777 

	Enter first integer          : 3333
	Enter location for data:       33
	Invalid location.
	Enter an integer <-1> to stop: 999
	Enter location for data:       -1
	Enter an integer <-1> to stop: 400
	Enter location for data:       4
	Enter an integer <-1> to stop: 100
	Enter location for data:       1
	Enter an integer <-1> to stop: -1

	Data Inserted
	Contents: 
	List contains:
	100 111 222 333 400 444 555 666 777 999 
	
	Data average: 460.7
	
	Delete data tests.
	Enter position of node to be deleted: 33
	33 is an invalid location
	Delete another <Y/N>: Y
	Enter position of node to be deleted: 10
	Delete another <Y/N>: Y
	Enter position of node to be deleted: 5
	Delete another <Y/N>: y
	Enter position of node to be deleted: 1
	Delete another <Y/N>: n

	List contains:
	111 222 333 444 555 666 777 

	Chronological tests complete.
*/
