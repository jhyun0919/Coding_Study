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

/*	Demonstrate automatic promotion of numeric types.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	char   aChar   = 'A';
	int    intNum  = 200;
	double fltNum  = 245.3;
	
/*	Statements */
	printf("aChar contains :  %c\n", aChar);
	printf("aChar numeric  :  %d\n", aChar);
	printf("intNum contains:  %d\n", intNum);
	printf("fltNum contains:  %f\n", fltNum);
	
	intNum = intNum + aChar;   /* aChar promoted to int   */
	fltNum = fltNum + aChar;   /* aChar promoted to float */

	printf("\nAfter additions...\n");
	printf("aChar numeric  :  %d\n", aChar);
	printf("intNum contains:  %d\n", intNum);
	printf("fltNum contains:  %f\n", fltNum);
	
	return 0;
}	/* main */

/*	Results:
	aChar contains :  A
	aChar numeric  :  65
	intNum contains:  200
	fltNum contains:  245.300000

	After additions...
	aChar numeric  :  65
	intNum contains:  265
	fltNum contains:  310.300000
*/
