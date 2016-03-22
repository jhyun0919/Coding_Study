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

/*	Demonstrate the inclusive OR operator
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include "makeBin16.h"

/*	Prototype Declarations */
char *makeBin16 (unsigned short dec, char *strNum);

int main (void)
{
/*	Local Definitions */
	char  strNum[17];
	short num1 = 0257;      /* Octal 0257--Binary 010101111 */ 
	short num2 = 0463;      /* Octal 0463--Binary 100110011 */ 
	short res;

/*	Statements */
	res = num1 | num2;

	printf("First Number : %s\n", makeBin16(num1, strNum)); 
	printf("Second Number: %s\n", makeBin16(num2, strNum)); 
	printf("OR Result    : %s\n", makeBin16(res,  strNum)); 

	return 0;
}	/* main */

/*	Run results:
	First Number : 0000000010101111
	Second Number: 0000000100110011
	OR Result    : 0000000110111111
*/
