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

/*	This program appends two binary files of integers.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
/*	Local Definitions */
FILE  *fp1;
FILE  *fp2;
int    data;
long   dataCount = 0;
char   fileID[13];

/*	Statements */
	printf("\nThis program appends two files.\n");
	printf("Please enter the file ID of the primary file: "); 
	scanf("%12s", fileID);
	if (!(fp1 = fopen (fileID, "ab")))
	    printf("\aCan't open %s\n", fileID), exit (100);

//	The following statement needs to be added.
	fseek(fp1, 0, 2);
	if (!(dataCount = (ftell (fp1))))
	   printf("\a%s has no data\n", fileID), exit (101); 
	dataCount /= sizeof(int);

	printf("Please enter the file ID of the second file: ");  
	scanf("%12s", fileID);
	if (!(fp2 = fopen (fileID, "rb")))
	   printf("\aCan't open %s\n", fileID), exit (110);

	while (fread (&data, sizeof(int), 1, fp2) == 1)
	   {
	    fwrite (&data, sizeof(int), 1, fp1);
	    dataCount++;
	   } /* while */

	if (! feof(fp2))
	   printf("\aRead Error. No output.\n"), exit (120); 

	fclose (fp1);
	fclose (fp2);

	printf("Append complete: %ld records in file\n",  
	        dataCount);
	return 0;
}	/* main */
