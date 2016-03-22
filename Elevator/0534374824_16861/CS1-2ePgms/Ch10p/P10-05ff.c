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

/*	Demonstrate concept of storing arrays in the heap. This 
	program builds and manipulates a variable number of ragged 
	arrays. It then calculates the minimum, maximum, and 
	average of the numbers in the arrays.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*	Prototype Declarations */
int **buildTable   (void);
void  fillTable    (int **table); 
void  processTable (int **table); 
int   smaller      (int first, int second);
int   larger       (int first, int second);
int   rowMinimum   (int *rowPtr);
int   rowMaximum   (int *rowPtr);
float rowAverage   (int *rowPtr);

int main (void)
{
/*	Local Definitions */
   int **table;

/*	Statements */
	table = buildTable(); 
	fillTable    (table); 
	processTable (table); 
	return 0; 
}	/* main */

/* ==================== buildTable ====================
	  Create backbone of the table by creating an array of
	pointers, each pointing to an array of integers.
	   Pre   nothing
	   Post  returns pointer to the table
*/
int **buildTable (void) 
{
/*	Local Definitions */
	int   rowNum;
	int   colNum;
	int **table;
	int   row;

/*	Statements */
	printf("\nEnter the number of rows in the table: "); 
	scanf("%d", &rowNum); 
	table = (int **) calloc(rowNum + 1, sizeof(int*)); 
	for (row = 0; row < rowNum; row++) 
	    {
	     printf("Enter number of integers in row %d: ", 
	             row + 1);
	     scanf("%d", &colNum); 
	     table[row] = (int*)calloc(colNum + 1, sizeof(int));
	     table[row] [0] = colNum; 
	    } /* for */
	table[row] = NULL;
	return table;
}	/* buildTable */

/*	==================== fillTable ====================
	This function fills the array rows with data. 
	   Pre   array of pointers 
	   Post  array filled 
*/
void fillTable (int **table) 
{
/*	Local Definitions */
	int row = 0;
	int column;

/*	Statements */
	printf("\n =============================");
	printf("\n Now we fill the table.\n");
	printf("\n For each row enter the data");
	printf("\n and press return: ");
	printf("\n =============================\n");

	while (table[row] != NULL) 
	   {
	    printf("\n row %d (%d integers) =====> ", 
	            row + 1, table[row][0]);
	    for (column = 1; column <= *table[row]; column++)
	         scanf("%d", table[row] + column); 
	    row++;
	   } /* while */
	return;
}	/* fillTable */

/*	==================== processTable ====================
	Process the table to create the statistics.
	   Pre   table
	   Post  statistics (min, max, and average) for each row.
*/
void processTable (int **table)
{
/*	Local Definitions */
int   row = 0;
int   rowMin;
int   rowMax;
float rowAve;

/*	Statements */
	while (table[row] != NULL)
	   {
	    rowMin = rowMinimum (table[row]);
	    rowMax = rowMaximum (table[row]);
	    rowAve = rowAverage (table[row]);
	    printf("\n\nThe statistics for row %d ", row + 1);
	    printf("\nThe minimum: %5d",    rowMin); 
	    printf("\nThe maximum: %5d",    rowMax); 
	    printf("\nThe average: %8.2f ", rowAve);
	    row++;
	   } /* while */
	return;
}	/* processTable */

/*	==================== rowMinimum ====================
	This function determines the minimum of the data in a row.
	   Pre   given pointer to the row
	   Post  returns the minimum for that row 
*/
int rowMinimum (int *rowPtr) 
{

/*	Local Definitions */
	int rowMin = INT_MAX;
	int column;

/*	Statements */
	for (column = 1; column <= *rowPtr; column++) 
	     rowMin = smaller (rowMin, *(rowPtr + column)); 
	return rowMin;
}	/*rowMinimum */

/*	==================== rowMaximum ====================
	This function calculates the maximum of the data in a row.
	   Pre   given pointer to the row 
	   Post  returns the maximum for that row
*/
int rowMaximum (int *rowPtr) 
{
/*	Local Definitions */
	int rowMax = INT_MIN;
	int column;

/*	Statements */
	for (column = 1; column <= *rowPtr; column++) 
	     rowMax = larger  (rowMax, *(rowPtr + column)); 
	return rowMax;
}	/*rowMaximum */

/*	==================== rowAverage ====================
	This function calculates the average of the data in a row.
	   Pre   pointer to the row
	   Post  returns the average for that row 
*/
float  rowAverage (int *rowPtr) 
{
/*	Local Definitions */
	float  total = 0;
	float  rowAve;
	int    column;

/*	Statements */
	for (column = 1; column <= *rowPtr; column++)
	     total += (float)*(rowPtr + column);
	rowAve = total / *rowPtr;
	return rowAve;
}	/*rowAverage */

/*	==================== smaller ====================
	This function returns the smaller of two numbers.
	   Pre   two numbers
	   Post  returns the smaller
*/
int  smaller (int first,  
              int second)
{
/*	Local Definitions */
	int result;

/*	Statements */
	result = first < second ? first : second;
	return result;
}	/* smaller */

/*	 ==================== larger ====================
	This function returns the larger of two numbers.
	   Pre   two numbers
	   Post  returns the larger
*/
int  larger  (int first, 
              int second)
{
/*	Local Definitions */
	int result;

/*	Statements */
	result = first > second ? first : second;
	return result;
}	/* larger */

/*	Results:
	
	Enter the number of rows in the table: 3
	Enter number of integers in row 1: 3
	Enter number of integers in row 2: 5
	Enter number of integers in row 3: 4

	 =============================
	 Now we fill the table.

	 For each row enter the data
	 and press return: 
	 =============================

	 row 1 (3 integers) =====> 12 3 45

	 row 2 (5 integers) =====> 10 6 61 78 61

	 row 3 (4 integers) =====> 2 31 40 70


	The statistics for row 1 
	The minimum:     3
	The maximum:    45
	The average:    20.00 

	The statistics for row 2 
	The minimum:     6
	The maximum:    78
	The average:    43.20 

	The statistics for row 3 
	The minimum:     2
	The maximum:    70
	The average:    35.75 
*/
