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
void printList (NODE *pList);

/*	Traverse and print a linked list. 
	   Pre   pList is a valid linked list
	   Post  List has been printed
*/
void printList (NODE *pList) 
{
/*	Local Definitions */
	NODE *pWalker;
	int   lineCount = 0;

/*	Statements */
	pWalker = pList;
	printf("\nList contains:\n");

	while (pWalker)
	   {
	    if (++lineCount > 10)
	       {
	        lineCount = 1;
	        printf("\n");
	       } /* if */

	    printf("%3d ", pWalker->data.key);
	    pWalker = pWalker->link;
	   } /* while */
	printf("\n");
	return;
} /* printList */
