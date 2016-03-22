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

/*	Add a list of integers from the standard input unit 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int x;
	int sum = 0;
	int testEOF;

	/* Statements */
	printf("Enter your numbers: <EOF> to stop.\n");
	do
	   {
	    testEOF = scanf("%d", &x);
	    if (testEOF != EOF)
	        sum += x;
	   } while (testEOF != EOF);
	printf ("\nTotal: %d\n", sum);
	return  0;
}	/* main */

/*	Results:
	Run 1:
	Enter your numbers: <EOF> to stop.
	10 15 20 25 ^d
	Total: 70

	Run 2:
	Enter your numbers: <EOF> to stop.
	^d
	Total: 0
*/
