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

/*	This program demonstrates three ways to use constants.
	   Written by:
	   Date:
*/
#include <stdio.h>
#define PI 3.1415926536

int main (void)
{
/* Local Definitions */
	const double pi = 3.1415926536;

/* Statements */
	printf("Defined constant PI: %f\n", PI);
	printf("Memory constant pi:  %f\n", pi);
	printf("Literal constant:    %f\n", 3.1415926536);
	return 0;
}	/* main */

/*	Results:
	Defined constant PI: 3.141593
	Memory constant pi:  3.141593
	Literal constant:    3.141593
*/
