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
void selectionSort    (int list[], int last);
void exchangeSmallest (int list[], int first, int last); 

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
		
	selectionSort (ary, MAX_ARY_SIZE - 1);

	printf("\nSorted array:   ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[i]);
	printf("\n");
	return 0;
}	/* main */

/*	==================== selectionSort ====================
	Sorts by selecting smallest element in unsorted portion 
	of array and exchanging it with element at the  
	beginning of the unsorted list.
	   Pre   list must contain at least one item 
	         last contains index to last element in list 
	   Post  list rearranged smallest to largest
*/
void selectionSort (int list[], 
                    int last)
{
/*	Local Definitions */
	int current;

/*	Statements */
	for (current = 0; current < last; current++)
	   exchangeSmallest (list, current, last);

	return;
}	/* selectionSort */

/*	================== exchangeSmallest ==================
	Given array of integers, place smallest element into 
	position in array.
	   Pre   list must contain at least one element
	         current is beginning of array (not always 0) 
	         last element in array must be >= current
	   Post  returns index of smallest element in array
*/
void exchangeSmallest (int list[], 
                       int current,
                       int last)
{	
/*	Local Definitions */
	int walker;
	int smallest;
	int tempData;

/*	Statements */
	smallest = current;
	for (walker = current + 1; walker <= last; walker++)
	   if (list[walker] < list[smallest])
	       smallest = walker;

	/* Smallest selected: exchange with current element */
	 tempData        = list[current];
	 list[current]   = list[smallest];
	 list[smallest]  = tempData;

	return;
}	/* exchangeSmallest */

/*	Results:
	Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
*/
