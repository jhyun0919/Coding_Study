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

/*	Test driver for reading strings
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{	/* Read Month */
	#define FLUSH while (getchar() != '\n')
	char month[10];

	printf("Please enter a month. ");
	scanf("%9s", month); 
	FLUSH; 
	/* Read Month*/

	printf("You entered |%s|\n", month);	
	
	return 0;
}	/* main */

/*	Results:
	Please enter a month. September
	You entered |September|
*/
