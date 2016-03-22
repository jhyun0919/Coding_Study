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

/*	Test driver for sorting. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define MAX_ARY_SIZE 15

/*	Prototype Declarations */
void bubbleSort  (int list[], int last);
void bubbleUp    (int list[], int first, int last); 

int main (void) 
{
/*	Local Declarations */
	int i;
	int	ary[MAX_ARY_SIZE] = { 89, 72,  3, 15, 21, 
							  57, 61, 44, 19, 98, 
							   5, 77, 39, 59, 61 };
/*	Statements */
	printf("Unsorted array: ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[i]);
		
	bubbleSort (ary, MAX_ARY_SIZE - 1);

	printf("\nSorted array:   ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[i]);
	printf("\n");
	return 0;
}	/* main */

/*	Prototype Declarations */
	void bubbleUp (int list[], int first, int last); 

/*	==================== bubbleSort ====================
	Sort list using bubble sort. Adjacent elements are 
	compared and exchanged until list is completely ordered.
	   Pre   the list must contain at least one item 
	         last contains index to last element in list
	   Post  list rearranged in sequence low to high
*/
void bubbleSort (int list [],
                 int last)
{
/*	 Local Definitions */
	int current;

/*	Statements */
	 for(current = 0; current < last; current++)
	     bubbleUp (list, current, last);

	return;
}	/* bubbleSort */

/*	====================== bubbleUp ======================
	Move the lowest element in unsorted portion of an array
	to the current element in the unsorted portion.
	   Pre   list must contain at least one element
	         current identifies beginning of unsorted data
	         last identifies the end of the unsorted data
	   Post  array segment has been rearranged so that lowest 
	         element is now at beginning of unsorted portion
*/
void bubbleUp (int list[], 
               int current,
               int last)
{
/*	Local Definitions */
	int walker;
	int temp;

/*	Statements */
	for (walker = last; walker > current; walker--)
	   if (list[walker]  < list[walker - 1])
	      {
	       temp             = list[walker];
	       list[walker]     = list[walker - 1];
	       list[walker - 1] = temp;
	      } /* if */
	return;
}	/* bubbleUp */

/*	Results:
	Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
*/
