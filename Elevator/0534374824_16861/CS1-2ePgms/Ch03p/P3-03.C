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

/*	Example of postfix increment.
	   Written by:
	   Date:
*/
#include <stdio.h>
int main (void)
{
/*	Local Definitions */
	int a;

/*	Statements */
	a = 4;
	printf("value of a    : %2d\n", a);
	printf("value of a++  : %2d\n",   a++);
	printf("new value of a: %2d\n\n", a);
	return 0;
}	/* main */

/*	Results:
	value of a    :  4
	value of a++  :  4
	new value of a:  5
*/
