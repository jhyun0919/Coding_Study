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

/*	Display the decimal value of selected characters,
	   Written by:
	   Date: 
*/
#include <stdio.h>
int main (void)
{
/*	Local Definitions */
	char A         = 'A';
	char a         = 'a';
	char B         = 'B';
	char b         = 'b';
	char Zed       = 'Z';
	char zed       = 'z';
	char zero      = '0';
	char eight     = '8';
	char NL        = '\n';       /* newline */
	char HT        = '\t';       /* horizontal tab */
	char VT        = '\v';       /* vertical tab */
	char SP        = ' ';        /* blank or space */
	char BEL       = '\a';       /* alert (bell). */
	char dblQuote  = '"';        /* double quote */
	char backSlash = '\\';       /* backslash itself */
	char oneQuote  = '\'';       /* single quote itself */

/*	Statements */
	printf("\nASCII for char 'A'  is: %d",  A);
	printf("\nASCII for char 'a'  is: %d",  a);
	printf("\nASCII for char 'B'  is: %d",  B);
	printf("\nASCII for char 'b'  is: %d",  b);
	printf("\nASCII for char 'Z'  is: %d",  Zed);
	printf("\nASCII for char 'z'  is: %d",  zed);
	printf("\nASCII for char '0'  is: %d",  zero);
	printf("\nASCII for char '8'  is: %d",  eight);
	printf("\nASCII for char '\\n' is: %d", NL);
	printf("\nASCII for char '\\t' is: %d", HT);
	printf("\nASCII for char '\\v' is: %d", VT);
	printf("\nASCII for char ' '  is: %d",  SP);
	printf("\nASCII for char '\\a' is: %d", BEL);
	printf("\nASCII for char '\"'  is: %d", dblQuote);
	printf("\nASCII for char '\\'  is: %d", backSlash);
	printf("\nASCII for char '\''  is: %d", oneQuote);

	return 0;
}	/* main */

/*	Results:
	ASCII for character 'A'  is: 65
	ASCII for character 'a'  is: 97
	ASCII for character 'B'  is: 66
	ASCII for character 'b'  is: 98
	ASCII for character 'Z'  is: 90
	ASCII for character 'z'  is: 122
	ASCII for character '0'  is: 48
	ASCII for character '8'  is: 56
	ASCII for character '\n' is: 10
	ASCII for character '\t' is: 9
	ASCII for character '\v' is: 11
	ASCII for character ' '  is: 32
	ASCII for character '\a' is: 7
	ASCII for character '"'  is: 34
	ASCII for character '\'  is: 92
	ASCII for character '''  is: 39
*/
