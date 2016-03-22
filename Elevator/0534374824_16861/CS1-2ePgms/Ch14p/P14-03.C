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
int seekNode (NODE   *pList,  NODE  **pPre, 
              NODE  **pCur,   int     offset);

/*	==================== seekNode ====================
	This function locates the predecessor to a requested
	node in the link list.
	   Pre   pList points to a head node
	         pPre points to variable to receive predecessor
	         pCur points variable to receive current node
	         offset is ordinal position of node in list
	             -1 requests last node in list
	   Post  pCur points to requested node 
	         -or- null if offset > size of list
	         pPre points to offset - 1
	         -or- null if offset is 1
	         function returns 1 if located, 0 if not  
	         -or- exits program if invalid offset
*/
int seekNode (NODE   *pList, 
              NODE  **pPre, 
              NODE  **pCur,  
              int     offset)
{
/*	Local Definitions */
	int  nodeCnt;
	int  rtnCode;
	
/*	Statements */
	if (offset < 1 && offset != -1)
	   {
	    /* Invalid offset--exit program */
	    printf("Invalid offset in seekNode\n");
	    exit (100);
	   } /* else */
	   
	*pPre = NULL;
	*pCur = pList;
	
	if (offset == -1)
	   {
	    /* find end of list */
	    while (*pCur)
	       {
	        *pPre = *pCur;
	        *pCur = (*pCur)->link;
	       } /* while */
	    rtnCode = 1;
	   } /* if */
	else
	   {
	    /* Locate requested node */
	    nodeCnt = offset;
	    while (nodeCnt > 1 && *pCur)
	       {
	        *pPre = *pCur;
	        *pCur = (*pCur)->link;
	        nodeCnt--;
	       } /* while */
	    if (*pCur)
	        rtnCode = 1;
	    else
	        rtnCode = 0;
	   } /* else */
	return rtnCode;
}	/* seekNode */
