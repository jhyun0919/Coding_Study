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

/*	This program prints out a Fibonacci series.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Statements */
	long fib (long num);

int main (void)
{
/*	Local Definitions */
	int looper;
	int seriesSize;

/*	Statements */
	printf("This program prints a Fibonacci series.\n");
	printf("How many numbers do you want? ");
	scanf ("%d", &seriesSize);
	if (seriesSize < 2)
	   seriesSize = 2;

	printf("First %d Fibonacci numbers: \n", seriesSize);
	for (looper = 0; looper < seriesSize; looper++)
	   {
	    if (looper % 5)
	        printf(", %8ld", fib(looper));
	    else
	        printf("\n%8ld", fib(looper));
	   }
	printf("\n");
	return 0;
}	/* main */

/*	================= fib ===================
	Calculates the nth Fibonacci number. 
	   Pre   num identifies Fibonacci number 
	   Post  returns nth Fibonacci number 
*/
long fib (long num)
{
/*	Statements */
	if (num == 0 || num == 1)
	   /* Base Case */
	   return num;
	
	return (fib (num - 1) + fib (num - 2));
}	/* fib */

/*	Results:
	This program prints a Fibonacci series.
	How many numbers do you want? 33
	First 33 Fibonacci numbers:

	       0,        1,        1,        2,        3
	       5,        8,       13,       21,       34
	      55,       89,      144,      233,      377
	     610,      987,     1597,     2584,     4181
	    6765,    10946,    17711,    28657,    46368
	   75025,   121393,   196418,   317811,   514229
	   832040,  1346269,  2178309
*/
