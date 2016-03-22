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

/*	Use a loop to print a number backward.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	long num;
	int  digit;
	
/*	Statements */
	printf("Enter a number and I'll print it backward: ");
	scanf ("%d", &num);
	
	while (num > 0)
	   {
	    digit = num % 10;
	    printf("%d", digit);
	    num   = num / 10;
	   } /* while */
	printf("\nHave a good day.\n");
	return 0;
}	/* main */

/*	Results:
	Enter a number and I'll print it backward: 12345678
	87654321
	Have a good day.
*/
