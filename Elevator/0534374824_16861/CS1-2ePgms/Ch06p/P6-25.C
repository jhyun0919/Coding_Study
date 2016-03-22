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

/*	Test driver for recursive factorial.
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

/*	=================== factorial ====================
	Calculate factorial of a number using recursion. 
	There is no test that the result fits in a long. 
	   Pre   n is the number being raised factorially 
	   Post  result is returned 
*/
long factorial (int n)
{
/*	Statements */
	if (n == 0)
	   return 1;
	else
	   return (n * factorial (n - 1));
} /* factorial */


/*	Results:
	Factorial 6 is: 720
*/
