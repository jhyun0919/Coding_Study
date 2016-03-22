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

/*	Copy a text file of integers.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
/*	Local Definitions */
	FILE *fpIn;
	FILE *fpOut;
	int   numIn;
	int   closeResult;
	
/*	Statements */
	printf("Running file copy\n");
	fpIn = fopen("P7-03.DAT", "r");
	if (!fpIn)
	   {
	    printf("Could not open input file\a\n");
	    exit  (101);
	   } /* if open fail */
	
	fpOut = fopen("P7-04.DAT", "w");
	if (!fpOut)
	   {
	    printf("Could not open output file\a\n");
	    exit  (102);
	   } /* if open fail */

	while ((fscanf(fpIn, "%d", &numIn)) == 1)
	   fprintf(fpOut, "%d\n", numIn);
	
	closeResult = fclose(fpOut);
	if (closeResult == EOF)
	   {
	    printf("Could not close output file\a\n");
	    exit  (201);
	   } /* if close fail */
	
	printf("File copy complete\n");
	return 0;
}	/* main */

/*	Results:
	Running file copy
	File copy complete
*/
