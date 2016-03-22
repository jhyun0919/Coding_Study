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

/*	Evaluate two complex expressions.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void)
{
/*	Local Definitions */
	int a = 3;
	int b = 4;
	int c = 5;
	int x;
	int y;

/*	Statements */
	printf("Initial values of the variables: \n");
	printf("a = %d\tb = %d\tc = %d\n\n", a, b, c);

	x = a * 4 + b / 2 - c * b;
	printf("Value of   a *  4 + b  / 2 - c   * b:  %d\n", x);

	y = --a * (3 + b) / 2 - c++ * b;
	printf("Value of --a * (3 + b) / 2 - c++ * b: %d\n", y); 
	printf("\nValues of the variables are now: \n");
	printf("a = %d\tb = %d\tc = %d\n\n", a, b, c);

	return 0;
}	/* main */

/*	Results:
	Initial values of the variables: 
	a = 3   b = 4   c = 5

	Value of   a *  4 + b  / 2 - c   * b:  -6
	Value of --a * (3 + b) / 2 - c++ * b: -13

	Values of the variables are now: 
	a = 2   b = 4   c = 6
*/
