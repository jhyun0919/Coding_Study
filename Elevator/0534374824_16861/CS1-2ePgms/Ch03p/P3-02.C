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

/*	Demonstrate examples of compound assignments.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int x;
	int y;

/*	Statements */
	x = 10;
	y = 5;

	printf("x: %2d  |  y: %2d ",   x, y);
	printf("  |  x *= y: %2d ",    x *= y);
	printf("  |  x is now: %2d\n", x);

	x = 10;
	printf("x: %2d  |  y: %2d ",   x, y);
	printf("  |  x /= y: %2d ",    x /= y);
	printf("  |  x is now: %2d\n", x);

	x = 10;
	printf("x: %2d  |  y: %2d ",   x, y);
	printf("  |  x %%= y: %2d ",   x %= y);
	printf("  |  x is now: %2d\n", x);

	return 0;
}	/* main */

/*	Results:
	x: 10  |  y:  5   |  x *= y: 50   |  x is now: 50
	x: 10  |  y:  5   |  x /= y:  2   |  x is now:  2
	x: 10  |  y:  5   |  x %= y:  0   |  x is now:  0
*/
