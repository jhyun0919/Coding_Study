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

/*	This program extracts and adds the two least 
	significant digits of an integer.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	 Prototype Declarations */
int addTwoDigits (int num);
int firstDigit   (int num);
int secondDigit  (int num);

int main (void)
{
/*	Local Definitions */
	int  number;
	int  sum;

/*	Statements */
	printf("\nEnter an integer: ");
	scanf ("%d", &number);

	sum = addTwoDigits (number);
	printf ("\nSum of last two digits is: %d", sum);

	return 0;
}	/* main */

/* ================== addTwoDigits ================== 
	 Adds the first two digits of an integer.
	    Pre  num contains an integer
	    Post returns sum of two least significant digits
*/
int addTwoDigits (int number)
{
/*	Local Definitions */
	int  result;

/*	Statements */
	result = firstDigit(number) + secondDigit(number);
	return result;
}	/* addTwoDigits */

/* ================== firstDigit ================= 
	Extract the least significant digit of an integer.
	   Pre   num contains an integer
	   Post  Returns least significant digit.
*/
int firstDigit (int num)
{
/*	Statements */
	return (num % 10);
}	/* firstDigit */

/* ================= secondDigit ================= 
	Extract second least significant (10s) digit
	   Pre   num is an integer
	   Post  Returns digit in 10s position
*/
int secondDigit (int num)
{
/*	Local Definitions */
	int  result;

/*	Statements */
	result = (num / 10) % 10;
	return result;
}	/* secondDigit */

/*	Results:
 	1.	Enter an integer: 23

		Sum of last two digits is: 5

	2.	Enter an integer: 8

		Sum of last two digits is: 8
*/
