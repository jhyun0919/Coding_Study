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

/*	This program reverses the case, that is,
	changes upper to lower and lower to upper
	   Written by:
	   Date: 
*/
#include <stdio.h>

#define CASE 5

int main (void)
{
/* Local Definitions */
	char  word [81];
	char *pStr = word;
	char  mask;

/* Statements */
	printf("Please enter a word: ");
	fgets (word, sizeof(word) - 1, stdin);
	printf("\nOriginal word: %s\n", word);

	mask = 1 << CASE;                  /* mask: 00100000 */
	while (*pStr != '\n') 
	   {
	    *pStr = *pStr ^ mask; 
	    pStr++;
	   } /* while */
	printf("Revised word : %s\n", word);

	return 0;
}	/* main */

/*	Results:
	Please enter a word: Computers

	Original word: Computers

	Revised word : cOMPUTERS
*/
