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

#include <stdio.h>
int main (void)
{
	int  i;
	int  j;
	int  sum;
	
	scanf("%d%d", &i, &j);
	sum = i + j;
	printf("The sum of %d & %d is %d\n", i, j, sum);
	return 0;
}	/*  main  */

/*	Resuls
	3 8
	The sum of 3 & 8 is 11
*/
