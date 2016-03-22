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

/*	Nested if in two-way selection.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int a;
	int b;

/*	Statements */
	printf("Please enter two integers: ");
	scanf ("%d%d", &a, &b);

	if (a <= b) 
	   if (a < b)
	      printf("%d < %d\n", a, b);
	   else
	      printf("%d == %d\n", a, b);
	else
	   printf("%d > %d\n", a, b);
	return 0;
}	/* main */

/*	Results:
	Please enter two integers: 10 10
	10 == 10
*/
