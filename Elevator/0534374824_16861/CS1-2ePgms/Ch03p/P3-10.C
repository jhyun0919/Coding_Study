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

/*	Print rightmost digit of an integer.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int  intNum;
	int  oneDigit;
	
/*	Statements */
	printf("Enter an integral numbers: ");
	scanf ("%d", &intNum);
	
	oneDigit = intNum % 10;
	printf("\nThe right digit is: %d", oneDigit);
	
	return 0;
}	/* main */

/*	Results:
	Enter an integral numbers: 185

	The right digit is: 5
*/
