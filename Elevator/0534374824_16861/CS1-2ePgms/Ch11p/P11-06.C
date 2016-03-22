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

/*	This program creates a text file from keyboard input.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
/*	Local Definitions */
	char  str[100];
	FILE *fpOut;
	
/*	Statements */
	if (!(fpOut = fopen ("P11-06.TXT", "w")))
	   {
	    printf("\aCould not open output file.\n");
	    
	     (100);
	   } /* (if) */
	while (fgets(str, sizeof (str), stdin))
	   fputs(str,  fpOut); 

	fclose (fpOut);
	return 0;
}	/* main */

/*	Results:
	Now is the time
	For all good students
	To come to the aid
	Of their school.^d

	P11-06.txt contents:
	Now is the time
	For all good students
	To come to the aid
	Of their school.
*/	
