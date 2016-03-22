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

/*	This program shows how the same pointer can point to 
	different data variables in different statements. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void) 
{
/*	Local Definitions */
	int  a;
	int  b;
	int  c;
	int *p;

/*	Statements */
	printf("Enter three numbers and key return: "); 
	scanf("%d %d %d", &a, &b, &c); 
	p = &a; 
	printf("\n%3d ", *p);
	p = &b;
	printf("\n%3d ", *p); 
	p = &c; 
	printf("\n%3d ", *p); 
	return 0;
}	/* main */

/*	Results:
	Enter three numbers and key return: 5 10 15

	  5 
	 10 
	 15 
*/ 
