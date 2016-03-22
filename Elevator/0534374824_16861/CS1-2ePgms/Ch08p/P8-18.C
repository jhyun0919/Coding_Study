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

/*	This program reads values of a two-dimensional array 
	from the keyboard. It then creates two one-dimensional 
	arrays, which are the averages of rows and columns.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLS 6

/*	Prototype Declaration */
void  getData       (int   table[][MAX_COLS]);
void  columnAverage (int   table[][MAX_COLS], 
                     float colAvrg []);
void  rowAverage    (int   table[][MAX_COLS],
                     float rowAvrg []);
void  printTables   (int   table[][MAX_COLS], 
                     float rowAvrg[], 
                     float colAvrg[]);

int main (void)
{
/*	Local Definitions */
	int   table     [MAX_ROWS][MAX_COLS];

	float rowAve    [MAX_ROWS] = {0};
	float columnAve [MAX_COLS] = {0};

/*	Statements */
	getData        (table);
	columnAverage  (table, columnAve);
	rowAverage     (table, rowAve);
	printTables    (table, rowAve, columnAve);

	return 0;
}	/* main */

/*	====================== getData ======================
	This function receives data for a two-dimensional array.
	   Pre   table is empty array to be filled with integers 
	   Post  the array would be filled 
*/
void getData (int table[][MAX_COLS]) 
{
/*	Local Definitions */
	int row;
	int col;

/*	Statements */
	for (row = 0; row < MAX_ROWS; row++)
	   for (col = 0; col < MAX_COLS; col++)
	       {
	        printf("\nEnter integer and key <return>: ");
	        scanf("%d", &table[row][col]);
	       } /* for col */
   return;
} /* getData */

/* ==================== columnAverage ====================
	This function calculates the average for the columns.
	   Pre   table has been filled with integer values
	   Post  average calculated and put in the average array
*/
void columnAverage (int    table [][MAX_COLS],
                    float  colAvrg[])
{
/*	Local Definitions */
	int row;
	int col;

/*	Statements */
	for (col = 0; col < MAX_COLS; col++)
	   {
	    for (row = 0; row < MAX_ROWS ; row++)
	        colAvrg [col] += table [row][col];
	    colAvrg [col] /=  MAX_ROWS;
	   } /* for col */

	return;
}	/* columnAverage */

/* ==================== rowAverage ====================
	This function calculates the row averages for a table
	   Pre   table has been filled with values
	   Post  averages calculated & put in the average array.
*/
void rowAverage (int    table[][MAX_COLS],
                 float  rowAvrg [])
{
/*	Local Definition */
	int row;
	int col;

/* Statements */
for (row = 0; row < MAX_ROWS; row++)
	   {
	    for (col = 0; col < MAX_COLS ; col++)
	        rowAvrg[row] += table [row][col];
	    rowAvrg [row] /=  MAX_COLS;
	   } /* for row */
	return;
}	/* rowAverage */

/*	==================== printTables ====================
	Print data table, with average of rows at end of each 
	row and average of columns below each column.
	   Pre   each table has been filled with its data
	   Post  the tables have been printed.
*/
void printTables (int    table[][MAX_COLS],
                  float  rowAvrg[], 
                  float  colAvrg[])
{
/*	Local Definitions */
	int row;
	int col;

/*	Statements */
	for (row = 0; row < MAX_ROWS; row++)
	   {
	    for (col = 0; col < MAX_COLS; col++)
	         printf("%6d", table[row][col]);
	    printf("   | %6.2f\n", rowAvrg [row]);
	   } /* for row */

	printf("---------------------------------------\n");
	for (col = 0; col < MAX_COLS; col++)
	     printf("%6.2f", colAvrg[col]);

	return;
}	/* printTables */
/*	================ End of Program ================= */

/*	Results:
	Enter integer and key <return>: 10
	Enter integer and key <return>: 12
	.
	.
	.
	    10    12    14    16    18    20   |  15.00
	    22    24    26    28    30    23   |  25.50
	    25    27    29    31    33    35   |  30.00
	    39    41    43    45    47    49   |  44.00
	    51    53    55    57    59    61   |  56.00
	---------------------------------------
	 29.40 31.40 33.40 35.40 37.40 37.60
*/
