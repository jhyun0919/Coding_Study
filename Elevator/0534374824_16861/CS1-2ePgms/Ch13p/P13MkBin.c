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

/*	Makes binary file of integers.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
/*	Local Definitions */
	int   i;
	int   limit;
	char  fileID[20];
	FILE *fp;
	
/*	Statements */
	printf("Make binary file. How many integers: ");
	scanf ("%d", &limit);
	
	printf("File name: ");
	scanf ("%19s", fileID);
	
	printf("Starting number: ");
	scanf ("%d", &i);
	limit = limit + i;
	
	if (!(fp = fopen (fileID, "wb")))
	    printf("\aCan't open %s\n", fileID), exit (100);
	for ( ; i < limit; i++)
	    fwrite (&i, sizeof(int), 1, fp);
	
	fclose (fp);    
	printf("End of file creation");
	
	return 0;
}	/* main */
