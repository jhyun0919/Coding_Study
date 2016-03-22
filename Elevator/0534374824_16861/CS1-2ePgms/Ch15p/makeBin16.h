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

#include <string.h>

/*	Prototype Declarations */
char *makeBin16 (unsigned short dec, char *strNum);

/*	==================== makeBin16 ==================== 
	Convert a decimal to binary.
	   Pre   dec is a positive decimal number
	   Post  returns 17 byte string in binary format
*/
char *makeBin16 (unsigned short dec,
                          char  *strNum) 
{
/*	Local Definitions */
	char str[17] = "0000000000000000";
	
	int bitLocn;
	
/*	Statements */
	bitLocn = sizeof(str) - 2;
	while (dec > 0)
	   {
	    if (dec % 2)
	      *(str + bitLocn--) = '1';
	    else
	      *(str + bitLocn--) = '0';
	    dec /= 2;
	   } /* while */
	strcpy (strNum, str);
	return strNum;

} 	/* makeBin16 */

/*	Run results:
	First Number : 0000000010101111
	Second Number: 0000000100110011
	AND Result   : 0000000000100011
*/
