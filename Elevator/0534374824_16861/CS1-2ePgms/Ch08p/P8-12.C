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

/*	Test driver for insertion sort. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define MAX_ARY_SIZE 15
#define TRUE  1
#define FALSE 0

/*	Prototype Declarations */
void insertionSort  (int list[], int last);

int main (void) 
{
/*	Local Definitions */
	int i;
	int ary[MAX_ARY_SIZE] = { 89, 72,  3, 15, 21, 
	                          57, 61, 44, 19, 98, 
	                           5, 77, 39, 59, 61 };
/*	Statements */
	printf("Unsorted: ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
	     printf("%3d", ary[i]);
	
	insertionSort (ary, MAX_ARY_SIZE - 1);

	printf("\nSorted  : ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
	     printf("%3d", ary[i]);
	printf("\n");
	return 0;
}	/* main */

/*	==================== insertionSort ====================
	Sort list using Insertion Sort. The list is divided into 
	sorted and unsorted list. With each pass, first element 
	in unsorted list is inserted into sorted list.
	   Pre   list must contain at least one element 
	         last contains index to last element in list
	   Post  list has been rearranged 
*/
void insertionSort (int list[], 
                    int last) 
{
/*	Local Definitions */
	int current;
	int walker;
	int located;
	int temp;

/*	Statements */
	for (current = 1; current <= last; current++)
	   {
	    located = FALSE;
	    temp = list[current];
	    for  (walker = current - 1; walker >= 0 && !located;)
	       if (temp < list[walker])
	          {
	           list[walker + 1] = list[walker];
	           walker--;
	          } /* if */
	       else
	           located = TRUE;

	    list [walker + 1] = temp;
	   } /* for */
	return;
}	/* insertionSort */

/*	Results:
	Unsorted:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted  :   3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
*/
