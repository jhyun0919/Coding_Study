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

/*	Demonstrates the results of relational operators.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void)
{
/*	Local Definitions */
	int a = 5;
	int b = -3;

/*	Statements */ 
	printf(" %2d <  %2d is %2d\n", a, b,  a <  b);
	printf(" %2d == %2d is %2d\n", a, b,  a == b);
	printf(" %2d != %2d is %2d\n", a, b,  a != b);
	printf(" %2d >  %2d is %2d\n", a, b,  a >  b);
	printf(" %2d <= %2d is %2d\n", a, b,  a <= b);
	printf(" %2d >= %2d is %2d\n", a, b,  a >= b);
	return 0;
}	/* main */

/*	Results:
	5 <  -3 is  0
	5 == -3 is  0
	5 != -3 is  1
	5 >  -3 is  1
	5 <= -3 is  0
	5 >= -3 is  1
*/
