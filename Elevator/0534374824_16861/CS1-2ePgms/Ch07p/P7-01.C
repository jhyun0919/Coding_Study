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

/*	This program fragment does nothing. It was slightly
	modified from the text program to make it executable.
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
FILE *fpTemps;

/*	Statements */
	
	if ((fpTemps = fopen("TEMPS.DAT", "r")) == NULL)
	   {
	    printf("\aERROR opening TEMPS.DAT\n");
	    return (100);
	   } /* if open */
	
	if (fclose(fpTemps) == EOF)
	   {
	    printf("\aERROR closing TEMPS.DAT\n");
	    return (102);
	   } /* if close */
	
	return 0;
}	/* main */

/*	Results if file not present:
	ERROR opening TEMPS.DAT
*/
