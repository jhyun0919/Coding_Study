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

/*	Print the number and sum of digits in an integer.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int number;
	int count = 0;
	int sum = 0;

/*	Statements */
	printf("\nEnter an integer: ");
	scanf("%d", &number);
	printf("Your number is:   %d\n\n", number);

	while (number != 0)
	   {
	    count++;
	    sum +=  number % 10;
	    number /= 10;
	   } /* while */

	printf("The number of digits is:  %3d\n", count);
	printf("The sum of the digits is: %3d\n", sum);

	return 0;
}	/* main*/

/*	Results:
	Enter an integer: 12345
	Your number is:   12345

	The number of digits is:    5
	The sum of the digits is:  15
*/
