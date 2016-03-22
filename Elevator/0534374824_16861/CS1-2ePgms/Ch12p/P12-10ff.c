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

/*	This program simulates the operation of an elevator.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TOP_FLOOR 10
#define DELAY_FACTOR 10000

typedef enum {OUT, IN} BUTTON_STATUS;
typedef enum {DOWN, STOP, UP} DIRECTION_STATUS;
typedef struct 
	{
	 int             currentFloor;
	 BUTTON_STATUS  *buttons;
	} ELEVATOR; 

/*	Prototype Declaration */
void initialize      (ELEVATOR *elev); 
void runElevator     (ELEVATOR *elev); 
void terminate       (ELEVATOR *elev); 
void move            (ELEVATOR *elev); 
int  anyUpRequest    (ELEVATOR *elev); 
int  anyDownRequest  (ELEVATOR *elev); 
void moveUp          (ELEVATOR *elev); 
void moveDown        (ELEVATOR *elev); 
void timePass        (int m); 

int main (void) 
{
/*	Local Definitions */ 
ELEVATOR elevator; 

/*	Statements */
	initialize  (&elevator);
	runElevator (&elevator);
	terminate   (&elevator);

	return 0;
}	/* main */

/*	================== initialize ================== 
	This function dynamically allocates memory locations for 
	the buttons and initializes the current floor to 1 to show 
	that the elevator is parked in the first floor. 
	   Pre   nothing 
	   Post  elevator created, all buttons reset, and
	         parked at first floor (not basement)
*/
void initialize (ELEVATOR *elev) 
{
/*	Local Definitions */
	int i;

/*	Statements */
	elev->buttons = 
	    (BUTTON_STATUS *) calloc(TOP_FLOOR + 1, 
	        sizeof (BUTTON_STATUS));

	for (i = 0; i <= TOP_FLOOR; i++) 
	   elev->buttons [i] = OUT;
	elev->currentFloor = 1; 

	return;
}	/* initialize */

/*	================= runElevator =================== 
	Simulate the operation of the elevator. 
	   Pre   elevator structure has been initialized
	   Post  simulation is complete
*/
void runElevator (ELEVATOR *elev) 
{
/*	Local Definitions */
	char  buffer [81]; 
	int   floor; 
	char *pStrIn;
	
/*	Statements */
	printf("\n\nThis elevator goes from basement (0) "); 
	printf("to floor %d", TOP_FLOOR); 
	printf(    "\n\nType floors & press return key to start"); 
	printf(   "\nIf no new floors, just press return key."); 
	printf("\nTo quit, key EOF"); 
	printf("\n\nPlease enter floors: "); 

	while (fgets(buffer, 81, stdin)) 
	   {
	    pStrIn = buffer;
	    while (*pStrIn != '\n')
	       {
	        /* Locate next floor digit & convert to int */
	       while (*pStrIn == ' ')
	          pStrIn++;
	       if (!isdigit (*pStrIn)) 
	          {
	           printf("\aInvalid floor %c\n", *pStrIn); 
	           pStrIn++;
	          } /* if */
	       else
	          {
	          sscanf (pStrIn, "%d", &floor); 
	          if (floor  == elev->currentFloor) 
	              printf("\n\aAlready on floor %d.", 
	                     elev->currentFloor); 
	          else 
	             if (floor < 0 || floor > TOP_FLOOR) 
	                 printf("\n\a%d is not a valid floor", 
	                       floor); 
	             else
	                 elev->buttons [floor] = IN; 

	          /* Synchronize sscanf & *pStrIn */
	          while (isdigit (*pStrIn))
	             pStrIn++; 
	         } /* else */
	       } /* while */

	    move (elev);
	    printf("\n\nPlease enter floors: "); 
	} /* while */
	return ;
}	/* runElevator */

/*	=================== move ===================
	Moves the elevator to a requested floor. It stops
	the elevator after responding to one request.
	   Pre   given elevator
	   Post  elevator has been moved--while it is 
	         moving, the floors are called out
*/
void move (ELEVATOR *elev) 
{
/*	Local Definitions */
	static DIRECTION_STATUS direction = STOP;
	
	int anyUp;
	int anyDown;

/*	Statements */
	anyUp    = anyUpRequest   (elev);
	anyDown  = anyDownRequest (elev);

	if (direction == UP)
	   {
	    if (!anyUp && anyDown)
	        direction = DOWN;
	    else
	        if (!anyUp && !anyDown)
	            direction = STOP;
	   } /* UP */
	
	else if (direction == DOWN)
	   {
	    if (!anyDown && anyUp)
	        direction = UP;
	    else
	        if (!anyDown && !anyUp)
	            direction = STOP;
	   } /* DOWN */
	
	else if (direction == STOP)
	   {
	    if (anyUp)
	        direction = UP;
	    else
	        if (anyDown)
	            direction = DOWN;
	   } /* else if stop */

	if (direction == UP) 
	    moveUp (elev); 
	else
	    if (direction == DOWN)
	        moveDown (elev);
	    else
	        printf("\n***** NO BUTTON PRESSED ***** "); 
	return;
}	/* move */

/*	=================== moveUp ===================
	This function simulates the movement of the elevator when
	it is going up.
	   Pre   given moving up elevator
	   Post  up simulation is displayed on the screen 
*/
void  moveUp (ELEVATOR *elev) 
{
/*	Statements */
	printf ("\nThe door is being closed ?);
	printf ("\nWe are going up.");
	(elev->currentFloor)++;
	while (elev->buttons[elev->currentFloor] != IN)
	   {
	    printf("\n"); 
	    timePass (2); 
	    printf("\nPassing floor %d", elev->currentFloor); 
	    printf("\n "); 
	    timePass (2);
	    (elev->currentFloor)++; 
	   } /* while */

	elev->buttons [elev->currentFloor] = OUT;
	printf("\nThe door is  being opened ?);
	printf("\n");
	printf("\n ***** FLOOR %d ***** ", elev->currentFloor); 
	printf("\n"); 
	timePass(4); 
	return;
}	/* moveUp */

/*	==================== moveDown ====================
	This function simulates the movement of the elevator when 
	it is going down.
	   Pre   given moving down elevator 
	   Post  down simulation is displayed on the screen 
*/
void moveDown (ELEVATOR *elev)
{
/*	Statements */
	printf("\nThe door is being closed ?); 
	printf("\nWe are going down"); 
	(elev->currentFloor)--;
	while (elev->buttons [elev ->currentFloor] != IN) 
	   {
	    printf("\n"); 
	    timePass (2); 
	    printf("\nPassing floor %d", elev->currentFloor); 
	    printf("\n"); 
	    timePass (2);
	    (elev->currentFloor)--; 
	   } /* while */
	elev->buttons [elev->currentFloor] = OUT;
	printf("\nThe door is being opened ?);
	printf("\n ");
	printf("\n ***** FLOOR %d ***** ", elev->currentFloor);
	printf("\n"); 
	timePass (4); 

	return;
}	/* moveDown */

/*	================= anyUpRequest =================== 
	This function checks to see if any request is for a floor 
	above the current floor.
	   Pre   given elevator
	   Post  return 1 if button above current floor pushed
	         return 0 otherwise.
*/
int anyUpRequest (ELEVATOR *elev) 
{
/*	Local Definitions */
	int  check;
	int  isAny = 0;

/*	Statements */
	for (check = elev->currentFloor; check <= TOP_FLOOR && !isAny; check++) 
	   isAny = (elev->buttons[check] == IN);

	return isAny;
}	/* anyUpRequest */

/*	================== anyDownRequest ================== 
	This function checks to see if any request is for a floor 
	below the current floor.
	   Pre   given elevator 
	   Post  return 1 if button below current floor pushed
	         return 0 otherwise
*/
int anyDownRequest (ELEVATOR *elev)
{
/*	Local Definitions */
	int  check;
	int  isAny = 0;

/*	Statements */
	for (check = elev->currentFloor; check >=  0; check--)
	   isAny = isAny || (elev->buttons[check] == IN);

	return isAny;
}	/* anyDownRequest */

/*	================== timePass ==================
	This function simulates the concept of passing time by 
	executing an empty for-loop.
	   Pre   time to be passed (number of moments)
	   Post  time has passed
*/
void timePass  (int time) 
 {
/*	Local Definitions */
	long  i;

/*	Statements */
	for (i = 0; i < (time * DELAY_FACTOR); i++) 
	   ;
	return; 
}	/* timePass */

/*	================= terminate =================
	Release the memory occupied by buttons.
	   Pre   given elevator
	   Post  elevator memory is released
*/
void terminate (ELEVATOR *elev) 
{
/* Statements */
	free (elev->buttons); 
	return ;
}	/* terminate */
/*	================== End of Program ================== */

/*	Results:
	This elevator goes from basement (0) to floor 10

	Type floors & press return key to start
	If no new floors, just press return key.
	To quit, key EOF

	Please enter floors: 3

	The door is being closed ?
	We are going up.

	Passing floor 2
 
	The door is  being opened ?

	 ***** FLOOR 3 ***** 


	Please enter floors: 4 5 6 1
	
	The door is being closed ?
	We are going up.
	The door is  being opened ?

	 ***** FLOOR 4 ***** 


	Please enter floors: 
	
	The door is being closed ?
	We are going up.
	The door is  being opened ?

	 ***** FLOOR 5 ***** 


	Please enter floors: 

	The door is being closed ?
	We are going up.
	The door is  being opened ?

	 ***** FLOOR 6 ***** 


	Please enter floors: 

	The door is being closed ?
	We are going down

	Passing floor 5


	Passing floor 4


	Passing floor 3


	Passing floor 2

	The door is being opened ?
 
	 ***** FLOOR 1 ***** 
	
	
	Please enter floors: 1

	Already on floor 1.
	***** NO BUTTON PRESSED ***** 

	Please enter floors: ^d
*/
