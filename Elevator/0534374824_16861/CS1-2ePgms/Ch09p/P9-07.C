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

/*	Demonstrate size of pointers.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/*	Local Definitions */
	char  c;
	char *pc;
	int   sizeofc      = sizeof(c);
	int   sizeofpc     = sizeof(pc);
	int   sizeofStarpc = sizeof(*pc);
	
	int  a;
	int *pa;
	int  sizeofa        = sizeof(a);
	int  sizeofpa       = sizeof(pa);
	int  sizeofStarpa   = sizeof(*pa);
	
	double  x;
	double *px;
	int	sizeofx      = sizeof(x);
	int	sizeofpx     = sizeof(px);
	int	sizeofStarpx = sizeof(*px);

/*	Statements */
	printf("sizeof(c): %3d | ",  sizeofc);
	printf("sizeof(pc): %3d | ", sizeofpc);
	printf("sizeof(*pc): %3d\n", sizeofStarpc);
		
	printf("sizeof(a): %3d | ",  sizeofa);
	printf("sizeof(pa): %3d | ", sizeofpa);
	printf("sizeof(*pa): %3d\n", sizeofStarpa);

	printf("sizeof(x): %3d | ",  sizeofx);
	printf("sizeof(px): %3d | ", sizeofpx);
	printf("sizeof(*px): %3d\n", sizeofStarpx);

	return 0;
}	/* main */

/*	Results:
	sizeof(c):   1 | sizeof(pc):   4 | sizeof(*pc):   1
	sizeof(a):   2 | sizeof(pa):   4 | sizeof(*pa):   2
	sizeof(x):  12 | sizeof(px):   4 | sizeof(*px):  12
*/
