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

/*	Demonstrate the use of fgets in a program
	   Written by: 
	   Date: 
*/
#include <stdio.h> 

int main (void) 
{
/*	Local Definitions */
	char str[81]; 

/*	Statements */
	printf("Please enter a string: ");
	fgets (str, sizeof (str), stdin); 
	printf("Here is your string: \n\t%s", str);
	return 0; 
}	/* main */ 

/*	Results:
	Please enter a string: Now is the time for all students
	Here is your string:
		 Now is the time for all students
*/
