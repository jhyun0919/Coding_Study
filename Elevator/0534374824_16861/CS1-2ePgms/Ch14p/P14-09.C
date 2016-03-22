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

/*	Prototype Statements */
NODE *deleteChron (NODE *pList);

/*	==================== deleteChron ====================
	Delete node from a chronologically linked list.
	   Pre   list is a pointer to the head of the list
	   Post  node has been deleted 
	         -or- a warning message printed if not found
	         returns pointer to first node (pList)
*/
NODE *deleteChron (NODE *pList)
{
/*	Local Definitions */
	int   locn;
	int   valid;
	NODE *pHead;
	NODE *pCur;
	NODE *pPre;

/*	Statements */
	if (!pList)
	   {
	    printf("List is empty...Can't delete.\n");
	    return pList;
	   } /* if */
	   
	printf("Enter position of node to be deleted: ");
	scanf ("%d", &locn);
	
	if (locn < 1)
	    printf("%d is an invalid location\a\n", locn);
	else if (locn == 1)
	    pHead = deleteNode (pList, NULL, pList);
	else
	    {
	     /* seek locations for delete node */
	     valid = seekNode (pList, &pPre, &pCur, locn);
	     if (valid)
	         pHead = deleteNode (pList, pPre, pCur);
	     else
	        {
	         printf("%d is an invalid location\a\n", locn);
	         pHead = pList;
	        } /* else locn not valid*/
	    } /* else delete after 1 */
	     
	return pHead;
} /* deleteChron */
