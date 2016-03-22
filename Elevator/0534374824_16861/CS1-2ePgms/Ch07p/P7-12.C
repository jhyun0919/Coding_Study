
/*	Test driver for getUnitsSold
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <ctype.h>

/*	Prototype Declarations */
	int getUnitsSold (void);

#define FLUSH while (getchar() != '\n')
#define TRUE   1
#define FALSE  0

int main (void)
{
/*	Statements */
	getUnitsSold();
	return 0;
}	/* main */

/*	This function reads the units sold from the keyboard and 
	verifies the data with the user.
	   Pre   nothing
	   Post  units Sold read, verified, and returned
*/
int getUnitsSold (void)
{
	int  unitsSold;
	int  valid;

do
	{
	 printf("\nPlease enter Number of Units Sold: ");
	   while (scanf("%d", &unitsSold) != 1)
	      {
	       FLUSH;
	       printf("\aInvalid number. Please re-enter: ");
	      }  /* while */
	   printf("\nVerify Units Sold: %d: ", unitsSold);
	   printf("<Y> correct: <N> not correct: \n");
	   FLUSH;
	   if (toupper(getchar ()) == 'Y')
	       valid = TRUE;
	   else
	      {
	       FLUSH;
	       printf("\nYou responded 'no.' ");
	       printf("Please re-enter Units Sold\n");
	       valid = FALSE;
	       } /* if */	
	} while (!valid);
return unitsSold;
} /* getUnitsSold */

/*	Results:
	Please enter Number of Units Sold: a
	Invalid number. Please re-enter: 15

	Verify Units Sold: 15: <Y> correct: <N> not correct: 
	n

	You responded 'no.' Please re-enter Units Sold

	Please enter Number of Units Sold: 16
	Verify Units Sold: 16: <Y> correct: <N> not correct: 
	y
*/

