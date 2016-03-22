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

/*	Prototype Declarations */
void sun (void);

/*	==================== sun ====================
	Increments two global variables and prints them. 
	   Pre   nothing 
	   Post  variables incremented and printed 
*/
extern int a;
extern int b;

void sun (void)
{ 
/*	Statements */
a++;
b++;

printf ("The value of a in sun is : %d\n",   a);
printf ("The value of b in sun is : %d\n\n", b);

return;
}	/* sun */
