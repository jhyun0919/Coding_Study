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

/*	Test driver for iterative factorial.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <limits.h>

/*	Prototype Declarations */
long factorial (int n);

int main (void)
{
/*	Statements */
	printf("Factorial 6 is: %ld\n", factorial(6));
	return 0;
}	/* main */

/*	=================== factorial ===================
	Calculate the factorial of a number using a loop. 
	There is no test that the result fits in a long. 
	   Pre   n is the number to be raised factorially 
	   Post  result is returned 
*/
long factorial (int n)
{
/*	Local Definitions */
	int i;

	long factN;

/*	Statements */
	for (i = 1, factN = 1; i <= n; i++)
		factN = factN * i;

	return factN;
} /* factorial */


/*	Results:
	Factorial 6 is: 720
*/
