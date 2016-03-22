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

/*	Demonstrate union of short integer and two characters.
	   Written by:
	   Date: 
*/
#include <stdio.h>

/*	Global Declarations */
	typedef union 
	   {
	    short  num;
	    char   chAry[2];
	   } SH_CH2;

int main (void)
{
/*	Local Definitions */
	SH_CH2 data;
	
/*	Statements */
	data.num = 16706;
	
	printf("Short: %hd\n", data.num);
	printf("Ch[0]: %c\n",  data.chAry[0]);
	printf("Ch[1]: %c\n",  data.chAry[1]);
	
	return 0;
}	/* main */

/*	Results: (A & B reversed is valid (little endian vs big endian)
	Short: 16706
	Ch[0]: A
	Ch[1]: B
*/
	
