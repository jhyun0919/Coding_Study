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

/*	Shows some of the application of functions we have learned
	in this chapter. The program first creates a binary file 
	of integers. It then prints the file, first sequentially
	and then randomly using rand().
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
/*	Prototype Statements */
void buildFile   (FILE **fp);
void printFile   (FILE  *fp);
void randomPrint (FILE  *fp);

int main (void) 
{
/*	Local Definitions */
	FILE *fpData; 

/*	Statements */

	buildFile   (&fpData);
	printFile   (fpData);
	randomPrint (fpData);
	
	return 0;
}	/* main */

/*	=================== buildFile ===================
	Creates a disk file that we can process randomly.
	   Pre   nothing 
	   Post  file has been built 
*/
void buildFile (FILE **fpData) 
{
/*	Local Definitions */
	int  i;
	int  data;
	
/*	Statements */
	if (!(*fpData = fopen("SAMPLE.DAT", "w+b"))) 
	   {
	    printf("\aError opening file.\n"); 
	    exit (100);
	   } /* if open */
	for (i = 1; i <= 10; i++) 
	    {
	     data = i * i;
	     fwrite(&data, sizeof(int), 1, *fpData);
	    } /* for */
	return;
}	/* buildFile */

/*	=================== printFile ===================
	Prints the file starting at the first record.
	   Pre   fp is an open file 
	   Post  file has been printed 
*/
void printFile (FILE *fpData) 
{
/*	Local Definitions */
	int data;
	int recNum;
	
/*	Statements */
	recNum = 0;
	rewind(fpData);
	fread(&data , sizeof(int), 1, fpData);
	while (!feof(fpData))
	   {
	    printf("Record %2d: %3d\n", recNum++, data);
	    fread(&data, sizeof(int), 1, fpData);
	   } /* while */
	return;
}	/* printFile */

/*	=================== randomPrint =================== 
	This function randomly prints the file. Some data may
	be printed twice, depending on the random numbers
	generated.
	   Pre  fp is an open file 
	   Post Ten records have been printed
*/
void randomPrint (FILE *fpData) 
{
/*	Local Definitions */
	int data;
	int i;
	int randomSeek;

/*	Statements */
	printf("\n\nFile contents in random sequence.\n");
	for (i = 0; i < 10; i++)
	   {
	    randomSeek =  (rand () % 10);
	    fseek(fpData, sizeof(int) * randomSeek, SEEK_SET); 
	    fread(&data, sizeof(int), 1, fpData);
	    printf("Record %3d ==> %3d\n", randomSeek, data); 
	   } /* for */
	return;
}	/* randomPrint */

/*	Results:
	Record 0:   1
	Record 1:   4
	Record 2:   9
	Record 3:  16
	Record 4:  25
	Record 5:  36
	Record 6:  49
	Record 7:  64
	Record 8:  81
	Record 9: 100
	
	File contents in random sequence.
	Record   8 ==>  81
	Record   8 ==>  81
	Record   3 ==>  16
	Record   5 ==>  36
	Record   1 ==>   4
	Record   7 ==>  64
	Record   0 ==>   1
	Record   9 ==> 100
	Record   2 ==>   9
	Record   6 ==>  49	
*/
