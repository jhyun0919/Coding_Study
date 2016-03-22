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

/*	Included in P14-LINK.H */

/*	Prototype Declaration */
double averageList (NODE *pList);

/*	This function averages the values in a linked list.
	   Pre   pList is a pointer to a linked list 
	   Post  list average is returned 
*/
double averageList (NODE *pList)
{
/*	Local Definitions */
	NODE *pWalker;
	int   total;
	int   count;

/*	Statements */
	total   = count = 0;
	pWalker = pList;
	while (pWalker)
	   {
	    total += pWalker->data.key;
	    count++;
	    pWalker = pWalker->link;
	   } /* while */
	return (double)total / count;
} /* averageList */
