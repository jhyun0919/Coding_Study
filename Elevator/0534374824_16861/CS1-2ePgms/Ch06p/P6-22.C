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

/*	Test driver for anyPositiveEOF.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <limits.h>

#define TRUE   1
#define FALSE  0

/*	Prototype Declarations */
int anyPositiveEOF (void);

int main (void)
{
/*	Local Definitions */
	int anyPos;
	
/*	Statements */
	anyPos = anyPositiveEOF();
	if (anyPos)
		printf("\nThere was at least one positive number\n");
	else
		printf("\nThere were no positive numbers\n");
	return 0;
}	/* main */

/*	=================== anyPositiveEOF ===================
	Read number series, and determine if any are positive.
	Pre   nothing 
	Post  returns TRUE if any numbers greater than zero
	      returns FALSE if all numbers negative or zero.
*/
int anyPositiveEOF (void)
{
/*	Local Definitions */
	int anyPositive = FALSE;
	int numIn;

/*	Statements */
	while (!anyPositive && (scanf("%d", &numIn) != EOF))
	   {
	    anyPositive  = numIn > 0;
	   } /* while */
	return anyPositive;
} /* anyPositiveEOF */


/*	Results
1.	0 -3 2 -7 -1^d
	There was at least one positive number
	
2.	-1 -2 -3 -4 0 -5^d
	There were no positive numbers
*/
