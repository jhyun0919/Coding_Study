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

/*	Demonstrate pointers with Selection Sort
	   Written by: 
	   Date written: 
*/
#include <stdio.h>
#define SIZE 25

/*	Prototype Declarations */
int  *getData    (int *pAry,    int  arySize);
void  selectSort (int *pAry,    int *last);
void  printData  (int *pAry,    int *last);
int  *smallest   (int *pAry,    int *pLast); 
void  exchange   (int *current, int *smallest);

int main (void)
{
/*	Local Definitions */
	int  ary[SIZE];
	int *pLast;

/*	Statements */
	pLast = getData (ary, SIZE);
	selectSort      (ary, pLast);
	printData       (ary, pLast);

	return 0;
}	/* main */

/*	==================== getData ====================
	Reads data from keyboard and places in array for sorting.
	   Pre   pAry is pointer to array to be filled 
	         arySize is integer with maximum array size
	   Post  array filled. Returns address of last element 
*/
int *getData (int *pAry,
              int  arySize) 
{
/*	Local Definitions */
	int  ioResult;
	int  readCnt = 0;
	int *pFill   = pAry;

/*	Statements */
	do
	   {
	    printf("Please enter number or <EOF>: ");
	    ioResult = scanf("%d", pFill);
	    if (ioResult == 1)
	       {
	        pFill++;
	        readCnt++;
	       } /* if */
	   } while (ioResult == 1 && readCnt < arySize);

	printf("\n\n%d numbers read.", readCnt);
	return (--pFill);
}	/* getData */

/*	==================== selectSort ====================
	Sorts by selecting smallest element in unsorted portion 
	of the array and exchanging it with element at the 
	beginning of the unsorted list.
	   Pre   array must contain at least one item 
	         pLast is pointer to last element in array
	   Post  array rearranged smallest to largest
*/
void selectSort (int *pAry, 
                 int *pLast)
{
/*	Local Definitions */
	int *pWalker; 
	int *pSmallest; 

/*	Statements */
	for (pWalker = pAry; pWalker < pLast; pWalker++) 
	    {
	     pSmallest = smallest (pWalker, pLast);
	     exchange (pWalker, pSmallest);
	    } /* for */
	return;
}	/* selectSort */

/*	==================== smallest ====================
	Find smallest element starting at current pointer.
	   Pre   pAry points to first unsorted element in array
	   Post  smallest element identified and returned 
*/
int *smallest (int *pAry, 
               int *pLast) 
	{
/*	Local Definitions */
	int *pLooker;
	int *pSmallest;

/*	Statements */
	for (pSmallest = pAry, pLooker = pAry + 1;
	     pLooker <= pLast;
	     pLooker++)
	   if (*pLooker < *pSmallest) 
	        pSmallest = pLooker;
	return pSmallest;
}	/* smallest */

/*	====================== exchange ====================
	Given pointers to two array elements, exchange them
	   Pre   p1 & p2 are pointers to values to be exchanged
	   Post  exchange is completed
*/
void exchange (int *p1, 
               int *p2)
	{
	/* Local Definitions */
	int temp;
	
	/* Statements */
	temp  =  *p1;
	*p1   =  *p2;
	*p2   =  temp;

	return;
}	/* exchange */

/*	==================== printData ====================
	Given a pointer to an array, print the data.
	   Pre   pAry points to array to be filled
	         pLast identifies last element in the array
	   Post  data have been printed 
*/
void  printData (int *pAry,
                 int *pLast) 
{
/*	Local Definitions */
	int  nmbrPrt;
	int *pPrint;

/*	Statements */
	printf("\n\nYour data sorted are: \n");
	for (pPrint = pAry, nmbrPrt = 0;
	     pPrint <= pLast;
	     nmbrPrt++, pPrint++)
	   printf ("\n#%02d %4d", nmbrPrt, *pPrint);
	printf("\n\nEnd of List ");
	return;
}	/* PrintData */
/*	=================== End of Program ================== */

/*	Results:
	Please enter number or <EOF>: 99
	Please enter number or <EOF>: 18
	Please enter number or <EOF>: 3
	Please enter number or <EOF>: 7
	Please enter number or <EOF>: 16
	Please enter number or <EOF>: 59
	Please enter number or <EOF>: ^d

	6 numbers read.

	Your data sorted are: 

	#00:    3
	#01:    7
	#02:   16
	#03:   18
	#04:   59
	#05:   99

	End of List 
*/
