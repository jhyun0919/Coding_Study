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

/*	This program fills the diagonal of a matrix (square 
	array) with 0, the lower left triangle with -1, and the 
	upper right triangle with 1.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int table [6][6];
	int row;
	int column;

/*	Statements */
	for (row = 0; row < 6; row++)
	   for (column = 0; column < 6; column++)
	      if (row ==  column)
	          table [row][column] = 0;
	      else if (row > column)
	          table [row][column] = -1;
	      else
	          table [row][column] = 1;

	for (row = 0; row < 6; row++)
	   {
	    for (column = 0; column < 6; column++)
	       printf("%3d", table[row][column]);
	    printf("\n");
	   } /* for row */
	return 0;
}	/* main */

/*	Results
	  0  1  1  1  1  1
	 -1  0  1  1  1  1
	 -1 -1  0  1  1  1
	 -1 -1 -1  0  1  1
	 -1 -1 -1 -1  0  1
	 -1 -1 -1 -1 -1  0
*/
