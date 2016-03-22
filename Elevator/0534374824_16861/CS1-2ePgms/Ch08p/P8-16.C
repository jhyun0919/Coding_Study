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

/*	This program changes a two-dimensional array to the 
	corresponding one-dimensional array.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#define ROWS 2
#define COLS 5

int main (void)
{
/*	Local Definitions */
	int table [ROWS] [COLS] =
	   {
	    {00, 01, 02, 03, 04},
	    {10, 11, 12, 13, 14}
	   }; /* table */
	int line [ROWS * COLS];
	int row;
	int column;

/*	Statements */
	for (row = 0; row < ROWS; row++)
	   for (column = 0; column < COLS; column++)
	       line[row * COLS + column] = table[row][column]; 

	for (row = 0; row < ROWS * COLS; row++)
	    printf(" %02d ", line[row]);

	return 0;
}	/* main */

/*	Results:
	00  01  02  03  04  10  11  12  13  14 
*/
