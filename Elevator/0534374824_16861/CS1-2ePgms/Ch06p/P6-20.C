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

/*	Test driver for powers.
	   Written by:
	   Date:
*/
#include <stdio.h>

/*	Prototype Declarations */
int powers (int base, int exp);

int main (void)
{
/*	Statements */
	printf("2 power 3 is %d\n", powers(2, 3));
	return 0;
}	/* main */

/*	======================== powers =======================
/*	Raise base to an integral power, exp. If the 
	exponent is zero, return 1.
	   Pre   base & exp are both positive integer values 
	   Post  return either (a) the result of raising the  
	           base to the exp power
	         or (b) zero if the parameters are invalid
*/
int powers (int base ,
            int exp)
{
/*	Local Definitions */
	int i;
	int result;

/*	Statements */
	if (base < 1 || exp < 0)
	   /* Error Condition */
	   result = 0;
	else
	   for  (result = 1 , i = 1; i <= exp; i++)
	         result *= base;

	return result;
}	/* powers */

/*	Results:
	2 power 3 is 8
*/
