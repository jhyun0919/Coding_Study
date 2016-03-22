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

/*	Included in P14-link.h */

NODE *insertNode (NODE *pList, NODE *pPre, DATA  item);

/*	==================== insertNode ====================
	This function inserts a single node into a linked list.
	   Pre   pList is pointer to the list; may be null
	         pPre points to new nodeÕs logical predecessor
	         item contains data to be inserted
	   Post  returns the head pointer
*/
NODE *insertNode (NODE *pList,
                  NODE *pPre,
                  DATA  item)
{
/*	Local Definitions */
	NODE *pNew;

/*	Statements */
	if (!(pNew  = (NODE *)malloc(sizeof(NODE)))) 
	    printf("\aMemory overflow in insert\n"), exit (100); 

	pNew->data = item;
	if (pPre == NULL) 
	   {
	    /* Inserting before first node or to empty list */
	    pNew->link  = pList;
	    pList       = pNew;
	   } /* if pPre */
	else
	   {
	    /* Inserting in middle or at end*/
	    pNew->link = pPre->link;
	    pPre->link = pNew;
	   } /* else */ 
	return pList;
}	/* insertNode */
