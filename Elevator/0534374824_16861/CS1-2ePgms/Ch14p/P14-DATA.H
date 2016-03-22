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

/*	Linked list data structures for Chapter 14.
	   Written by: 
	   Date:  
*/
/*	Global Structures */

#ifndef KEY_TYPE

typedef int KEY_TYPE;
typedef struct
	{
	 KEY_TYPE key;
	} DATA;
typedef struct nodeTag
	{
	 DATA             data; 
	 struct nodeTag  *link; 
	} NODE;

#endif
