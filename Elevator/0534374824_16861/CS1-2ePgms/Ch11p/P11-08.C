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

/*	Write file double spaced.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
/*	Local Definitions */
	char  strng[81]; 
	FILE *textIn;

/*	Statements */
	if (!(textIn = fopen("P11-06.TXT", "r")))
	   {
	    printf("\aCan't open textdata\n");
	    exit (100);
	   } /* if */
	while (fgets(strng, sizeof(strng), textIn)) 
	   {
	    fputs(strng, stdout);
	    putchar ('\n'); 
	   } /* while */

	return 0;
}	/* main */

/*	Results:
	Now is the time

	for all good students

	to come to the aid

	of their school.
*/
