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

/*	This program demonstrates an array of pointers to strings.
	   Written by: 
	   Date written: 
*/
#include <stdio.h> 

int main (void)
{
	/* Local Definitions */
	char  *pDays[7];
	char **pLast;
	char **pWalker;
	
	/* Statements */
	pDays[0] = "Sunday";
	pDays[1] = "Monday";
	pDays[2] = "Tuesday";
	pDays[3] = "Wednesday";
	pDays[4] = "Thursday";
	pDays[5] = "Friday";
	pDays[6] = "Saturday";

	printf("The days of the week\n");
	pLast = pDays + 6;
	for (pWalker = pDays; pWalker <= pLast; pWalker++)
	     printf("%s\n", *pWalker);

	return 0;
} /* main*/

/*	Results:
	The days of the week
	Sunday
	Monday
	Tuesday
	Wednesday
	Thursday
	Friday
	Saturday
*/
