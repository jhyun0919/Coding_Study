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

/*	This program adds, subtracts, multiplies, and divides
	two integers.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Definitions */
int   getOption (void);

float add2  (float num1, float num2);
float sub2  (float num1, float num2);
float mul2  (float num1, float num2);
float div2  (float num1, float num2);

void  printResult (float num1,   float num2,
                   float result, int option);

int main (void)
{
/*	Local Definitions */
	int    done = 0;
	int    option;
	float  num1;
	float  num2;
	float  result;

/*	Statements */
	while (!done)
	  {
	   option = getOption();
	   if (option == 5)
	      done = 1;
	   else
	     {
	      do
	        {
	         printf("\n\nEnter two numbers: ");
	         scanf("%f %f", &num1, &num2);
	         if (option == 4 && num2 == 0)
	            {
	             printf("\a\n *** Error *** ");
	             printf("Second number cannot be 0\n"); 
	            } /* if */
	        } while (option == 4 && num2 == 0);

	      switch (option)
	        {
	         case 1: result = add2 (num1, num2);
	                 break;
	         case 2: result = sub2 (num1, num2);
	                 break;
	         case 3: result = mul2 (num1, num2);
	                 break;
	         case 4: result = div2 (num1, num2); 
	        } /* switch */

	      printResult (num1, num2, result, option);
	     } /* else option != 5 */
	  } /* while */
	printf("\nThank you for using Calculator.\n");

	return 0;
}	/* main */

/*	==================== getOption ====================
	This function shows a menu and reads the user option.
	   Pre   nothing 
	   Post  returns a valid option 
*/
int getOption (void)
{ 
/*	Local Definitions */
	int option;

/*	Statements */
	do
	  {
	   printf("\n*******************");
	   printf("\n*       MENU      *");
	   printf("\n*                 *");
	   printf("\n*  1. ADD         *");
	   printf("\n*  2. SUBTRACT    *");
	   printf("\n*  3. MULTIPLY    *");
	   printf("\n*  4. DIVIDE      *");
	   printf("\n*  5. QUIT        *");
	   printf("\n*                 *");
	   printf("\n*******************");

	   printf("\n\n\nPlease type your choice ");
	   printf("and press the return key : ");
	   scanf("%d", &option);

	   if (option < 1 || option > 5)
	      printf("\nInvalid option. Please re-enter.\n");

	 } while (option < 1 || option > 5);

	return option;
}	/* getOption */

/*	===============================================
	The following program are copied from Chapter 5 
	===============================================	
*/

/*	====================== add2 ======================
	This function adds two numbers. 
	   Pre   The two numbers are given as parameters.
	   Post  returns the results.
*/
float add2 (float num1,
            float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 + num2;
	return res;
}	/* add */
/*	====================== sub2 ======================
/*	This function subtracts two numbers.
	   Pre   The two numbers are given as parameters
	   Post  returns the results
*/
float sub2 (float num1,
            float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 - num2;
	return res;
}	/* sub */
/*	====================== mul2 ======================
/* This function multiplies two numbers.
	   Pre   The two numbers are given as parameters
	   Post  returns the results
*/
float mul2 (float num1,
            float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 * num2;
	return res;
}	/* mul */
/*	====================== div2 ======================
/*	This function divides two numbers.
	   Pre   The two numbers are given as parameters
	   Post  returns the results
*/
float div2 (float num1,
            float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 / num2;
	return res;
}	/* dvd */
/*	=================== printResult ===================
/*	This function prints the result of calculation.
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

/*	Results:
	*******************
	*       MENU      *
	*                 *
	*  1. ADD         *
	*  2. SUBTRACT    *
	*  3. MULTIPLY    *
	*  4. DIVIDE      *
	*  5. QUIT        *
	*                 *
	*******************


	Please type your choice and press the return key : 1


	Enter two numbers: 2 5

	    2.00  +  5.00 = 7.00

	*******************
	*       MENU      *
	*                 *
	*  1. ADD         *
	*  2. SUBTRACT    *
	*  3. MULTIPLY    *
	*  4. DIVIDE      *
	*  5. QUIT        *
	*                 *
	*******************


	Please type your choice and press the return key : 5

	Thank you for using Calculator.
*/
