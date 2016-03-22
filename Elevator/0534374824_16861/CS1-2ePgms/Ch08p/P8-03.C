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

/*	Read a number series and print it reversed.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	int i;
	int readNum;
	int numPrinted;
	int numbers[50];

/*	Statements */
	printf("You may enter up to 50 integers:\n");
	printf("How many would you like to enter? ");
	scanf ("%d", &readNum);
	
	if (readNum > 50)
	    readNum = 50;
	
	/* Fill the array */
	printf("\nEnter your numbers: \n");
	for (i = 0; i < readNum; i++)
	     scanf("%d", &numbers[i]);
	     
	/* Print the array */
	printf("\nYour numbers reversed are: \n");
	for (i = readNum - 1, numPrinted = 0; 
	     i >= 0;
	     i--)
	   {
	    printf("%3d", numbers[i]);
	    if (numPrinted < 9)
	        numPrinted++;
	    else
	       {
	        printf("\n");
	        numPrinted = 0;
	       } /* else */
	   } /* for */

	return 0;
}	/* main */

/*	Results:
	You may enter up to 50 integers:
	How many would you like to enter? 12

	Enter your numbers: 
	1 2 3 4 5 6 7 8 9 10 11 12

	Your numbers reversed are: 
	 12 11 10  9  8  7  6  5  4  3
	  2  1
*/
