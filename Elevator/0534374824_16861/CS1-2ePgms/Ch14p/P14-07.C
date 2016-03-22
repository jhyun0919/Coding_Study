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
int   getData    (FILE *fpData, DATA *pData);
NODE *buildChron (char *fileID);

/*	==================== buildChron ====================
	This function builds a chronological linked list.
	   Pre   fileID is file that contains data for list 
	   Post  list built
	         returns pointer to head of list
*/
NODE *buildChron (char *fileID)
{
/*	Local Definitions */
	DATA   data;
	NODE  *pList;
	NODE  *pPre;
	NODE  *pCur;
	FILE  *fpData;

/*	Statements */
	pList  = NULL;
	fpData = fopen(fileID, "r");
	if (!fpData)
	   {
	    printf("Error opening file %s\a\n", fileID);
	    exit (200);
	   } /* if open fail */
	
	while (getData (fpData, &data))
	   {
	    /* Determine insert position */
	    seekNode  (pList, &pPre, &pCur, -1);
	    pList = insertNode(pList, pPre, data);
	   } /* while */
	   
	return pList;
} /* buildChron */
