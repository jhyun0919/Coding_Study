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

/*	Read integers from keyboard & print them multiplied by 2.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#define SIZE  5

/*	 Prototype Declarations */
void multiply (int *pAry, int size);

int main (void) 
{
/*	Local Definitions */
	int ary [SIZE];
	int *pLast;
	int *pWalk;

/*	Statements */
	pLast = ary + SIZE - 1;
	for (pWalk = ary; pWalk <= pLast; pWalk++)
	   {
	    printf("Please enter an integer: ");
	    scanf("%d", pWalk);
	   } /* for */

	multiply (ary, SIZE);

	printf ("Doubled value is: \n");
	for (pWalk = ary; pWalk <= pLast; pWalk++)
	     printf (" %3d", *pWalk); 

	return 0;
}	/* main */

/*	==================== multiply ====================
	Multiply elements in an array by 2
	   Pre   array has been filled 
	         size indicates number of elements in array
	   Post  values in array doubled 
*/
void multiply (int *pAry,
               int  size)
{
/*	Local Definitions */
	int *pWalk;
	int *pLast;

/*	Statements */
	pLast = pAry + size - 1;
	for (pWalk = pAry; pWalk <= pLast; pWalk++)
	    *pWalk = *pWalk * 2;
	 return;
}	/* multiply */
/*	================= End of Program ================= */

/*	Results:
	Please enter an integer: 1
	Please enter an integer: 2
	Please enter an integer: 3
	Please enter an integer: 4
	Please enter an integer: 5
	Doubled value is: 
	   2   4   6   8  10
*/
