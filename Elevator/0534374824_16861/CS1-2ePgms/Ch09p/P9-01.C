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

/*	Demonstrate pointer use
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int		main (void) 
{
/* Local Definitions */
	int  a;
	int *p;

/*	Statements */
	a = 14;
	p = &a;

	printf("%d %p\n", a, &a);
	printf("%p %d %d\n", 
	         p, *p, a);

	return 0;
}	/* main */

/*	Results: You will get different addresses.

	14 00135760
	00135760 14 14
*/
