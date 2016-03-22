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

/*	Demonstrate while and do…while loops.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int loopCount;
	int testCount;

/*	Statements */
	loopCount = 1;
	testCount = 0;
	printf("while loop:       ");
	while (testCount++, loopCount <= 10) 
	   printf("%3d", loopCount++);
	printf("\nLoop Count:       %3d\n", loopCount);
	printf("Number of tests:  %3d\n", testCount);

	loopCount = 1;
	testCount = 0;
	printf("\ndo...while loop:  ");
	do
	   printf("%3d",    loopCount++);
	while (testCount++,  loopCount <= 10);

	printf("\nLoop Count:       %3d\n", loopCount);
	printf("Number of tests:  %3d\n", testCount);

	return 0;
}	/* main */

/*	Results:
	while loop:        1  2  3  4  5  6  7  8  9 10 
	Loop Count:       11
	Number of tests:  11

	do...while loop:   1  2  3  4  5  6  7  8  9 10
	Loop Count:       11
	Number of tests:  10
*/
