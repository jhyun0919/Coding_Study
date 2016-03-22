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

/*	This program shows how to change a temperature in 
	Fahrenheit to Celsius
	   Written by:
	   Date:
*/
#include <stdio.h>

#define CONVERSION_FACTOR (100.0 / 180.0)

int main (void)
{
/*	Local Definitions */
	float cel;
	float fah;

/*	Statements */
	printf("Enter the temperature in Fahrenheit: ");
	scanf("%f", &fah);

	cel = CONVERSION_FACTOR * (fah - 32);

	printf("Fahrenheit temperature is: %5.1f\n", fah);
	printf("Celsius temperature is:    %5.1f\n", cel);

	return 0;
}	/* main */

/*	Results:
	Enter the temperature in Fahrenheit: 98.6
	Fahrenheit temperature is:  98.6
	Celsius temperature is:     37.0

*/
