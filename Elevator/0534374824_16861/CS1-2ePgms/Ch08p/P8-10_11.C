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
#define TRUE  1
#define FALSE 0

/*	Prototype Declarations */
void insertionSort  (int list[], int last);
void insertOne      (int list[], int current); 

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
		
	insertionSort (ary, MAX_ARY_SIZE - 1);

	printf("\nSorted array:   ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[i]);
	printf("\n");
	return 0;
}	/* main */

/*	Prototype Declarations */
void insertOne (int list[], int first);

/*	==================== insertionSort ====================
	Sort list using Insertion Sort. The list is divided into 
	sorted and unsorted lists. With each pass, first element 
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

/*	Statements */
	for (current = 1; current <= last; current++)
	   insertOne(list, current);

	return;
}	/* insertionSort */

/*	====================== insertOne ======================
	Sorts current element in unsorted list into its proper
	location in sorted portion of the list--one sort pass.
	   Pre   list must contain at least one element 
	         current identifies beginning of unsorted list
	   Post  next element placed into its proper location 
*/
void insertOne (int list[],
                int current)
{
/*	Local Definitions */
	int walker;
	int located;
	int temp;

/*	Statements */
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
	return;
}	/* insertOne */

/*	Results:
	Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
*/
