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

/*	This program calculates the area and circumference 
	of a circle using PI as a defined constant.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#define PI  3.1416

int main (void)
{
/*	Local Definitions */
	float circ;
	float area;

	float radius;

/*	Statements */

	printf("\nPlease enter the value of the radius: ");
	scanf("%f", &radius);

	circ  = 2  * PI     * radius;
	area  = PI * radius * radius;

	printf("\nRadius is :        %10.2f", radius);
	printf("\nCircumference is : %10.2f", circ);
	printf("\nArea is :          %10.2f", area);

	return 0;
}	/* main */

/*	Results:
	Please enter the value of the radius: 23

	Radius is :             23.00
	Circumference is :     144.51
	Area is :             1661.91
*/
