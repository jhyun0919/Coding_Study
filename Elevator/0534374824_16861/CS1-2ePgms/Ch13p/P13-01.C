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

/*	This program was modified to compile. It does not execute. */

#include <stdio.h>

int main (void)
{
/*	Read a file of integers, three integers at a time. */

/*	Local Definitions */
	FILE *intFile;
	int   i; 
	int   itemsRead;
	int   intAry[3];
/*	Statements */
	intFile = fopen("int_file.dat", "rb");

	while ((itemsRead = fread(intAry, 
	        sizeof(int), 3, intFile)) != 0)
	   {
	    /* process array */
	    for (i = 0; i < itemsRead ; i++) 
	         ;
	   } /* while */
	   
	return 0;
}	/* function */

