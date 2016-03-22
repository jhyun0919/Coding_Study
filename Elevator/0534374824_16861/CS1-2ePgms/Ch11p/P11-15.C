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

/*	Demonstrate memory formatting function: sscanf.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <string.h>
#define NAME_SIZE 26

/*	Prototype Statements */
char *getLast  (char *pInput, char *pLast);
char *getFirst (char *pInput, char *pFirst);

int main (void)
{
/*	Local Definitions */
	char  input[81];
	char *pInput;
	
	char  last [NAME_SIZE];
	char  first[NAME_SIZE];
	
/*	Statements */
	printf("Enter: last-name, first-name;\n");
	fgets (input, sizeof(input), stdin);
	
	pInput = input;
	pInput = getLast (pInput, last);
	
	if (pInput)
	   {
	    printf("Last Name : %s\n", last);
	    pInput = getFirst (pInput, first);
	    if (pInput)
	        printf("First Name: %s\n", first);
	   } /* if */
	return 0;
}	/* main */

/*	==================== getLast ====================
	Verify format of name, and parse into variables.
	   Pre   pInput is pointer to string to be checked 
	         pLast is pointer to last name variable
	   Post  last name validated and formatted
	         If no errors, returns pointer to first name
	         If errors, returns null pointer
*/ 
char *getLast (char *pInput,
               char *pLast) 
{
/*	Local Definitions */
	char *pEndLast;

/*	Statements */
	/* Get last name */
	pEndLast = strchr(pInput, ',');
	if (!pEndLast)
	   {
	    printf("\aNo comma in name.\n");
	    return NULL;
	   } /* if */
	else
	   if (pEndLast - pInput > NAME_SIZE - 1)
	      {
	       printf("\aLast Name too big\n");
	       return NULL;
	      } /* if */
	   else
	      sscanf(pInput, "%[^,]", pLast);
	
	return pEndLast + 1;
}	/* getLast */

/*	==================== getFirst ==================
	Verify format of name, and parse into variables.
	   Pre   pInput is pointer to string with input
	         pFirst is pointer to first name variable
	   Post  first name validated and formatted
	         If no errors, returns pointer to first name
	         If errors, returns null pointer
*/ 
char *getFirst (char *pInput,
                char *pFirst) 
{
/*	Local Definitions */
	char *pEndFirst;

/*	Statements */
	/* Get first name - Eliminate leading spaces */
	while (*pInput == ' ')
	   pInput++;

	pEndFirst = strchr(pInput, ';');
	if (!pEndFirst)
	   {
	    printf("\aNo semicolon in name.\n");
	    return NULL;
	   } /* if */
	else
	   if (pEndFirst - pInput > NAME_SIZE - 1)
	      {
	       printf("\aFirst Name too big\n");
	       return NULL;
	      } /* if */
	   else
	      sscanf(pInput, "%[^;]", pFirst);
	
	return pEndFirst + 1;
}	/* getFirst */

/*	Results:
	Enter: last-name, first-name;
	Washington, George;
	Last Name : Washington
	First Name: George

	Results with error:
	Enter: last-name, first-name;
	Arnold,Benedict
	Last Name : Arnold
	No semicolon in name.
*/
