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

/*	This program appends two linked lists.
	   Written by: 
	   Data: 
*/

#include <stdio.h>
#include <stdlib.h>
#include "P14-DATA.H"
#include "P14-LINK.H"
#include "P14-getData.c"

int main (void)
{
/*	Local Definitions */
	NODE *pList1;
	NODE *pList2;

/*	Statements */
	pList1 = buildChron ("P14FILE1.DAT");
	printList (pList1);
	pList2 = buildChron ("P14FILE2.DAT");
	printList (pList2);

	append (pList2, pList1);

	/* The lists are now appended. Print to prove success */ 
	printList (pList1);

	return 0;
}	/* main */

/*	Results:
	List contains:
	101 111 121 131 141 151 161 171 181 191

	List contains:
	202 212 222 232 242 252 252 272 282 292

	List contains:
	101 111 121 131 141 151 161 171 181 191
	202 212 222 232 242 252 252 272 282 292
	
*/
