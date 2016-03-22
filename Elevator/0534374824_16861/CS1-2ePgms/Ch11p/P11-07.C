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

/*	Echo keyboard input that begins with a capital letter.
	   Written by: 
	   Date written: 
*/
#include <ctype.h>
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	char strng[81]; 

/*	Statements */
	while (fgets (strng, sizeof(strng), stdin)) 
	    if (isupper(*strng))
	        fputs(strng, stdout);
	return 0;
}	/* main */

/*	Results:
	Now is the time
	Now is the time
	for all good students
	to come to the aid
	of their school.
	Amen
	Amen
*/
