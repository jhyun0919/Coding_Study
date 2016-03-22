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

/*	This program demonstrates binary expressions.
	   Written by:
	   Date: 
*/
#include <stdio.h>
int main (void)
{
/*	Local Definitions */
	int a = 17;
	int b = 5;

/*	Statements */
	printf("%d + %d = %d\n",  a, b, a + b);
	printf("%d - %d = %d\n",  a, b, a - b);
	printf("%d * %d = %d\n",  a, b, a * b);
	printf("%d / %d = %d\n",  a, b, a / b);
	printf("%d %% %d = %d\n", a, b, a % b);
	printf("Hope you enjoyed the demonstration.\n");
	return 0;
}	/* main */

/*	Results:
	17 + 5 = 22
	17 - 5 = 12
	17 * 5 = 85
	17 / 5 = 3
	17 % 5 = 2
	Hope you enjoyed the demonstration.
*/
