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

/*	This program reads two integers and then prints the 
	quotient and remainder of the first number divided
	by the second.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Declarations */
	void divide  (int  dividend, int  divisor, 
	              int *quotient, int *remainder);
	void getData (int *dividend, int *divisor);
	void print   (int  quotient, int  remainder);

int main (void)
{
/*	Local Definitions */
int  dividend;
int  divisor;
int  quot;
int  rem;

/*	Statements */
	getData (&dividend, &divisor);
	divide  ( dividend,  divisor, &quot, &rem);
	print   ( quot,      rem);
	
	return 0;
} /* main */

/*	================== getData ==================
	This function reads two numbers into variables
	specified in the parameter list.
	   Pre   Nothing.
	   Post  Data read and placed in calling function.
*/
void getData  (int *dividend,
               int *divisor)
{
/*	Statements */
	printf("Enter two integers and return: ");
	scanf ("%d%d", dividend, divisor);
	return;
} /* getData */

/*	==================== divide ====================
	This function divides two integers and places the
	quotient/remainder in calling program variables
	   Pre   dividend & divisor contain integer values
	   Post  quotient & remainder calc’d
*/
void divide (int  dividend,
             int  divisor,
             int *quotient,
             int *remainder)
{
/*	Statements */
	*quotient  = dividend / divisor;
	*remainder = dividend % divisor;

	return;
}	/* divide */
/*	==================== print ====================
	This function prints the quotient and the remainder
	   Pre   quot contains the quotient 
	         rem contains the remainder 
	   Post  Quotient and remainder printed 
*/
void print (int quot,
            int rem)
{
/*	Statements */
	printf ("Quotient : %3d\n", quot);
	printf ("Remainder: %3d\n", rem);
	return;
}	/* print */
/*	=============== End of Program =============== */

/*	Results
	Enter two integers and return: 81 7
	Quotient :  11
	Remainder:   4
*/
