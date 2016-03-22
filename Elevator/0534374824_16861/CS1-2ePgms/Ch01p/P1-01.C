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

/*	This program reads two integer numbers from the 
	keyboard and prints their product.
	   Written by: 
	   Date: 
*/ 
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int number1;
	int number2;
	int result;

/*	Statements */
	scanf  ("%d", &number1); 
	scanf  ("%d", &number2);
	result = number1 * number2;
	printf ("%d", result);
	return 0;
}	/* main */

/*	Results
	5 3
	15
*/
