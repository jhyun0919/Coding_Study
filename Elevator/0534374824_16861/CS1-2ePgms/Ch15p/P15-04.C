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

/*	Demonstrate use of one's complement
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include "makeBin16.h"

/*	Prototype Declarations */
char *makeBin16 (unsigned short dec, char *strNum);

int main (void)
{
/* Local Definitions */
	char  str[17];
	short num = 0257;       /* Octal 0257--Binary 010101111 */ 
	short res;

/* Statements */
	printf("Original Num    : %s\n", makeBin16(num, str)); 
	res = ~num;

	printf("Complemented Num: %s\n", makeBin16(res, str)); 

	return 0;
} /* main */

/*	Results:
	Original Num    : 0000000010101111
	Complemented Num: 1111111101010000
*/
