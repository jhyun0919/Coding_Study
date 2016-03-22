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

/*	Print numbers on a line.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int i;
	int j;

/*	Statements */
	for (i = 1; i <= 3; i++)
	   {
	    printf("Row %d: ", i);
	    for (j = 1; j<= 5; j++)
	         printf("%3d", j);
	    printf("\n");
	   } /* for i */
	return 0;
}	/* main */

/*	Results:
	Row 1:   1  2  3  4  5
	Row 2:   1  2  3  4  5
	Row 3:   1  2  3  4  5
*/
