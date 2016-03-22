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

/*	Test driver for "Checking scanf results."
	   Written by:
	   Date: 
*/
#include <stdio.h>

#define FLUSH while (getchar() != '\n')
#define ERR1 "\aPrice incorrect. Re-enter both fields\n" 
#define ERR2 "\aAmount incorrect. Re-enter both fields\n" 

int main (void)
{
/*	Local Definitions */
	int   ioResult;
	int   amount;
	float price;
	
/*	Statements */

/* Read price and amount */
	 do
	   {
	    printf("\nEnter amount and price: ");
	    ioResult = scanf("%d%f", &amount, &price);

	    if (ioResult != 2)
	       {
	        FLUSH;
	        if (ioResult == 1)
	            printf(ERR1);
	        else
	            printf(ERR2);
	       } /* if */
	   } while (ioResult != 2);
	   
	printf("Amount: %d | Price: %5.2f\n", amount, price);
	return 0;
}	/* main */

/*	Results:
	
Results:
	Enter amount and price: ? 15.25
	Amount incorrect. Re-enter both fields

	Enter amount and price: 100 ?
	Price incorrect. Re-enter both fields

	Enter amount and price: 100 15.25
*/

