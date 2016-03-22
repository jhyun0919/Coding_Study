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

/*	Test driver for process controlled loop function.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>

/*	Prototype Declarations */
int  getTemperature  (void);
void turnOnHeater    (void);
void turnOffHeater   (void);
void turnOnAirCond   (void);
void turnOffAirCond  (void);

int main (void)
{
/*	Local Definitions */
	int temp;
	
/*	Statements */
	printf("\n\nHeater off: Air Conditioner: off   \r");
while (1)
	{
	 temp = getTemperature();
	 if (temp < 68)
	     turnOnHeater();
	 else if (temp > 78)
	     turnOnAirCond();
	 else
	    {
	     turnOffHeater();
	     turnOffAirCond();
	    } /* else */
	} /* while 1 */     

	return 0;
}	/* main */

/*	================ getTemperature ================
	Simulate reading temperature using random numbers.
	   Pre   nothing
	   Post  temperature in range 50..90 returned.
*/
int getTemperature (void)
{
/*	Local Definitions */
	int  temp;
	long timeLoop;
	
/*	Statements */
	temp = rand() % 41 + 50;
	
	/* Timing loop delay */
	for (timeLoop = 2000000 ; timeLoop; timeLoop--)
	    ;
	
	return temp;
}	/* getTemperature */

/*	================ turnOnHeater ================
	Stub: Prints heater turned on
		Pre   nothing
		Post  stub message printed
*/
void turnOnHeater (void)
{
/*	Statements */
	printf("Heater  on: Air Conditioner: off\r   ");
	return;
}	/* turnOnHeater */
 
/*	================ turnOffHeater ================
	Stub: Prints heater turned off
		Pre   nothing
		Post  stub message printed
*/
void turnOffHeater (void)
{
/*	Statements */
	printf("Heater off: Air Conditioner: off\r   ");
	return;
}	/* turnOffHeater */
 
/*	================ turnOnAirCond ================
	Stub: Prints heater turned on
		Pre   nothing
		Post  stub message printed
*/
void turnOnAirCond (void)
{
/*	Statements */
	printf("Heater off: Air Conditioner:  on\r   ");
	return;
}	/* turnOnAirCond */
 
/*	================ turnOffAirCond ================
	Stub: Prints air conditioner turned off
		Pre   nothing
		Post  stub message printed
*/
void turnOffAirCond (void)
{
/*	Statements */
	printf("Heater off: Air Conditioner: off\r   ");
	return;
}	/* turnOffAirCond */
