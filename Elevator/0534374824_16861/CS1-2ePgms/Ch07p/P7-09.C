/*	This program counts characters and lines in a program.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void)
{
/*	Local Definitions */
	int   curCh;
	int   preCh;
	int   countLn = 0;
	int   countCh = 0;
	FILE *fp1;

/*	Statements */
	if (!(fp1 = fopen("P7-08.DAT", "r")))
	   {
	    printf("Error opening P7-07.DAT for reading");
	    return (1);
	   } /* if open error */

	while ((curCh = fgetc(fp1)) != EOF)
	   {
	    if (curCh != '\n')
	        countCh++;
	    else
	        countLn++;
	    preCh = curCh;
	   } /* while */

	if (preCh != '\n')
	    countLn++;

	printf("Number of characters: %d\n", countCh);
	printf("Number of lines     : %d\n", countLn);

	fclose(fp1);

 return 0;
}  /* main*/

/*	Results:
	Number of characters: 73
	Number of lines     : 2
*/
