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
	void sun (void);

/* Global Definitions */
	int a = 100;
	int b = 200;

int main (void)
{
/* Statements */
	printf ("The value of a in main is: %3d\n",   a); 
	printf ("The value of b in main is: %3d\n\n", b); 

	fun ();
	sun ();

	printf ("The value of a in main is: %d\n", a); 
	printf ("The value of b in main is: %d\n", b); 

	return 0;
}	/*main */

/*	Run results:
	The value of a in main is: 100
	The value of b in main is: 200
	
	The value of a in fun is : 101
	The value of b in fun is :   0

	The value of a in sun is : 102
	The value of b in sun is : 201

	The value of a in main is: 102
	The value of b in main is: 201
*/
