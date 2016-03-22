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

/*	Examine the effect of precedence on an expression.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int a = 10;
	int b = 20;
	int c = 30;

/*	Statements */
	printf ("a *  b + c  is: %d\n", a *  b + c);
	printf ("a * (b + c) is: %d\n", a * (b + c));
	return 0;
}	/* main */

/*	Results:
	a *  b + c  is: 230
	a * (b + c) is: 500
*/
