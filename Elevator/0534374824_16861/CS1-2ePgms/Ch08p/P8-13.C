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

/*	Test driver for searching. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define MAX_ARY_SIZE 15

/*	Prototype Declarations */
int seqSearch (int  list[], int last, int target, int *locn);

int main (void) 
{
/*	Local Declarations */
	int i;
	int locn;
	int target;
	int	ary[MAX_ARY_SIZE] = { 89, 72,  3, 15, 21, 
							  57, 62, 44, 19, 98, 
							   5, 77, 39, 59, 61 };
/*	Statements */
	printf("Data: ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[i]);
	
	printf("\n\nEnter a key for search     : ");
	scanf("%d", &target);	
	do
	  {
	   if (seqSearch (ary, MAX_ARY_SIZE - 1, target, &locn))
	       printf("%3d found at location:       %2d\n", target, locn);
	   else
	       printf("%d3 NOT found at locn:        %2d\n", target, locn);
	   printf("Enter next key <-1> to quit: ");
	   scanf("%d", &target);	
	  } while (target != -1);

	printf("End of search.\n");
	return 0;
}	/* main */

/*	==================== seqSearch ====================
	Locate the target in an unordered list of size elements.
	   Pre   list must contain at least one item.
	         last contains index to last element in list 
	         target contains the data to be located 
	   Post  FOUND: matching index stored in locn address
	                return 1 (found)
	         NOT FOUND: last stored in locn address
	                    return 0 (not found)
*/
int seqSearch (int  list[], 
               int  last, 
               int  target, 
               int *locn)
{
/*	Local Definitions */
	int looker;

/*	Statements */
	looker = 0; 
	while (looker < last && target != list[looker])
	   looker++; 

	*locn = looker;
	return (target == list[looker]);
}	/* seqSearch */

/*	Results:
	Data:  89 72  3 15 21 57 62 44 19 98  5 77 39 59 61

	Enter a key for search     : 89
	 89 found at location:        0
	Enter next key <-1> to quit: 61
	 61 found at location:       14
	Enter next key <-1> to quit: 4
	43 NOT found at locn:        14
	Enter next key <-1> to quit: -1
	End of search.
*/
