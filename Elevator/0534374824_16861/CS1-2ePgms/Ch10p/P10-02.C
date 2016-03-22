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

/*	Test driver for searching--binary search. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define MAX_ARY_SIZE 12

/*	Prototype Declarations */
int binarySearch (int   list[], int  *endPtr, 
                  int   target, int **locnPtr);

int main (void) 
{
/*	Local Declarations */
	int  i;
	int  target;
	int *locn;
	int	 ary[MAX_ARY_SIZE] = {  4,  7,  8, 10, 
	              14, 21, 22, 36, 
	              62, 77, 81, 91, };
	              
/*	Statements */
	printf("Data: ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[i]);
	
	printf("\n\nEnter a key for search     : ");
	scanf("%d", &target);	
	do
	  {
	   if (binarySearch (ary, ary + MAX_ARY_SIZE - 1, target, &locn))
	       printf("%3d found at location:       %2d\n", target, locn - ary);
	   else
	       printf("%3d NOT found at locn:       %2d\n", target, locn - ary);
	   printf("Enter next key <-1> to quit: ");
	   scanf("%d", &target);	
	  } while (target != -1);

	printf("End of search.\n");
	return 0;
}	/* main */

/* ==================== binary Search ====================
	Search an ordered list using Binary Search 
	   Pre   list must contain at least one element
	         endPtr is pointer to largest element in list
	         target is value of element being sought
	   Post  FOUND: locnPtr pointer to target element 
	                return 1 (found)
	         !FOUND: locnPtr = element below or above target 
	                 return 0 (not found)
*/
int binarySearch (int   list[],
                  int  *endPtr,
                  int   target, 
                  int **locnPtr)
{
/*	Local Definitions */
	int *firstPtr;
	int *midPtr;
	int *lastPtr;

/*	Statements */
	firstPtr = list;
	lastPtr  = endPtr;
	while (firstPtr <= lastPtr)
	   {
	    midPtr = firstPtr + (lastPtr - firstPtr) / 2;
	    if (target > *midPtr)
	       /* look in upper half */
	       firstPtr = midPtr + 1;
	    else if (target < *midPtr)
	       /* look in lower half */
	       lastPtr = midPtr - 1;
	    else
	       /* found equal: force exit */
	       firstPtr = lastPtr + 1;
	   } /* end while */
	*locnPtr = midPtr;
	return (target == *midPtr);
}	/* binarySearch */

/*	Results:
	Data:   4  7  8 10 14 21 22 36 62 77 81 91

	Enter a key for search     : 4
	  4 found at location:        0
	Enter next key <-1> to quit: 91
	 91 found at location:       11
	Enter next key <-1> to quit: 7
	  7 found at location:        1
	Enter next key <-1> to quit: 95
	 95 NOT found at locn:       11
	Enter next key <-1> to quit: -1
	End of search.
*/
