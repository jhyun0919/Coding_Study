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

/*	Convert English to Morse code and Morse code to English.
	   Written by: 
	   Date Written: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FLUSH while(getchar() != '\n') 
#define STR_LEN 81

/*	Prototype Declarations */
char menu         (void); 
void getInput     (char *inStr);
void printOutput  (char *inStr, char *outSt); 
int  encode       (char *(*encDec)[2], 
                   char *inStr, 
                   char *outStr); 
int  decode       (char *(*encDec)[2], 
                   char *inStr,
                   char *outStr); 
int  convert      (char *(*encDec)[2], 
                   char *s1, 
                   int   col, 
                   char *s2); 

int main (void) 
{
/*	Local Definitions */
	char *encDec [27][2] = 
	   {
	    { "A", ".-#" }, 
	    { "B", "-...#" }, 
	    { "C", "-.-.#" }, 
	    { "D", "-..#" }, 
	    { "E", ".#" }, 
	    { "F", "..-.#" }, 
	    { "G", "--.#" }, 
	    { "H", "....#" }, 
	    { "I", "..#" }, 
	    { "J", ".---#" }, 
	    { "K", "-.-#" }, 
	    { "L", ".-..#" }, 
	    { "M", "--#" }, 
	    { "N", "-.#" }, 
	    { "O", "---#" }, 
	    { "P", ".--.#" }, 
	    { "Q", "--.-#" }, 
	    { "R", ".-.#" }, 
	    { "S", "...#" }, 
	    { "T", "-#" }, 
	    { "U", "..-#" }, 
	    { "V", "...-#" }, 
	    { "W", ".--#" }, 
	    { "X", "-..-#" }, 
	    { "Y", "-.--#" }, 
	    { "Z", "--..#" }, 
	    { " ", "$$#" }, 
	   }; /* Encode / Decode array */
	char inStr  [STR_LEN]; 
	char outStr [STR_LEN]; 
	char option; 
	int  done = 0; 

/*	Statements */
	while (!done)
	   {
	    option = menu ();
	    switch (option) 
	       {
	        case 'E' :  
	               getInput (inStr);
	               if (!encode (encDec, inStr, outStr))
	                  {
	                   printf ("Error! Try again"); 
	                   break; 
	                  } /* if */
	               printOutput (inStr, outStr); 
	               break;
	        case 'D' : getInput (inStr); 
	               if (!decode (encDec, inStr, outStr))
	                  {
	                   printf ("Error! Try again"); 
	                   break;
	                  } /* if */
	               printOutput (inStr, outStr);
	               break;
	        default :  
	               done = 1;
	               printf("\nEnd of Morse Code.\n");
	               break;
	       } /* switch */
	   } /* while */
	return 0;
}	/* main */ 

/*	==================== menu ====================
	Display menu of choices; return selected character.
	   Pre   nothing 
	   Post  returns validated option code 
*/
char menu (void) 
{
/*	Local Definitions */
	char  option;
	int   validData;

/*	Statements */ 
	printf("\t\t\tM E N U \n"); 
	printf("\t\tE)  encode \n"); 
	printf("\t\tD)  decode \n"); 
	printf("\t\tQ)  quit \n"); 

	do
	   {
	    printf ("\nEnter option: press return key: "); 
	    option = toupper (getchar());
	    FLUSH;
	    if (option == 'E' || option == 'D' || option == 'Q')
	       validData = 1;
	    else
	       {
	        validData = 0;
	        printf("\aEnter only one option\n"); 
	        printf(" \tE, D, or Q\n "); 
	       } /* else */
	   } while (!validData); 
	return option; 
}	/* menu */

/*	==================== getInput ====================
	Reads input string to be encoded or decoded.
	   Pre   inStr is a pointer to the input area 
	   Post  string read into input area
*/
void getInput (char *inStr) 
{
/*	Local Statements */
	printf ("\nPlease enter line of text to be coded: \n");
	fgets  (inStr, STR_LEN, stdin);
	
	/* Eliminate newline in input string */
	*(inStr-1 + strlen(inStr)) = '\0'; 
	
	if (isalpha(*inStr) && strlen(inStr) > 16)
	   {
	    /* Exceeds English input length */
	    printf("\n***WARNING: Input length exceeded: ");
	    printf("Only 16 chars will be encoded.\a\a\n");
	    *(inStr + 16) = '\0';
	   } /* if */
	return;
}	/* getInput */ 

/*	================== printOutput ==================
	Print the input and the transformed output
	   Pre   inStr contains the input data 
	         outStr contains the transformed string 
	   Post  output printed 
*/
void printOutput (char *inStr, 
                  char *outStr) 
{
/*	Statements */
	printf("\nThe information entered was: \n"); 
	puts(inStr); 
	printf("\nThe transformed information is: \n"); 
	puts(outStr); 
	return;
}	/* printOutput */

/* ==================== encode ====================
	Transforms character data to Morse Code 
	   Pre     encDec is the conversion table
	           inStr contains data to be put into Morse
	   Post    data have been encoded in outStr
	   Return  TRUE  if all valid characters; 
	           FALSE if invalid character found
*/
int encode (char *(*encDec)[2], 
            char *inStr,
            char *outStr) 
{
/*	Local Definitions */
	char s1[2];
	char s2[6];
	int  error = 0;

/*	Statements */
	outStr[0] = '\0';
	while (*inStr != '\0' && !error) 
	   {
	    s1[0] = toupper(*inStr);
	    s1[1] = '\0';
	    error = !convert (encDec, s1, 0, s2); 
	    strcat (outStr, s2); 
	    inStr++;
	   } /* while */
	return (!error); 
}	/* encode */

/* ==================== decode ====================
	Transforms Morse Code data to character string
	   Pre    encDec is the conversion table
	          inStr contains data to transform to string
	   Post   data encoded and placed in outStr
	   Return TRUE  if all valid characters; 
	          FALSE if invalid character found
*/
int decode (char *(*encDec)[2], 
            char *inStr, 
            char *outStr) 
{
/*	Local Definitions */
	char  s1[6];
	char  s2[2];
	int   error = 0;
	int   i;

/*	Statements */
	outStr[0] ='\0';
	while (*inStr != '\0' && !error) 
	   {
	    for (i = 0; i < 5 && *inStr != '#'; i++, inStr++) 
	        s1[i] = *inStr;

	    s1[i]   = *inStr;
	    s1[++i] = '\0';

	    error = !convert (encDec, s1, 1, s2);
	    strcat (outStr, s2);
	    inStr++;
	   } /* while */
	return (!error);
} /* decode */

/*	==================== convert ====================
	Looks up code in table and converts to opposite format
	   Pre   encDec is a pointer decoding table
	         s1 is string being converted
	         s2 is output string
	          col is code: 0 for character to Morse
	                       1 for Morse to character
	   Post  converted output s2
*/
int convert (char *(*encDec)[2],
             char *s1, 
             int   col, 
             char *s2)
{
/*	Statements */
	int found = 0;
	int i;

	for (i = 0; i < 27 && !found; i++) 
	   found = !strcmp(s1, encDec[i][col]); 

	if (found)
	   strcpy (s2, encDec [i - 1][(col + 1) % 2]); 
	else
	   *s2 = '\0';

	return found;
}	/* convert */
/*	================= End of Program ================ */

/*	Results:
		            M E N U 
	        E)  encode 
	        D)  decode 
	        Q)  quit 

	Enter option: press return key: e

	Please enter line of text to be coded: 
	sos

	The information entered was: 
	sos

	The transformed information is: 
	...#---#...#
            M E N U 
	        E)  encode 
	        D)  decode 
	        Q)  quit 

	Enter option: press return key: d

	Please enter line of text to be coded: 
	...#---#...#

	The information entered was: 
	...#---#...#

	The transformed information is: 
	SOS
            M E N U 
	        E)  encode 
	        D)  decode 
	        Q)  quit 

	Enter option: press return key: q

	End of Morse Code.
*/
