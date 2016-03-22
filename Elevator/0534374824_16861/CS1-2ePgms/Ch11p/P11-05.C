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

/*	Test driver for demonstration of put string
	   Written by: 
	   Date: 
*/
#include <stdio.h> 

int main (void) 
{
/*	Local Definitions */
	char str[] = "Necessity Is the Mother of Invention.";
	char *pStr = str; 

/*	Statements */
	puts(pStr); 
	puts(pStr + 13); 
	
	return 0; 
}	/* main */ 

/*	Results:
	Necessity Is the Mother of Invention
	the Mother of Invention.
*/
