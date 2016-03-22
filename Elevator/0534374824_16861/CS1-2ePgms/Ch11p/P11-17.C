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

/*	Test driver for formatDlr.
	   Date written: 
	   Written by: 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define COMMA ","

/*	Prototype Declarations */
int formatDlr (double num, char *out, int width);

int main (void)
{
/*	Local Definitions */
	double amt;
	char   outArea[36];

/*	Statements */
	printf("Enter a floating-point number: ");
	scanf ("%lf", &amt);

	if (formatDlr (amt, outArea, 36))
	    printf("Your number is: %s\n", outArea);
	else
	    printf("\a\nNumber could not be formatted.\n");

	return 0;
}	/* main */

/*	=================== formatDlr ===================
	Format float as dollar amount with $ and commas.
	   Pre   num is a floating point number
	         out is address of a string output area
	         width is maximum size of the output
	   Post  num has been formatted and one returned
	         or if errors detected, zero returned and
	               out is undefined.
*/
int formatDlr (double num,
               char  *out,
               int    wdth)
{
/*	Local Definitions */
	char *dlrs;                    /* Dollars string */
	char *pDlrs;
	char *pCents;
	int   numCommas;
	int   result;
	int   size;

/*	Statements */
	dlrs = (char *)malloc (wdth + 1);
	strcpy (out, "$");
	sprintf(dlrs, "%.2f", num);
	pDlrs     = dlrs;
	strtok (dlrs, ".");
	pCents    = strtok (NULL, ".");
	numCommas = (ceil (strlen (dlrs) / 3.0) - 1);
	
	if ((strlen (dlrs) + numCommas + 4) > wdth)
		result = 0;
	else
	   {
	    switch (numCommas) 
	       {
	        case 5:        /* ddd,ddd,ddd,ddd,ddd,ddd.dd */
	                size    = strlen (pDlrs) - 15;
	                strncat (out, pDlrs, size);
	                strcat  (out, COMMA);
	                pDlrs   = pDlrs + size;
	        case 4:            /* ddd,ddd,ddd,ddd,ddd.dd */
	                size    = strlen (pDlrs) - 12;
	                strncat (out, pDlrs, size);
	                strcat  (out, COMMA);
	                pDlrs   = pDlrs + size;
	        case 3:                /* ddd,ddd,ddd,ddd.dd */
	                size    = strlen (pDlrs) - 9;
	                strncat (out, pDlrs, size);
	                strcat  (out, COMMA);
	                pDlrs   = pDlrs + size;
	        case 2:                    /* ddd,ddd,ddd.dd */
	                size    = strlen (pDlrs) - 6;
	                strncat (out, pDlrs, size);
	                strcat  (out, COMMA);
	                pDlrs   = pDlrs + size;
	        case 1:                        /* ddd,ddd.dd */
	                size = strlen (pDlrs) - 3;
	                strncat (out, pDlrs, size);
	                strcat  (out, COMMA);
	                pDlrs = pDlrs + size;
	        default:                            /*ddd.dd */
	                size = strlen (pDlrs) ;
	                strncat (out, pDlrs, size);
	                strcat  (out, ".");
	                strcat  (out, pCents);
	       } /* switch */
	   } /* else */
	free (dlrs);
	return 1;
}	/* formatDlr */

/*	Results:
	Enter a floating-point number: 123456789012.987
	Your number is: $123,456,789,012.99
	
	Enter a floating-point number: 12345678.91
	Your number is: $12,345,678.91

	Enter a floating-point number: 1.23333
	Your number is: $1.23
*/
