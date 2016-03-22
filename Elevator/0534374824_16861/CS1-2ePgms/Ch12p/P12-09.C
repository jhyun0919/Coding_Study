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

/*	Reformat IP string address to long integer.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*	Global Structures */
	typedef union
	   {
	    unsigned char chAddr[4];
	    unsigned long numAddr;
	   } IP_ADDR;

int main (void)
{
/*	Local Definitions */
	int      i;
	IP_ADDR  addr;
	char    *parser;
	char    *strAddr = "153.18.8.105";
	
/*	Statements */
	/* Convert first address segment */
	parser = strtok (strAddr, ".");
	addr.chAddr[0] = strtol (parser, (char **)NULL, 10);
	
	for (i = 1; i < 4; i++)
	    {
	     /* Convert decimal dot positions 2, 3, 4 */
	     parser = strtok (NULL, ".");
	     addr.chAddr[i] = strtol (parser, (char **)NULL, 10);
	    } /* for */
	    
	/* Now print results */
	printf ("IP decimal dot   : %d.%d.%d.%d\n",
	          addr.chAddr[0], addr.chAddr[1],
	          addr.chAddr[2], addr.chAddr[3]);
	printf ("IP binary address: %lu\n", addr.numAddr);
	
	return 0;
}	/* main */

/*	Results: Big Endian:
	IP decimal dot   : 153.18.8.105
	IP binary address: 2568095849

	Results: Little Endian:
	IP decimal dot   : 153.18.8.105
	IP binary address: 1762136729
*/
