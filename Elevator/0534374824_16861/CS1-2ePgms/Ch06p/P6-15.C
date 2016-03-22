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

/*	Convert a binary number to a decimal number.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Definitions */
long getNum          (void);
long binaryToDecimal (long binary);
long powerTwo        (long num);
long firstDigit      (long num);
int  validateBinary  (long binary);

int main (void)
{
/*	Local Definitions */
	long binary;
	long decimal;

/*	Statements */
	binary   = getNum ();
	decimal  = binaryToDecimal (binary);
	printf("\nThe binary number was: %ld", binary);
	printf("\nThe decimal number is: %ld", decimal);
	return 0;
}	/* main*/

/*	==================== getNum ====================
	This function reads and validates a binary number from 
	the keyboard.
	  Pre   nothing
	  Post  a valid binary number is returned
*/
long getNum (void) 
{
/*	Local Definitions */
	int  isValid;
	long binary;

/*	Statements */
	do
	 {
	  printf("Enter a binary number (zeros and ones): ");
	  scanf ("%ld", &binary);
	  isValid = validateBinary (binary);
	  if (!isValid)
	     printf("\a\aNot binary. Zeros/ones only.\n\n");
	 } while (!isValid);

	return binary;
} /* getNum */

/*	================= binaryToDecimal ================== 
	Change a binary number to a decimal number. 
	  Pre   binary is a number consisting of only 0 and 1
	  Post  returns the decimal number
*/
long binaryToDecimal (long binary)
{
/*	Local Definitions */
	int   i;
	long  decimal;

/*	Statements */
	decimal = 0;
	for (i = 0; binary != 0; i++)
	    {
	     decimal += firstDigit (binary) * powerTwo (i);
	     binary /= 10;
	    } /* for i */
	return decimal;
} /* binaryToDecimal */

/*	================== validateBinary ================== 
	Check the digits in a binary number for only 0 and 1.
	   Pre   binary is a number to be validated 
	   Post  returns 1 if valid; 0 otherwise 
*/
int validateBinary (long binary)
{
/*	Statements */
	while (binary != 0)
	   {
	    if (!(binary % 10 == 0 || binary % 10 == 1))
	        return 0;
	    binary /= 10;
	   } /* while */
	return 1;
}	/* validateBinary */

/*	===================== powerTwo =====================
	This function raises 2 to the power num 
	   Pre   num is exponent
	   Post  Returns 2 to the power of num
*/
long powerTwo (long num)
{
/*	Local Definitions */
	   int   i;
	   long  power;

/*	Statements */
	for    (power = 1, i = 1; i <= num; i++) 
	    power *= 2;
	return power;
}	   /* powerTwo */
/*	================== firstDigit ================== 
	This function returns the right most digit of num 
	   Pre   the integer num
	   Post  the right digit of num returned
*/
long firstDigit (long num) 
{
/*	Statements */

	return (num % 10);
}	/* first Digit */
/*	================== End of Program ================== */

/*	Results:
	Enter a binary number (zeros and ones): 10001
	The binary number was: 10001 

	The decimal number is: 17
*/
