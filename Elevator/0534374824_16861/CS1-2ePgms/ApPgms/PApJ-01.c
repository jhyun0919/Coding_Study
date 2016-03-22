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

/*	Demonstrate use of pointers to functions. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Declarations */
void strange (void(*ptrToFunction)(void)); 
void fun  (void);
void pun  (void);
void sun  (void);

int main (void)
{
/*	Local Definitions */
	void (*f1) (void);

/*	Statements */
	f1 = fun;
	strange (f1);
	f1 = pun;
	strange (f1);
	strange (sun);
	return 0;
} /* main */

/* ================== strange ================== 
	This function will call whatever function is passed
	to it by the calling function.
	   Pre   ptrFun is pointer to function to be executed 
	   Post  requested function has been executed
*/
void strange (void(*ptrToFunction)(void))
{
	(*ptrToFunction)(); 
	return;
}	/* strange */

/* ================== fun ================== 
	Prints a simple message about fun.
	   Pre    Nothing
	   Post   Message has been printed
*/
void fun (void)
{
	printf("Fun is being with good friends.\n");
	return;
}	/* fun */
/* ================== pun ================== 
	Prints a simple message about pun.
	   Pre   nothing
	   Post  message has been printed
*/
void pun (void)
{
	printf("Pun is a play on words.\n");
	return;
}	/* pun */

/* ================== sun ================== 
	Prints a simple message about sun.
	   Pre   nothing
	   Post  message has been printed
*/
void sun (void)
{
	printf("Sun is a bright star.\n");
	return;
}	/* sun */

/*	Results:
	Fun is being with good friends.
	Pun is a play on words.
	Sun is a bright star.
*/
