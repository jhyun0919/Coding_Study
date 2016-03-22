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

/*	This program calculates and prints the sum of 
	three numbers input by the user at the keyboard.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int  main  (void) 
{
/*	Local Definitions */
	int  a;
	int	 b;
	int  c;
	int	  sum;

/*	Statements */
	printf("\nWelcome. This program adds\n");
	printf("three numbers. Enter three numbers\n");
	printf("in the form: nnn nnn nnn <return>\n");

	scanf("%d %d %d", &a, &b, &c);

	/* Numbers are now in a, b, and c. Add them. */
	sum	 = a + b + c;

	printf("The total is: %d\n\n", sum);

	printf("Thank you. Have a good day.\n");
	return 0;
}	/*  main  */

/*	Results:
	Welcome. This program adds
	three numbers. Enter three numbers
	in the form: nnn nnn nnn <return>
	11 22 33
	The total is: 66
	
	Thank you. Have a good day.
*/
