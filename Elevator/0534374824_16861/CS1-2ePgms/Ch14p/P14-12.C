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

/*	Prototype Declaration */
void append (NODE *list1, NODE *list2);

/*	================= append ================
	This function appends the first list to the end
	of the second list.
	   Pre   lists have been created 
	   Post  first list appended to the second list 
*/
void append (NODE *list1,
             NODE *list2)
{
/*	Local Definitions */
	NODE *pPre;
	NODE *pCur;
	
/*	Statements */
	seekNode(list2, &pPre, &pCur, -1);
	pPre->link = list1;
	
	return;
}	/* append */
