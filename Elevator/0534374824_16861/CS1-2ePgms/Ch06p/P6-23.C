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

/*	Test driver for allPositiveEOF.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <limits.h>

#define TRUE   1
#define FALSE  0

/*	Prototype Declarations */
int allPositiveEOF (void);

int main (void)
{
/*	Local Definitions */
	int allPos;
	
/*	Statements */
	allPos = allPositiveEOF();
	if (allPos)
		printf("\nAll numbers were positive\n");
	else
		printf("\nAt least one number was not positive\n");
	return 0;
}	/* main */

/*	=================== allPositiveEOF ===================
/*	Read number series, and determine if all are positive.
	   Pre   nothing
	   Post  returns TRUE if all numbers greater than zero
	         returns FALSE if any numbers zero or less.
*/
int allPositiveEOF (void)
{
/*	Local Definitions */
	int allPositive = TRUE;
	int numIn;

/*	Statements */
	while (allPositive && (scanf("%d", &numIn) != EOF))
	   {
	    allPositive =  numIn > 0;
	   } /* while */
	return allPositive;
} /* allPositiveEOF */


/*	Results:
1.	1 2 3 4 5 6^d
	All numbers were positive

2.	1
	0

	At least one number was not positive
*/
