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

/*	This program tests the reusability of dynamic memory.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
/*	Local Definitions */
	int  looper;
	int *ptr;
	
/*	Statements */
	for (looper = 0; looper < 5; looper++)
	   {
	    ptr = malloc(16);
	    printf("Memory allocated at: %p\n", ptr);
 
	    free (ptr);
	   } /* for */
	return 0;
}	/* main */

/*	Results in Personal Computer:
	Memory allocated at: 00E7FC32
	Memory allocated at: 00E8024A
	Memory allocated at: 00E8025C
	Memory allocated at: 00E8026E
	Memory allocated at: 00E80280
*/
