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

/*	Test driver for printBin.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Declarations */
void printBin (int num);

int main (void)
{
/*	Statements */
	printBin(  8);
	printBin( 66);
	printBin(234);

	return 0;
}	/* main */

/*	==================== printBin ====================
	Print an integer as a binary number.
	   Pre   num contains a value
	   Post  num printed 
*/
void printBin (int num)
{
/*	Local Definitions */
	int   temp;
	int   i;
	int   spaceCnt;
	
/*	Statements */
	for (i  = sizeof(int) * 8 - 1, spaceCnt = 0; 
	     i >= 0;
	     i--, spaceCnt++)
	   {
	    temp  = num >> i;
	    temp &= 1;
	    if (spaceCnt == 4)
	       {
	        /* insert space */
	        printf(" %d", temp);
	        spaceCnt = 0;
	       } /* if */
	    else
	       printf("%d", temp);
	   } /* for */
	printf("\n");
	   
	return;
}	/* printBin */

/*	Results:
	16 bit integers:
	0000 0000 0000 1000
	0000 0000 0100 0010
	0000 0000 1110 1010

	32 bit integers:
	0000 0000 0000 0000 0000 0000 0000 1000
	0000 0000 0000 0000 0000 0000 0100 0010
	0000 0000 0000 0000 0000 0000 1110 1010
*/
