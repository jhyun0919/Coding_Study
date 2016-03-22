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

/*	Print number series from 1 to a user-specified limit 
	in the form of a rectangle.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int row;
	int col;
	int limit;

/*Statements */
	/* Read limit */
	printf("\nPlease enter a number between 1 and 9: ");
	scanf("%d", &limit);

	for (row = 1; row <= limit; row++)
	   {
	    for (col = 1; col <= limit; col++)
	        if (row >= col)
	           printf("%d", col);
	        else
	           printf("*");
	    printf("\n");
	   } /* for row ... */

	return 0;
}	/* main */

/*	Results
	Please enter a number between 1 and 9: 6
	1*****
	12****
	123***
	1234**
	12345*
	123456
*/
