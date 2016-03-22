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

/*	Demonstrate the bitwise shift-left operator.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
/* Local Definitions */
int num  = 49U;
int res;

 /* Statements */
res =  num << 1;

printf("Original value: %3d\n", num);
printf("Shifted 1 left: %3d\n", res);

res =  num << 2;
printf ("Shifted 2 left: %3d \n", res);

res = num << 4;
printf ("Shifted 4 left: %3d \n", res);

return 0;
} /* main */

/*	Results:
	Original value:  49
	Shifted 1 left:  98       (times  2) 
	Shifted 2 left: 196       (times  4) 
	Shifted 4 left: 784       (times 16) 
*/
