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

/*	Test driver for smallestEOF.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <limits.h>

/*	Prototype Declarations */
int smallestEOF (void);

int main (void)
{
/*	Statements */
	printf("\n\nSmallest is %d\n", smallestEOF());
	return 0;
}	/* main */

/*	======================== smallestEOF =======================
/*	Read a series of numbers, terminated by EOF, and 
	pass the smallest to the calling program. 
	   Pre   nothing 
	   Post  data read and smallest returned 
*/
int smallestEOF (void)
{
/*	Local Definitions */
	int numIn;
	int smallest;

/*	Statements */
	smallest = INT_MAX;        /* requires <limits.h> */

	printf("\nPlease enter an integer: ");

	while (scanf("%d", &numIn) != EOF)
	   {
	    if (numIn < smallest)
	        smallest = numIn;
	    printf("Enter next integer <EOF> to stop: ");
	   } /* while */
	return smallest;
}	 /* smallestEOF */

/*	Results:
	
	Please enter an integer: 18
	Enter next integer <EOF> to stop: 21
	Enter next integer <EOF> to stop: 7
	Enter next integer <EOF> to stop: 53
	Enter next integer <EOF> to stop: -2
	Enter next integer <EOF> to stop: 18
	Enter next integer <EOF> to stop: 
	
	Smallest is -2
*/
