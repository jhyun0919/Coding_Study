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
	FILE *fpAppnd;
	int   numIn;
	int   closeResult;
	
/*	Statements */
	printf("This program appends data to a file\n");
	fpAppnd = fopen("P7-05.DAT", "a");
	if (!fpAppnd)
	   {
	    printf("Could not open input file\a\n");
	    exit  (101);
	   } /* if open fail */
	
	printf("Please enter first number:  ");
	while ((scanf("%d", &numIn)) != EOF)
	   {
	    fprintf(fpAppnd, "%d\n", numIn);
	    printf("Enter next number or <EOF>: ");
	   } /* while */
	
	closeResult = fclose(fpAppnd);
	if (closeResult == EOF)
	   {
	    printf("Could not close output file\a\n");
	    exit  (201);
	   } /* if close fail */
	
	printf("\nFile append complete\n");
	return 0;
}	/* main */

/*	Results: (Two runs to see full effects of append.)
	This program appends data to a file
	Please enter first number:  1
	Enter next number or <EOF>: 2
	Enter next number or <EOF>: 3
	Enter next number or <EOF>:^d
	File append complete

	This program appends data to a file
	Please enter first number:  10
	Enter next number or <EOF>: 11
	Enter next number or <EOF>: 12
	Enter next number or <EOF>: ^d
	File append complete
*/
