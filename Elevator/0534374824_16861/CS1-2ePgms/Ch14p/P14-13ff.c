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

/*	Creates an array of linked lists. Each list is read from 
	a file. After the lists have been created, they are 
	printed to verify that they were built properly.
	   Written by: 
	   Data: 
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "P14-DATA.H"
#include "P14-LINK.H"
#include "P14-getData.c"

#define NUM_LISTS 2 

/*	Prototype Declarations */
void buildAry (NODE **listArray, int numLists);
void printAry (NODE **listArray, int numLists);

int main (void)
{
/*	Local Definitions */
	NODE *listArray [NUM_LISTS]; 

/*	Statements */
	buildAry (listArray, NUM_LISTS);
	printAry (listArray, NUM_LISTS);
	
	return 0;
}	/* main */

/*	==================== buildAry ====================
	Read files with a sequential name of FILEn.DAT
	and put the contents of the file into linked lists pointed
	to by an array of pointers.
	   Pre   nothing 
	   Post  array of linked lists built 
*/
void buildAry (NODE **listArray,
               int    numLists)
{
/*	Local Definitions */
	int     row ;
	char    fileNum [3];
	char    filename[20]; 
	
/*	Statements */
	for (row = 0; row < numLists; row++)
	   {
	    /* Convert row to text number - open file */
	    strcpy (filename, "P14FILE");
	    sprintf(fileNum,  "%d", row + 1);
	    strcat (filename, fileNum); 
	    strcat (filename, ".DAT"); 
	 
	    listArray[row] = buildSeq (filename);
	   } /* for */
	return;
}	/* buildAry */

/*	==================== printAry ==================
	This function prints contents of lists in listArray.
	   Pre   listArray has been filled 
	         numLists is number of list pointers in array 
	   Post  lists printed, one after the other 
*/
void printAry (NODE **listArray, 
               int    numLists)
{
/*	Local Definitions */
	int row;
	
/*	Statements */

	for (row = 0; row < numLists; row++) 
	   printList (listArray [row]); 
	return;
}	/* printAry */
/*	================== End of Program ================== */

/*	Results:
	List contains:
	101 111 121 131 141 151 161 171 181 191

	List contains:
	202 212 222 232 242 252 252 272 282 292
*/