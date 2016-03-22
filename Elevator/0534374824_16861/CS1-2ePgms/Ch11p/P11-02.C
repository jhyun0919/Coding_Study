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

/*	Read and print second integer from each line.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int amount;

/*	Statements */
	printf("Enter <integer> <integer> <float>: ");
	while (fscanf(stdin, "%*d%d%*[^\n]", &amount) != EOF)
	   {
	    printf("Second integer: %d\n", amount);
	    printf("Enter <integer> <integer> <float>: ");
	   } /* while */
	
	printf("\nThank you\n");
	
	return 0;
}	/* main */

/*	Results:
	Enter <integer> <integer> <float>: 123 456 7.89
	Second integer: 456
	Enter <integer> <integer> <float>: 987 654 3.21
	Second integer: 654
	Enter <integer> <integer> <float>: ^d
	Thank you

*/
