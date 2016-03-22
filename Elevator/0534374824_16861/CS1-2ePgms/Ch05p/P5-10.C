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

/*	This program demonstrates the use of the character 
	classification functions found in the c-type library. 
	Given a character, it displays the highest classification   
	for the character.
	   Written by:
	   Date: 
*/

#include <stdio.h>
#include <ctype.h>

int main (void)
{
/*	Local Definitions */
	char charIn;
	
/*	Statements */
	printf("Enter a character to be examined: ");
	scanf ("%c", &charIn);
	
	if (islower(charIn))
	    printf("You entered a lowercase letter.\n");
	else if (isupper(charIn))
	    printf("You entered an uppercase character.\n");
	else if (isdigit(charIn))
	    printf("You entered a digit.\n");
	else if (ispunct(charIn))
	    printf("You entered a punctuation character.\n");
	else if (isspace(charIn))
	    printf("You entered a whitespace character.\n");
	else
	    printf("You entered a control character\n");

	return 0;
}	/* main */

/*	Results
	Enter a character to be examined: a
	You entered a lowercase letter.

	Enter a character to be examined: Z
	You entered an upper-case character.

	Enter a character to be examined: 5
	You entered a digit.

	Enter a character to be examined: $
	You entered a punctuation character.

	Enter a character to be examined: 	[tab]
	You entered a whitespace character.

	Enter a character to be examined:  [esc]
	You entered a control character
*/
