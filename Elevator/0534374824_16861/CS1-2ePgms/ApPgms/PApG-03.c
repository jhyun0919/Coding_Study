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

/*	Test driver for Program G-3. Note executable
	   Written by:
	   Date:
*/
#include <stdio.h>

#define Denver  0
#define Phoenix 0
#define SanJose 1
#define Seattle 0

#if (Denver)
	/* Denver unique initialization */
	#include "Denver.h"
#elif (Phoenix)
	/* Phoenix unique initialization */
	#include "Phoenix.h"
#elif (SanJose)
	/* San Jose unique initialization */
	#include "SanJose.h"
#else
	/* Seattle unique iniitalization */
	#include "Seattle.h"
#endif

int main (void)
{
/*	Statements */
	printf("Does nothing.\n");
	return 0;
}	/* main */

