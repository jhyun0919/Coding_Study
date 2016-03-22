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

/*	This program merges two files
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define READ_MODE  "rb"
#define WRITE_MODE "wb"

int main (void)
{
/*	Local Definitions */
	FILE *fpM1;
	FILE *fpM2;
	FILE *fpOut;

	int recM1;
	int recM2;

	char file1ID[]   = "P13Mrg1.bin";
	char file2ID[]   = "P13Mrg2.bin";
	char fileOutID[] = "P13Mrg3.bin";
	int  sentinel    = INT_MAX;
	int  mergeCnt    = 0;

/*	Statements */
	printf("Begin File Merge:\n");
	if (!(fpM1 = fopen (file1ID, READ_MODE)))
	    printf("\aError on %s\n", file1ID), exit (100); 

	if (!(fpM2 = fopen (file2ID, READ_MODE)))
	    printf("\aError on %s\n", file2ID), exit (200); 

	if (!(fpOut = fopen (fileOutID, WRITE_MODE)))
	    printf("\aError on %s\n", fileOutID), exit (300); 

	fread (&recM1, sizeof(int), 1, fpM1);
	if (feof(fpM1)) 
	     recM1 = sentinel;
	fread (&recM2, sizeof(int), 1, fpM2);
	if (feof(fpM2)) 
	    recM2 = sentinel;

	while (!feof(fpM1) || !feof(fpM2))
	   {
	    if (recM1 <=  recM2)
	       {
	        fwrite (&recM1, sizeof(int), 1, fpOut); 
	        mergeCnt++;
	        fread  (&recM1, sizeof(int), 1, fpM1); 
	        if (feof(fpM1)) 
	           recM1 = sentinel;
	       } /* if */
	    else
	       {
	        fwrite (&recM2, sizeof(int), 1, fpOut);
	        mergeCnt++;
	        fread  (&recM2, sizeof(int), 1, fpM2);
	        if (feof(fpM2)) 
	           recM2 = sentinel;
	       } /* else */
	   } /* while */
	fclose (fpM1);
	fclose (fpM2);
	fclose (fpOut);
	printf("End File Merge. %d items merged.\n", mergeCnt);

	
/*	Following code added to verify output */
	printf("Merged Results: \n");
	if (!(fpM2 = fopen (fileOutID, READ_MODE)))
	    printf("\aError opening merged file: %s\n", fileOutID), exit (210); 
	while (!feof(fpM2))
	   {
	    fread  (&recM2, sizeof(int), 1, fpM2);
	    if (!feof(fpM2))
	        printf ("%d ", recM2);
	   } /* while */
	fclose (fpM2);
/*	End of added code */
	
	return 0;
}	/* main */

/*	Results:
	Begin File Merge:
	End File Merge. 14 items merged.
	Merged Results: 
	10 12 14 15 16 17 18 19 21 23 25 27 28 31 
*/
