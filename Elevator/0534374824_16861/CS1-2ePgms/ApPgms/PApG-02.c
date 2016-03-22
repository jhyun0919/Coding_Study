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

 /*	Test driver for Program G-3
	   Written by:
	   Date:
*/
#include <stdio.h>

#define DEBUG 1
#define PRINT_INT(a) \
	 printf("The variable '" #a "' contains: %d\n", a);
	
int main (void)
{
/*	Local Definitions */
	int totalScore = 0;

/*	Statements */
	printf("DEBUG is %d\n\n", DEBUG);

#if (DEBUG)
	PRINT_INT (totalScore);
#endif

	printf("\nEnd of Test\n");
	return 0;
}	/* main */

/*	Results Test 1:
	DEBUG is 0


	End of Test
---------------------
	
	Results Test 2:
	DEBUG is 1

	The variable 'totalScore' contains: 0

	End of Test
*/
