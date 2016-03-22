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

/*	Typewriter program: adds two spaces to the left margin & 
	writes line to file
	   Written by: 
	   Date: 
*/
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int main (void)
{
/*	Local Definitions */
	FILE *outFile;
	char  strng[81];

/*	Statements */
	if (!(outFile = fopen("P11-07.TXT", "w")))
	   {
	    printf("\aCould not open output file.\n");
	    exit (100);
	   } /* (if) */

	while (fgets(strng, sizeof(strng), stdin))
	   {
	    fputc(' ', outFile); 
	    fputc(' ', outFile); 
	    fputs(strng, outFile); 
	    if (strng[strlen(strng) - 1] != '\n')
	        fputs("\n", outFile);
	   } /* while */
	fclose (outFile);
	return 0;
}	/* main */

/*	Results:
	Now is the time
	for all good students
	to come to the aid
	of their school.^d

	P11-07.TXT contains:
	  Now is the time
	  for all good students
	  to come to the aid
	  of their school.
*/
