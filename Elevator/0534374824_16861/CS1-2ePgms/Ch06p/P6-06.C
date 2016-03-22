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

/*	Demonstrate while and do...while loops.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int loopCount;

/*	Statements */
	loopCount = 5;
	printf("while loop     : ");
	while (loopCount > 0)
	   printf ("%3d", loopCount--);
	printf("\n\n");

	loopCount = 5;
	printf("do...while loop: ");
	do
	   printf ("%3d", loopCount--);
	while (loopCount > 0);
	printf("\n");
	return 0;
}	/* main */

/*	Results
	while loop     :   5  4  3  2  1

	do...while loop:   5  4  3  2  1
*/
