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

/*	Test driver for sequential list functions. This program
	included to complete testing of functions developed in
	Chapter 14.
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
NODE  *insertNode  (NODE  *pList,  NODE     *pPre, DATA  item);
NODE  *deleteNode  (NODE  *pList,  NODE     *pPre, NODE *pCur);
int    searchList  (NODE  *pList,  NODE    **pPre, 
                    NODE **pCur,   KEY_TYPE  target);
void   printList   (NODE  *pList);
double averageList (NODE *pList);
NODE  *buildSeq    (char  *fileID);
int    getData     (FILE  *fpData, DATA  *pData);

/*	Include Files for Functions         */
#include "P14-LINK.H"

int main (void)
{
/*	Local Definitions */
	NODE  *pList;
	NODE  *pPre;
	NODE  *pCur;
	DATA   data;
	double avrg;
	int    success;

/*	Statements */
	printf("Begin key-sequenced list functions\n\n");
	pList = NULL;
	
	/*	Build List */
	pList = buildSeq("P14CHRON.DAT");
	if (!pList)
	   {
	    printf("Error building key-sequenced file\a\n");
	    exit  (100);
	   } /* if */
	   
	printf("List Built\nContents: ");
	printList (pList);
	
	printf("\nInsert data tests.\n");
	printf("Enter first integer          : ");
	scanf ("%d", &data.key);
	do
	   {
	    /* Determine insert position */
	    success = searchList (pList, &pPre, &pCur, data.key);
	    if (!success)
	        pList = insertNode(pList, pPre, data);
	    else
	        printf("Duplicate data.\a\n");
	        
	    printf("Enter an integer <-1> to stop: ");
	    scanf ("%d", &data.key);
	   } while (data.key != -1);
        
	printf("\nData Inserted\nContents: ");
	printList (pList);
	
	avrg = averageList(pList);
	printf("\nData average: %.1f\n", avrg);
	

	printf("\nKey-sequenced tests complete.\n");
	return 0;
} /* main */

/*	==================== getData ====================
	Reads data from file.
	   Pre   fpData is an open file
	         pData is pointer to input structure
	   Post  data read
             returns success/failure
*/
int getData (FILE *fpData,
             DATA *pData)
{
/*	Local Definitions */
	int ioResult;

/*	Statements */
	ioResult = fscanf (fpData, "%d", &(pData->key));	
	if (ioResult == 1)
	   return 1;
	else
	   return 0;
}	/* getData */ 

/*	Results:
	Begin sequential list functions

	List Built
	Contents: 
	List contains:
	111 222 333 444 555 666 777 

	Insert data tests.
	Enter first integer          : 999
	Enter an integer <-1> to stop: 100
	Enter an integer <-1> to stop: 888
	Enter an integer <-1> to stop: 400
	Enter an integer <-1> to stop: 777
	Duplicate data.
	Enter an integer <-1> to stop: -1
	Data Inserted

	Contents: 
	List contains:
	100 111 222 333 400 444 555 666 777 888 
	999 

	Data average: 499.5

	Key-sequenced tests complete.
*/
