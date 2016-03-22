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

/*	Demonstrates the generation of random numbers in 
	three different series:
	   03 and 07
	   20 and 50
	   -6 and 15
	After generating three numbers, it prints them.
	The seed for the series is 997.  
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
/*	Local Definitions */
	int  a;
	int  b;
	int  c;

/*	Statements */
	srand (997);
	/* range is 3 through 7 */
	a = rand () % 5  +  3;              /* 8 - 3 = 5 */

	/* range is 20 through 50*/
	b = rand () % 31 + 20;            /* 51 - 20 = 31 */

	/* range is -6 through 15*/
	c = rand () % 22  - 6;          /* 16 - (-6) = 22 */
	printf ("Range  3 to 7:  %2d\n", a);
	printf ("Range 20 to 50: %2d\n", b);
	printf ("Range -6 to 15: %2d\n", c);
	return 0;
}	/* main */

/*	Results:
	Range  3 to 7:   3
	Range 20 to 50: 34
	Range -6 to 15:  2
*/
