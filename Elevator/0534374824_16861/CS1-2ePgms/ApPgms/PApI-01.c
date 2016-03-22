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

/*	Demonstrate the use of command-line arguments.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int   argc, 
          char *argv[])
{
/*	Local Definitions */
	int i;

/*	Statements */
	printf ("The number of user elements: %d\n", argc);
	printf ("The name of the program: %s\n", argv[0]);

	for ( i = 1 ; i < argc ; i++ )
	   printf ("User Value No. %d: %s\n", i, argv[i]);

	return 0;
} /* main */

/*	Results: (UNIX)
	$ PApI-01 "To err is human" Pope
	The number of user elements: 3
	The name of the program: PApI-01
	User Value No. 1: To err is human
	User Value No. 2: Pope
	$
*/
