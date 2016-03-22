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

/*	Demonstrate the bitwise shift-right operator.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int num  = 64;
	int res;

/*	Statements */
	res =  num >> 1;

	printf("Original value: %3d\n", num);
	printf("Shifted right 1:%3d\n", res);

	res =  num >> 2;
	printf("Shifted right 2:%3d\n", res);

	res =  num >> 4;
	printf("Shifted right 4:%3d\n", res);

	return 0;
}	/* main */

/*	Results:
	Original value:   64 
	Shifted 1 right:  32   (divide by  2) 
	Shifted 2 right:  16   (divide by  4) 
	Shifted 4 right:   4   (divide by 16)
*/
