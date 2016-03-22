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

/*	This program demonstrates the two’s complement values.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int a = +13422;
	int b = -768;
	int ca;
	int cb;

/*	Statements */
	ca = ~ a;
	cb = ~ b;
	printf("The complement of %6d is %6d\n", a, ca);
	printf("The complement of %6d is %6d\n", b, cb);
	return 0;
}	/* main */

/*	Results:
	The complement of  13422 is -13423
	The complement of   -768 is    767
*/
