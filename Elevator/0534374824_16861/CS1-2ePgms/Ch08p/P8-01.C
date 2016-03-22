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

/*	Test driver for print ten numbers per line.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define MAX_SIZE 25

int main (void)
{
/*	Local Definitions */
	int i;
	int numPrinted;
	int list [MAX_SIZE];

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

/*	Statements */
	/* Initialize list */
	for (i = 0; i < MAX_SIZE; i++)
		list[i] = i * 3;


/*	Statements */

/*	a program fragment */
	numPrinted = 0;
	for (i = 0; i < MAX_SIZE; i++)
	   {
	    printf("%3d", list[i]);
	    if (numPrinted < 9)
	        numPrinted++;
	    else
	       {
	        printf("\n");
	        numPrinted = 0;
	        } /* else */
	   } /* for */
	
	return 0;
}	/* main */

/*	Results:
	  0  3  6  9 12 15 18 21 24 27
	 30 33 36 39 42 45 48 51 54 57
	 60 63 66 69 72
*/
