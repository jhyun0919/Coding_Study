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

/*	This program tests string directives
	   Written by: 
	   Date: 
*/
#include <stdio.h>
	
#define PRINT_INT(a) \
	 printf("The variable '" #a "' contains: %d\n", a);
	 
int main (void) 
{
/*	Local Declarations */
	int legalAge = 21;
	
/*	Statements */
	PRINT_INT (legalAge);
	 
	return 0;
}	/* main */

/*	Results:
	The variable 'legalAge' contains: 21
*/
