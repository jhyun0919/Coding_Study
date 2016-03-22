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

/*	Test driver for rotateRight.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include "makebin16.h"

/*	Prototype Declarations */
void rotateRight (int numIn, int *numOut, int numBits);
void printBin    (int num);

int main (void)
{
/*	Local Definitions */
	int num;
	
/*	Statements */
	printf      ("Before rotation: ");
	printBin    (234);
	rotateRight (234, &num, 4);

	printf      ("After rotation : ");
	printBin    (num);	

	return 0;
}	/* main */

/*	==================== rotateRight ====================
	Rotate integer numBits to the right.
	   Pre   numIn contains value to be rotated
	         numOut is address to received new num
	         numBits is number of bits to be rotated
	   Post  numOut contains rotated value
	         -or- if numBits invalid, zero 
*/
void rotateRight (int  numIn, 
                  int *numOut, 
                  int  numBits)
{
/*	Local Definitions */
	int   temp;
	
/*	Statements */
	if (numBits > sizeof(int) * 8)
	    *numOut = 0;
	else
	    {
	     temp    = numIn << sizeof(int) * 8 - numBits;
	     *numOut = numIn >> numBits;
	     *numOut = *numOut | temp;
	    } /* else */
	   
	return;
}	/* rotateRight */

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
	Before rotation: 0000 0000 0000 0000 0000 0000 1110 1010
	After rotation : 1010 0000 0000 0000 0000 0000 0000 1110
*/
