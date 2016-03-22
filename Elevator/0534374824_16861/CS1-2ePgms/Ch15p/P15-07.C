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

/*	Changes lowercase characters in words to uppercase.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define CASE 5

int main (void)
{
/*	Local Definitions */
	char  word[81];
	char *pStr = word;
	char  mask;

/*	Statements */
	printf("Please enter a word (alpha characters only)\n"); 
	fgets (word, sizeof(word) - 1, stdin);
	printf("\nOriginal string: %s\n", word);

	mask = 1 << CASE;
	mask = ~mask;                        /* mask 11011111 */

	while (*pStr != '\n')
	   {
	    *pStr =  *pStr & mask;
	    pStr++;
	   } /* while */

	printf("Modified string: %s\n", word);
	return 0;
}	/*main */

/*	Results
	Please enter a word (alpha characters only)
	computers

	Original string: computers

	Modified string: COMPUTERS
*/
