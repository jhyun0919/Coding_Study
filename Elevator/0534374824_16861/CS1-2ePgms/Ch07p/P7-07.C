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

/* This program creates a text file. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void)
{
/*	Local Definitions */
	FILE *fpText;
	int   c;
	int   closeStatus;

/*	Statements */
	printf("This program copies your input to a file.\n");
	printf("When you are through, enter <EOF>.\n\n");
	
	if (!(fpText = fopen("P7-07.DAT","w")))
	   {
	    printf("Error opening FILE1.DAT for writing");
	    return (1);
	   } /* if open */

	while ((c = getchar()) != EOF)
	   fputc(c, fpText);

	closeStatus = fclose(fpText);
	if (closeStatus == EOF)
	   {
	    printf("Error closing file\a\n");
	    return 100;
	   } /* if */
	
	printf("\n\nYour file is complete\n");
	return 0;
}	/* main */

/*	Results:
	This program copies your input to a file.
	When you are through, enter <EOF>.

	Now is the time for all good students
	To come to the aid of their college.^d

	Your file is complete
*/
