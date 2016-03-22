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

/*	Count number of words in file. Words are separated by 
	whitespace characters: space, tab, and newline.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define WHT_SPC (cur == ' ' || cur == '\n' || cur == '\t')

int main (void)
{
/*Local Definitions */
	int   cur;
	int   countWd = 0;
	char  word = 'O';					     /* O out of word: I in word */
	FILE *fp1;

/*	Statements */
	if (!(fp1 = fopen("P7-07.DAT", "r")))
	   {
	    printf("Error opening P7-07.DAT for reading");
	    return (1);
	   } /* if file open error */
	while ((cur = fgetc(fp1)) != EOF)
	   {
	    if (WHT_SPC)
	        word = 'O';
	    else
	        if (word == 'O')
	           {
	            countWd++;
	            word = 'I';
	           } /* else */
	   } /* while */
	printf("The number of words is: %d\n", countWd);

	fclose(fp1);
	return 0;
}	/* main */

/*	Results:	
	The number of words is: 16
*/
