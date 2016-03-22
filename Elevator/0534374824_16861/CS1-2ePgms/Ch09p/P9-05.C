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

/*	This program shows how we can use different pointers 
	to point to the same data variable. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void) 
{
/*	Local Definitions */
	int  a;
	int *p = &a; 
	int *q = &a; 
	int *r = &a; 

/*	Statements */
	printf("Enter a number: ");
	scanf ("%d", &a); 
	printf("\n%d ", *p); 
	printf("\n%d ", *q); 
	printf("\n%d ", *r); 

	return 0;
}	/* main */

/*	Results:
	Enter a number: 15

	15 
	15 
	15 
*/
