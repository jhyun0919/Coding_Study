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

/*	Demonstrate the results of logical operators.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int a = 5;
	int b = -3;
	int c = 0;

/*	Statements */ 
	printf(" %2d &&  %2d is %2d\n", a, b,  a &&  b);
	printf(" %2d &&  %2d is %2d\n", a, c,  a &&  c);
	printf(" %2d &&  %2d is %2d\n", c, a,  c &&  a);
	printf(" %2d ||  %2d is %2d\n", a, c,  a ||  c);
	printf(" %2d ||  %2d is %2d\n", c, a,  c ||  a);
	printf(" %2d ||  %2d is %2d\n", c, c,  c ||  c);
	printf("!%2d && !%2d is %2d\n", a, c, !a && !c);
	printf("!%2d &&  %2d is %2d\n", a, c, !a &&  c);
	printf(" %2d && !%2d is %2d\n", a, c,  a && !c);
	return 0;
}	/* main */

/*	Results:
	  5 &&  -3 is  1
	  5 &&   0 is  0
	  0 &&   5 is  0
	  5 ||   0 is  1
	  0 ||   5 is  1
	  0 ||   0 is  0
	! 5 && ! 0 is  0
	! 5 &&   0 is  0
	  5 && ! 0 is  1
*/
