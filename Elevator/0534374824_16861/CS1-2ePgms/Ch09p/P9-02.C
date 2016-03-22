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

/*	Fun with pointers 
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
	int *q;
	int *r;

/*	Statements */
	a = 6;
	b = 2;
	p = &b;

	q = p;
	r = &c;

	p  = &a;
	*q = 8;

	*r = *p;

	*r = a + *q + *&c;

	printf("%d %d %d \n", 
	         a, b, c); 
	printf("%d %d %d", 
	        *p, *q, *r); 
	return 0;
}	/* main */

/*	Results:
	6 8 20 
	6 8 20
*/
