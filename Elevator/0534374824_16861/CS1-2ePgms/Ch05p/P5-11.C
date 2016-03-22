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

/*	This program uses a menu to allow the user to add, 
	multiply, subtract, or divide two integers. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

/*	Prototype Declarations */
void  getData      (float *num1, float *num2);
void  printResult  (float num1,
                    float num2,
                    float result,
                    int   option);
int   getOption    (void);
float calc         (int option, float num1, float num2);
float add          (float num1, float num2);
float sub          (float num1, float num2);
float mul          (float num1, float num2);
float dvd          (float num1, float num2);

int main (void)
{
/*	Local Definitions */
	int option;

	float num1;
	float num2;
	float result;

/*	Statements */
	option = getOption();
	getData (&num1, &num2);
	result = calc (option, num1, num2);
	printResult (num1, num2, result, option);
	
	return 0;
}	/* main */

/*	==================== getOption ==================== 
	This function shows a menu and reads the user option.
	   Pre    Nothing
	   Post   returns the option
*/
int getOption (void)
{
/*	Local Definitions */
	int option;

/*	Statements */
	printf  ("\t**********************************");
	printf("\n\t*              MENU              *");
	printf("\n\t*                                *");
	printf("\n\t*  1. ADD                        *");
	printf("\n\t*  2. SUBTRACT                   *");
	printf("\n\t*  3. MULTIPLY                   *");
	printf("\n\t*  4. DIVIDE                     *");
	printf("\n\t*                                *");
	printf("\n\t**********************************");

	printf("\n\nPlease type your choice ");
	printf("and key return: ");
	scanf ("%d", &option);
	return option;
}	/* getOption */

/*	==================== getData ====================
	This function reads two numbers from the keyboard.
	   Pre   Nothing
	   Post   Two numbers read into variables in main
*/
void getData (float *num1, 
              float *num2)
{
/*	Statements */
	printf("Enter two numbers separated by a space: ");
	scanf ("%f %f", num1, num2);
	return;
}/* getData */

/*	==================== calc ====================
	This function determines the type of operation
	and calls a function to perform it. 
	   Pre   option contains the operation
	         num1 & num2 contains data
	   Post  returns the results
*/
float calc (int   option, 
            float  num1, 
            float  num2) 
{
/* Local Definitions */
float result;

/*	Statements */
	switch (option)
	    {
	     case 1:  result = add (num1, num2);
	              break;
	     case 2:  result = sub (num1, num2);
	              break;
	     case 3:  result = mul (num1, num2);
	              break;
	     case 4:  if (num2 == 0.0) 
	                 {
	                  printf("\n\a\aError: ");
	                  printf("division by zero ***\n");
	                  exit (1);
	                 } /* if */
	              else
	                  result = dvd (num1, num2);
	              break;
	     /* Better structured programming would validate the
	        option in getOption. However, we have not yet 
	        learned the technique to put it there.
	     */
	     default: printf("\aOption not available\n");
	              exit (1);
		} /* switch */ 
	return result;
}	/* calc */ 

/*	====================== add ======================
	This function adds two numbers. 
	   Pre   The two numbers are given as parameters.
	   Post  returns the results.
*/
float add (float num1,
           float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 + num2;
	return res;
}	/* add */
/*	====================== sub ======================
	This function subtracts two numbers.
	   Pre   The two numbers are given as parameters
	   Post  returns the results
*/
float sub (float num1,
           float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 - num2;
	return res;
}	/* sub */
/*	====================== mul ======================
	This function multiplies two numbers.
	   Pre   The two numbers are given as parameters
	   Post  returns the results
*/
float mul (float num1,
           float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 * num2;
	return res;
}	/* mul */
/*	====================== dvd ======================
	This function divides two numbers.
	   Pre   The two numbers are given as parameters
	   Post  returns the results
*/
float dvd (float num1,
           float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 / num2;
	return res;
}	/* dvd */
/*	=================== printResult ===================
	This function prints the result of calculation.
	   Pre   The two numbers, result, and option are given
	   Post  Prints the numbers and the result
*/
void printResult (float num1,
                  float num2,
                  float res,
                  int   option)
{
/*	Statements */
	printf("\n%8.2f ", num1);
	switch (option)
	   {
	    case 1: printf(" + ");
	            break;
	    case 2: printf(" - ");
	            break;
	    case 3: printf(" * ");
	            break;
	    case 4: printf(" / ");
	            break;
	   } /* switch option */
	printf(" %.2f = %.2f\n", num2, res);

	return;
}	/* printResults */
/*	================== End of Program ================== */

/*	Results: 
	    **********************************
	    *              MENU              *
	    *                                *
	    *  1. ADD                        *
	    *  2. SUBTRACT                   *
	    *  3. MULTIPLY                   *
	    *  4. DIVIDE                     *
	    *                                *
	    **********************************

	Please type your choice and key return: 3
	Enter two numbers separated by a space: 5 7

	    5.00  *  7.00 = 35.00
*/
