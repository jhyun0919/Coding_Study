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

/*	This program demonstrates that one function can be called
	multiple times.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Declarations */
void printOne (int x);

int main (void)
{
/*	Local Definitions */
	int a;

/*	Statements */
	/* First call */
	a = 5;
	printOne (a);
	
	/* Second call */
	a = 33;
	printOne (a);

	/* Done. Return to operating system. */
	return 0;
}	/* main */

/*	=================== printOne ===================
	Print one integer value.
	   Pre   x contains number to be printed
	   Post  value in x printed
*/
void printOne (int x)
{
/*	Statements */
	printf("%d\n", x);
	return;
}	/* printOne */

/*	Results:
	5
	33
*/
