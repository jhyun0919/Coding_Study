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

/*	Initialize array with square of index and print it.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#define ARY_SIZE 5

int main (void)
{
/*	Local Definitions */
	int i;
	int sqrAry[ARY_SIZE];

/*	Statements */
	for (i = 0; i < ARY_SIZE; i++) 
	   sqrAry[i] = i * i;

	printf("Element\tSquare\n");
	printf("=======\t======\n");
	for (i = 0; i < ARY_SIZE; i++)
	   printf("%5d\t%4d\n", i, sqrAry[i]);

	return 0;
}	/* main */

/*	Results:
	Element Square
	======= ======
	    0      0
	    1      1
	    2      4
	    3      9
	    4     16
*/
