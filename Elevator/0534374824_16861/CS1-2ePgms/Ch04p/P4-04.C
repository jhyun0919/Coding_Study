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

/*	This program prints the first digits of an integer 
	read from the keyboard 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	 Prototype Declarations */
	int firstDigit (int num);

int main (void)
{
/*	Local Definitions */
	int number;
	int digit;

/*	Statements */
	printf("Enter an integer: ");
	scanf ("%d", &number);

	digit = firstDigit (number);
	printf("\nLeast significant digit is: %d\n", digit);

	return 0;
}	/* main */

/* ================= firstDigit ================== 
 	This function extracts the least significant digit 
	of an integer.
	   Pre   num contains an integer
	   Post  Returns least significant digit.
*/
int firstDigit (int num)
{
/*	Statements */
	return (num % 10);
}	/* firstDigit */

/*	Results:
	Enter an integer: 27

	Least significant digit is: 7
*/
