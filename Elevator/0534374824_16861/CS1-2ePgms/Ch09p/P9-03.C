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

/*	This program adds two numbers using pointers to 
	demonstrate the concept of pointers.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void) 
{
/*	Local Definitions */
	int  a;
	int  b;
	int  r;
	int *pa = &a;
	int *pb = &b;
	int *pr = &r;

/*	Statements */
	printf("Enter the first number : "); 
	scanf("%d", pa); 
	printf("Enter the second number: "); 
	scanf("%d", pb);
	*pr = *pa + *pb; 
	printf("\n%d + %d is %d", *pa, *pb, *pr); 
	return 0;
}	/* main */

/*	Results:
	Enter the first number : 15
	Enter the second number: 51

	15 + 51 is 66
*/
