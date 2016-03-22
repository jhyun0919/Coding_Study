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

/*	Demonstrate string to long function.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <string.h>

int main (void)
{
/*	Local Definitions */
	long   num;
	char  *ptr;

/*	Statements */
	num = strtol ("12345 Decimal constant: ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	num = strtol ("11001 Binary constant : ", &ptr, 2);
	printf("%s %ld\n", ptr, num);

	num = strtol ("13572 Octal constant  : ", &ptr, 8);
	printf("%s %ld\n", ptr, num);

	num = strtol (" 7AbC Hex constant    : ", &ptr, 16);
	printf("%s %ld\n", ptr, num);

	num = strtol ("11001 Base 0-Decimal  : ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	num = strtol ("01101 Base 0-Octal    : ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	num = strtol ("0x7AbC Base 0-Hex      : ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	num = strtol ("Invalid input    : ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	return 0;
}	/* main */

/*	Results:
	Decimal constant:  12345
	Binary constant :  25
	Octal constant  :  6010
	Hex constant    :  31420
	Base 0-Decimal  :  11001
	Base 0-Octal    :  577
	Base 0-Hex      :  31420
	Invalid input   :  0
*/
