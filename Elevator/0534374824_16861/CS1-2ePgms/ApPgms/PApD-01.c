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

/*	Demonstrate circular nature of unsigned integer numbers.
	   Written by: 
	   Date:
*/
#include <stdio.h>
#include <limits.h>

int main (void)
{
/*	Local Definitions */
	unsigned int x = UINT_MAX;
	
/*	Statements */
	printf("Maximum value:     %u\n", x);
	
	x++;
	printf("Maximum value + 1: %u\n", x);
	
	x++;
	printf("Maximum value + 2: %u\n", x);

	return 0;
}	/* main */

/*	Results:
	16 bit integer
	Maximum value:      65535
	Maximum value + 1:  0
	Maximum value + 2:  1
	
	32 bit integer
	Maximum value:     4294967295
	Maximum value + 1: 0
	Maximum value + 2: 1
*/
