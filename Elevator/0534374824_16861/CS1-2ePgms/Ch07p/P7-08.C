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

/*	This program copies one text file into another.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int		main (void) 
{
/*	Local Definitions */
	int   c;
	int   closeStatus;
	FILE *fp1;
	FILE *fp2;

/*	Statements */
	printf("Begin file copy\n");

	if (!(fp1 = fopen ("P7-07.DAT", "r")))
		{
		 printf("Error opening P7-07.DAT for reading");
		 return (1);
		} /* if open input */
	if (!(fp2 = fopen ("P7-08.DAT", "w")))
		{
		 printf("Error opening P7-08.DAT for writing");
		 return (2);
		} /* if open output */

	while ((c = fgetc(fp1)) != EOF)
		fputc(c, fp2);

	fclose(fp1);
	closeStatus = fclose(fp2);
	if (closeStatus == EOF)
	   {
	    printf("File close error.\a\n");
	    return 201;
	   } /* if close error */
	printf("File successfully created\n");
	return 0;
}	/* main */

/*	Results:
	Begin file copy
	File successfully created
*/
