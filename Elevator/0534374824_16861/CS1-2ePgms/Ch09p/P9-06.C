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

/*	Show how pointers to pointers can be used by different 
	scanf functions to read data to the same variable.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void) 
{
/*	Local Definitions */
	int    a; 
	int   *p; 
	int  **q; 
	int ***r;

/*	Statements */
	p = &a; 
	q = &p; 
	r = &q;

	printf("Enter a number: ");
	scanf ("%d", &a); 
	printf("The number is : %d\n", a);

	printf("\nEnter a number: ");
	scanf ("%d", p); 
	printf("The number is : %d\n", a);

	printf("\nEnter a number: "); 
	scanf ("%d", *q); 
	printf("The number is : %d\n", a); 

	printf("\nEnter a number: "); 
	scanf ("%d", **r); 
	printf("The number is : %d\n", a); 

	return 0;
}	/* main */

/*	Results:
	Enter a number: 1
	The number is : 1

	Enter a number: 2
	The number is : 2

	Enter a number: 3
	The number is : 3

	Enter a number: 4
	The number is : 4
*/
