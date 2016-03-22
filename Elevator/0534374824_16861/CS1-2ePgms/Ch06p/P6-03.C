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

/*	Add a list of integers from the standard input unit 
	Written by: 
	Date: 
*/
#include <stdio.h>
int main (void)
{
/* Local Definitions */
	int x;
	int sum = 0;

	/* Statements */
	printf("Enter your numbers: <EOF> to stop.\n");
	while (scanf("%d", &x) != EOF)
	   sum += x;
	printf ("\nThe total is: %d\n", sum);
	return  0;
}	/* main */

/*	Results:
	Enter your numbers: <EOF> to stop
	15
	22
	3^d
	The total is: 40
*/
