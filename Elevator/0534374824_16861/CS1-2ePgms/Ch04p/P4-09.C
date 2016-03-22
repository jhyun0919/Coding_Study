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

/*	Demonstrate random number generation
	   Written by:
	   Date:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
/*	Local Definitions */
	int  rand1;
	int  rand2;
	int  rand3;
	
/*	Statements */
	printf("Begin random number generation\n");
	
	srand (time (NULL));
	rand1 = rand();
	rand2 = rand();
	rand3 = rand();
		
	printf("The random numbers are: %d %d %d\n",
	         rand1, rand2, rand3);
	return 0;
}	/* main */

/*	Results
	Begin random number generation
	The random numbers are: 31277 16136 26092
*/	
