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

/*	Print number series from 1 to user-specified limit.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void)
{
/*	Local Definitions */
	int i;
	int limit;

/*	Statements */
	printf ("\nPlease enter the limit: ");
	scanf ("%d", &limit);
	for (i = 1; i <= limit; i++)
	   printf("\t%d\n", i);

	return 0;
}	/* main*/

/*	Results:
	Please enter the limit: 3
		 1
		 2
		 3
*/
