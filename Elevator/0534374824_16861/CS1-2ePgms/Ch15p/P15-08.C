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

/*	Change uppercase to lowercase without 
	affecting any lowercase letters.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define CASE 5

int main (void)
{
/* Local Definitions */
	char string [81];
	char *pStr = string;
	char mask;

/* Statements */
	printf("Please enter a word with upper & lower case: ");
	fgets (string, sizeof(string) - 1, stdin);
	printf("Original string: %s\n", string);

	mask = 1 << CASE;                   /* mask 00100000 */
	while (*pStr != '\n')
	   {
	    *pStr  =  *pStr | mask;
	    pStr++;
	   } /* while */

	printf("Revised string:  %s\n", string);

	return 0;
}	/* main */

/*	Results
	Please enter a word with upper & lower case: cOmPuTErs

	Original string: cOmPuTErs

	Revised string:  computers
*/
