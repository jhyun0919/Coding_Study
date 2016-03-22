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

/*	Read a text file of integers, and print the contents.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
/*	Local Definitions */
	FILE *fpIn;
	int   numIn;
	
/*	Statements */
	fpIn = fopen("P7-03.DAT", "r");
	if (!fpIn)
	   {
	    printf("Could not open file\a\n");
	    exit  (101);
	   } /* if open fail */
	
	while ((fscanf(fpIn, "%d", &numIn)) == 1)
	   printf("%d ", numIn);
	   
	return 0;
}	/* main */

/*	Results:
	1 2 3 4 5 6 7 8 9 10 
*/
