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

/*	Test driver for sumEOF.
	   Written by:
	   Date:
*/
#include <stdio.h>

/*	Prototype Declarations */
int sumEOF (void);

int main (void)
{
/*	Statements */
	printf("\n\nThe sum is %d\n", sumEOF());
	return 0;
}	/* main */

/*	======================== sumEOF =======================
/*	Read a series of numbers, terminated by EOF, and return 
	their sum to the calling program.
	   Pre   nothing
	   Post  data read from standard input and sum returned
*/
int sumEOF (void)
{
/*	Local Definitions */
	int nmbr;
	int sum;

/*	Statements */
	sum = 0;
	printf ("\nPlease enter an integer:    ");

	while (scanf("%d", &nmbr) != EOF)
	   {
	    sum += nmbr;
	    printf("Next integer <EOF> to stop: ");
	   } /* while */
	return sum;
}	/* sumEOF */

/*	Results:
	
	Please enter an integer:    1
	Next integer <EOF> to stop: 2
	Next integer <EOF> to stop: 3
	Next integer <EOF> to stop: ^d

	The sum is 6
*/
