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

/*	Demonstrate separate compilations.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Declarations */
void fun (void);

static int b;

/*	==================== fun ====================
	Increments a global variable and prints it
	   Pre   nothing 
	   Post  variable incremented and printed 
*/
void fun (void)
{ 
/*	Local Definitions */
	extern int a;

/*	Statements */
	a++;
	printf ("The value of a in fun is : %3d\n",   a);
	printf ("The value of b in fun is : %3d\n\n", b); 
	return;
}	/* fun */
