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

/*	Demonstrate use of unions in structures.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#include <string.h>

/*	Global Structures */
typedef struct
  {
   char  first[20];
   char  init;
   char  last[30];
  } PERSON;
  
typedef struct
  {
   char  type;            /* C--company: P--person */
   union
     {
      char    company[40];
      PERSON  person;
     } un;
  } NAME;

int main (void)
{
/*	Local Definitions */
	int  i;
	NAME business = {'C', "ABC Company"};
	NAME friend;
	NAME names[2];
	
/*	Statements */
	friend.type = 'P';
	strcpy (friend.un.person.first, "Martha");
	strcpy (friend.un.person.last,"Washington");
	friend.un.person.init  = 'C';
	
	names[0] = business;
	names[1] = friend;
	
	for (i = 0; i < 2; i++)
	     switch (names[i].type)
	        {
	         case 'C': printf("Company: %s\n",
	                     names[i].un.company);
	                   break;
	         case 'P': printf("Friend:  %s %c %s\n",
	                     names[i].un.person.first,
	                     names[i].un.person.init,
	                     names[i].un.person.last);
	                   break;
	         default:  printf("Error in type\a\n");
	                   break;
	        } /* switch */
	return 0;
}	/* main */

/*	Results:
	Company: ABC Company
	Friend:  Martha C Washington
*/  
	
