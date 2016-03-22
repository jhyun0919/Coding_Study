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
int searchList (NODE     *pList,  NODE    **pPre, 
                NODE    **pCur,   KEY_TYPE  target);

/*	==================== searchList ====================
	Given key value, finds the location of a node
	   Pre   pList points to a head node
	         pPre points to variable to receive predecessor
	         pCur points variable to receive current node
	         target is key being sought
	   Post  pCur points to first node with equal/greater key 
	         -or- null if target > key of last node
	         pPre points to largest node smaller than key
	         -or- null if target < key of first node
	         function returns 1 if found, 0 if not found 
*/
int searchList (NODE     *pList, 
                NODE    **pPre, 
                NODE    **pCur,  
                KEY_TYPE  target) 
{
/*	Local Definitions */
	int found = 0; 

/*	Statements */
	*pPre = NULL;
	*pCur = pList;

	/* start the search from beginning */
	while (*pCur != NULL && target > (*pCur)->data.key)
	   {
	    *pPre = *pCur; 
	    *pCur = (*pCur)->link; 
	   } /* while */
	if (*pCur && target == (*pCur)->data.key) 
	   found = 1;

	return found ;
}	/* searchList */
