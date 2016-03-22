/* func_body.h */


#include "header.h"
#include "func.h"


void Init_Scheduler(){
	Schedule4EV.head = (Scheduler *) malloc(sizeof(Scheduler));
	Schedule4EV.tail = (Scheduler *) malloc(sizeof(Scheduler));

	Schedule4EV.head->next = Schedule4EV.tail;

	Schedule4EV.head->tick = -1;
	Schedule4EV.tail->tick = 99999999;
}
void Init_Track(Track T[]){
	int i;

	for(i = 0; i < Max_Level; i++){
		T[i].In_Up_ptr = NULL;
		T[i].In_Down_ptr = NULL;
		T[i].Out_passenger = 0;
	}
}
void Init_Elevator(EV *Elv){
	Elv->cur_level = 0;
	Elv->direction = IDLE;
	Elv->weight = 0;
}




void Memory2Scheduler(Input_Info Info){

	/* = read data from textfile and make Schedule = */
	// called from main function

	/* make a schedule on given tick for Independent Event */
	// Schedule tick = Info.tick
	Append_Schedule4Independent_Event(Info);
	
	/* connet Input_Info to the schedule */
	Append_Input_Info(Info);
}
void Append_Schedule4Independent_Event(Input_Info Info){

	/* = make a Schedule on given tick for Independent Event = */
	// called form void Text2Scheduler(Input_Info Info)

	/*	local definitions */
	Scheduler * New_Schedule, *append_right;

	/* assign memory space */
	New_Schedule = (Scheduler *) malloc(sizeof(Scheduler));

	/* assign tick */
	New_Schedule->tick = Info.tick;

	/* initialize */
	New_Schedule->Info_ptr = NULL;
	//New_Schedule->Move_SW = OFF;
	New_Schedule->Door_SW_A = OFF;
	New_Schedule->Door_SW_B = OFF;

	/* searching appropriate position */
	append_right = Schedule4EV.head;
	while(append_right->next != Schedule4EV.tail && append_right->next->tick < New_Schedule->tick){
		append_right = append_right->next;
	}
	/* insert New Schedule */
	if(append_right->next->tick != New_Schedule->tick){
		New_Schedule->next = append_right->next;
		append_right->next = New_Schedule;
	}
	/* a Schedule on given tick is already exist */
	/* free surplus New_Schedule memory */
	else{
		free(New_Schedule);
	}
}
void Append_Input_Info(Input_Info Info){
	
	/* = connect Input_Info to proper Schedule = */
	// called form void Text2Scheduler(Input_Info Info)
	
	/*	local definitions */
	Scheduler *search;
	Input_Info * New_Input_Info, *append_right;
	int i;

	/* assign memory space */
	New_Input_Info = (Input_Info *) malloc(sizeof(Input_Info));

	/* assign data */
	New_Input_Info->tick = Info.tick;
	New_Input_Info->load_level = Info.load_level;
	New_Input_Info->direction = Info.direction;
	New_Input_Info->passenger = Info.passenger;
	for(i = 0; i < Info.passenger; i++){
		New_Input_Info->unload_level[i] = Info.unload_level[i];
	}
	for(i = Info.passenger; i < 20; i++){
		New_Input_Info->unload_level[i] = 0;
	}
	New_Input_Info->next = NULL;

	/* connect Input_Info to Schedule */
	search = Schedule4EV.head;
	do{
		search = search->next;
	}while(search->tick != Info.tick);

	if(search->Info_ptr == NULL){
		search->Info_ptr = New_Input_Info;
	}
	else{
		append_right = search->Info_ptr;
		while(append_right->next != NULL){
			append_right = append_right->next;
		}
		append_right->next = New_Input_Info;
	}
}



void Append_Schedule4Dependent_Event(){

	/* = make a Schedule on given tick for Dependent Event = */
	// called form void Append_Event_Move()
	// called form void Append_Event_DoorOpen()

	/*	local definitions */
	Scheduler * New_Schedule, *append_right;

	/* assign memory space */
	New_Schedule = (Scheduler *) malloc(sizeof(Scheduler));
	
	/* assign tick */
	New_Schedule->tick = tick+1;

	/* initialize */
	New_Schedule->Info_ptr = NULL;
	//New_Schedule->Move_SW = OFF;
	New_Schedule->Door_SW_A = OFF;
	New_Schedule->Door_SW_B = OFF;

	/* searching appropriate position */
	append_right = Schedule4EV.head;
	while(append_right->next != Schedule4EV.tail && append_right->next->tick < New_Schedule->tick){
		append_right = append_right->next;
	}
	/* insert New Schedule */
	if(append_right->next->tick != New_Schedule->tick){
		New_Schedule->next = append_right->next;
		append_right->next = New_Schedule;
	}
	/* a Schedule on given tick is already exist */
	/* free surplus New_Schedule memory */
	else{
		free(New_Schedule);
	}
}

void Append_Event_DoorOpen_A(){

	/* = connect Event_DoorOpen to proper Schedule = */
	// called from void MoveUp(), only if the door need to be open at next tick
	// called from void MoveDown(), only if the door need to be open at next tick

	/*	local definitions */
	Scheduler *search;
	
	/* make a schedule on given tick for Dependent Event */
	// Schedule tick = Info.tick
	Append_Schedule4Dependent_Event();
	 
	/* connet Event_DoorOpen to Scheduler */
	search = Schedule4EV.head;
	while(search->tick != tick + 1){
		search = search->next;
	}
	search->Door_SW_A = ON;
}
void Append_Event_DoorOpen_B(){

	/* = connect Event_DoorOpen to proper Schedule = */
	// called from void MoveUp(), only if the door need to be open at next tick
	// called from void MoveDown(), only if the door need to be open at next tick

	/*	local definitions */
	Scheduler *search;
	
	/* make a schedule on given tick for Dependent Event */
	// Schedule tick = Info.tick
	Append_Schedule4Dependent_Event();
	 
	/* connet Event_DoorOpen to Scheduler */
	search = Schedule4EV.head;
	while(search->tick != tick + 1){
		search = search->next;
	}
	search->Door_SW_B = ON;
}




void EraseScheculer(){

	/* = erase passed Schedule = */
	// called from main funtion

	/*	local definitions */
	Scheduler *hold;

	/* erase the Schedule */
	hold = Schedule4EV.head->next->next;
	free(Schedule4EV.head->next);
	Schedule4EV.head->next = hold;
}



int Scheduler2Track(Input_Info *Info){

	/* = transfer information from Scheduler to Track when there is a Schedule at the tick = */
	// called from main function

	/*	local definitions */
	In_Event *New, *chosen, *target;
	Input_Info *temp, *erase;
	
	int i;
	int pushBlevel;
	int chosen_Elv;





	/* transfer information from Scheduler to Track */
	temp = Info;
	do{
		
		/* assign memory space */
		chosen = ( In_Event *) malloc(sizeof (In_Event));

		/* assign data Input_Info2In_Event */
		chosen->direction = temp->direction;
		chosen->passenger = temp->passenger;
		for(i = 0; i <chosen->passenger; i++){
			chosen->unload_level[i] = temp->unload_level[i];
		}
		for(i = chosen->passenger; i < 20; i++){
			chosen->unload_level[i] = 0;
		}
		chosen->next = NULL;

		/* select which elevator to be activated */
		chosen_Elv = Priority_Selector(temp->load_level);		//	누른 층 정보만 날린뒤, 엘베 선택받는다

		
		pushBlevel = temp->load_level;
		
		/* connect In_Event to chosen Track */
		switch(chosen_Elv){
		case A:
			{
				if(chosen->direction == UP){
					target = Track_A[temp->load_level].In_Up_ptr;
					if(target == NULL)
						Track_A[temp->load_level].In_Up_ptr = chosen;
					else{
						while(target->next != NULL){
							target = target->next;
						}
						target->next = chosen;
					}
				}
				else if(chosen->direction == DOWN){
					target = Track_A[temp->load_level].In_Down_ptr;
					if(target == NULL)
						Track_A[temp->load_level].In_Down_ptr = chosen;
					else{
						while(target->next != NULL){
							target = target->next;
						}
						target->next = chosen;
					}
				}
			}
			break;
		case B:
			{
				if(chosen->direction == UP){
					target = Track_B[temp->load_level].In_Up_ptr;
					if(target == NULL)
						Track_B[temp->load_level].In_Up_ptr = chosen;
					else{
						while(target->next != NULL){
							target = target->next;
						}
						target->next = chosen;
					}
				}
				else if(chosen->direction == DOWN){
					target = Track_B[temp->load_level].In_Down_ptr;
					if(target == NULL)
						Track_B[temp->load_level].In_Down_ptr = chosen;
					else{
						while(target->next != NULL){
							target = target->next;
						}
						target->next = chosen;
					}
				}
			}
			break;
		default:
			printf("connect In_Event to chosen Track error");
			exit(1);
		}
		


		/* move Input_Info *temp to the next one */
		/* erase garbage Input_Info memory space */
		erase = temp;
		temp = temp->next;
		free(erase);
	}while(temp !=NULL);

	//Append_Event_Move();

	return pushBlevel;
}



void Move_A(){

	/* = determine where to move : up/down/idle = */
	// called from main function at every tick

	/*	local definitions */
	int anyUp;
	int anyDown;

	anyUp = anyUpRequest_A();
	anyDown = anyDownRequest_A();

	if (Elv_A.direction == UP)
	{
		if (!anyUp && anyDown)
			Elv_A.direction = DOWN;
		else
			if (!anyUp && !anyDown)
				Elv_A.direction = IDLE;
	} /* UP */
	else if (Elv_A.direction == DOWN)
	{
		if (!anyDown && anyUp)
			Elv_A.direction = UP;
		else
			if (!anyDown && !anyUp)
				Elv_A.direction = IDLE;
	} /* DOWN */
	else if (Elv_A.direction == IDLE)
	{
		if (anyUp)
			Elv_A.direction = UP;
		else
			if (anyDown)
				Elv_A.direction = DOWN;
	} /* else if IDLE */

	if (Elv_A.direction == UP){
		MoveUp_A();
	}
	else{
		if (Elv_A.direction == DOWN)
			MoveDown_A();
		else{
			printBuilding();
			printf( "\n***** NO BUTTON PRESSED ***** \n" );
			Sleep(1000);
			system("cls");
		}
	}
}
void MoveUp_A(){

	/* = go one level up = */
	// called from void Move()

	/* go up */
	Elv_A.cur_level++;

	/* append Event_DoorOpen at next tick if EV has arrived */
	if(Track_A[Elv_A.cur_level].Out_passenger != 0){
		Append_Event_DoorOpen_A();	
	}
	if(Track_A[Elv_A.cur_level].In_Up_ptr != NULL){
		Append_Event_DoorOpen_A();
	}
	
	if(Track_A[Elv_A.cur_level].In_Down_ptr != NULL){
		if(Elv_A.cur_level == Max_Level){
			Append_Event_DoorOpen_A();
			Elv_A.direction = DOWN;
		}
		else if(anyUpForecast_A() == OFF){
			Append_Event_DoorOpen_A();
			Elv_A.direction = DOWN;
		}
	}
}

void MoveDown_A(){

	/* = go one level down = */
	// called from void Move()

	

	/* go down */
	Elv_A.cur_level--;

	/* append Event_DoorOpen at next tick if EV has arrived */
	if(Track_A[Elv_A.cur_level].Out_passenger != 0){
		Append_Event_DoorOpen_A();
	}
	if(Track_A[Elv_A.cur_level].In_Down_ptr != NULL){
			Append_Event_DoorOpen_A();
	}	

	if(Track_A[Elv_A.cur_level].In_Up_ptr != NULL){
		if(Elv_A.cur_level == 0){
			Append_Event_DoorOpen_A();
			Elv_A.direction = UP;
		}
		else if(anyDownForecast_A() == OFF){
			Append_Event_DoorOpen_A();
			Elv_A.direction = UP;
			return;
		}
	}
}
int anyUpRequest_A(){

	/* = check any up request = */
	//called from void Move()

	/*	local definitions */
	int check;
	int isAny = OFF;

	/* check is there any request to move up */
	// request exit : isAny = ON
	// no request : isAny = OFF
	for(check = Elv_A.cur_level; check < Max_Level && !isAny; check++){
		isAny = Track_On_Off(Track_A[check]);
	}

	return isAny;
}
int anyDownRequest_A(){

	/* = check any down request = */
	//called from void Move()

	/*	local definitions */
	int check;
	int isAny = OFF;

	/* check is there any request to move down */
	// request exit : isAny = ON
	// no request : isAny = OFF
	for(check = Elv_A.cur_level; check >= 0; check--){
		isAny = isAny || Track_On_Off(Track_A[check]);
	}

	return isAny;
}
int anyUpForecast_A(){

	/* = check any up request = */
	//called from void Move()

	/*	local definitions */
	int check;
	int isAny = OFF;

	/* check is there any request to move up */
	// request exit : isAny = ON
	// no request : isAny = OFF
	for(check = Elv_A.cur_level + 1; check < Max_Level && !isAny; check++){
		isAny = Track_On_Off(Track_A[check]);
	}

	return isAny;
}
int anyDownForecast_A(){

	/* = check any down request = */
	//called from void Move()

	/*	local definitions */
	int check;
	int isAny = OFF;

	/* check is there any request to move down */
	// request exit : isAny = ON
	// no request : isAny = OFF
	for(check = Elv_A.cur_level - 1; check >= 0; check--){
		isAny = isAny || Track_On_Off(Track_A[check]);
	}

	return isAny;
}
void Move_B(){

	/* = determine where to move : up/down/idle = */
	// called from main function at every tick

	/*	local definitions */
	int anyUp;
	int anyDown;

	anyUp = anyUpRequest_B();
	anyDown = anyDownRequest_B();

	if (Elv_B.direction == UP)
	{
		if (!anyUp && anyDown)
			Elv_B.direction = DOWN;
		else
			if (!anyUp && !anyDown)
				Elv_B.direction = IDLE;
	} /* UP */
	else if (Elv_B.direction == DOWN)
	{
		if (!anyDown && anyUp)
			Elv_B.direction = UP;
		else
			if (!anyDown && !anyUp)
				Elv_B.direction = IDLE;
	} /* DOWN */
	else if (Elv_B.direction == IDLE)
	{
		if (anyUp)
			Elv_B.direction = UP;
		else
			if (anyDown)
				Elv_B.direction = DOWN;
	} /* else if IDLE */

	if (Elv_B.direction == UP){
		MoveUp_B();
	}
	else{
		if (Elv_B.direction == DOWN)
			MoveDown_B();
		else{
			printBuilding();
			printf( "\n***** NO BUTTON PRESSED ***** \n" );
			Sleep(1000);
			system("cls");
		}
	}
}
void MoveUp_B(){

	/* = go one level up = */
	// called from void Move()

	

	/* go up */
	Elv_B.cur_level++;

	/* append Event_DoorOpen at next tick if EV has arrived */
	if(Track_B[Elv_B.cur_level].Out_passenger != 0){
		Append_Event_DoorOpen_B();	
	}
	if(Track_B[Elv_B.cur_level].In_Up_ptr != NULL){
		Append_Event_DoorOpen_B();
	}
	
	if(Track_B[Elv_B.cur_level].In_Down_ptr != NULL){
		if(Elv_B.cur_level == Max_Level){
			Append_Event_DoorOpen_B();
			Elv_B.direction = DOWN;
		}
		else if(anyUpForecast_B() == OFF){
			Append_Event_DoorOpen_B();
			Elv_B.direction = DOWN;
			return;
		}
	}
	
}
void MoveDown_B(){

	/* = go one level down = */
	// called from void Move()

	

	/* go down */
	Elv_B.cur_level--;

	/* append Event_DoorOpen at next tick if EV has arrived */
	if(Track_B[Elv_B.cur_level].Out_passenger != 0){
		Append_Event_DoorOpen_B();
	}
	if(Track_B[Elv_B.cur_level].In_Down_ptr != NULL){
			Append_Event_DoorOpen_B();
	}
	
	if(Track_B[Elv_B.cur_level].In_Up_ptr != NULL){
		if(Elv_B.cur_level == 0){
			Append_Event_DoorOpen_B();
			Elv_B.direction = UP;
		}
		else if(anyDownForecast_B() == OFF){
			Append_Event_DoorOpen_B();
			Elv_B.direction = UP;
		}
	}
		
}
int anyUpRequest_B(){

	/* = check any up request = */
	//called from void Move()

	/*	local definitions */
	int check;
	int isAny = OFF;

	/* check is there any request to move up */
	// request exit : isAny = ON
	// no request : isAny = OFF
	for(check = Elv_B.cur_level; check < Max_Level && !isAny; check++){
		isAny = Track_On_Off(Track_B[check]);
	}

	return isAny;
}
int anyDownRequest_B(){

	/* = check any down request = */
	//called from void Move()

	/*	local definitions */
	int check;
	int isAny = OFF;

	/* check is there any request to move down */
	// request exit : isAny = ON
	// no request : isAny = OFF
	for(check = Elv_B.cur_level; check >= 0; check--){
		isAny = isAny || Track_On_Off(Track_B[check]);
	}

	return isAny;
}
int anyUpForecast_B(){

	/* = check any up request = */
	//called from void Move()

	/*	local definitions */
	int check;
	int isAny = OFF;

	/* check is there any request to move up */
	// request exit : isAny = ON
	// no request : isAny = OFF
	for(check = Elv_B.cur_level + 1; check < Max_Level && !isAny; check++){
		isAny = Track_On_Off(Track_B[check]);
	}

	return isAny;
}
int anyDownForecast_B(){

	/* = check any down request = */
	//called from void Move()

	/*	local definitions */
	int check;
	int isAny = OFF;

	/* check is there any request to move down */
	// request exit : isAny = ON
	// no request : isAny = OFF
	for(check = Elv_A.cur_level - 1; check >= 0; check--){
		isAny = isAny || Track_On_Off(Track_B[check]);
	}

	return isAny;
}

int Track_On_Off(Track T){

	/* = check is there any reguest in given level = */
	//called from int anyUpRequest()
	//called from int anyDownRequest()


	if(T.In_Up_ptr == NULL && T.In_Down_ptr == NULL && T.Out_passenger == 0)	
		return OFF;
	else
		return ON;
}



void DoorOpen_A(){

	/* = open the door and load or/and unload passengers = */
	// called from main function, only if Door_SW is ON in its tick

	/*	local definitions */
	int i;
	In_Event * temp_Up, *temp_Down, *erase;

	/* Out_Event : unload passegner */
	if(Track_A[Elv_A.cur_level].Out_passenger != 0){
		Track_A[Elv_A.cur_level].Out_passenger = 0;
	}


	/* In_Event : load pasenger */
	// 나중에 weight에 대한 코드 추가할 것!!!
	/* direction : Up */
	if(Track_A[Elv_A.cur_level].In_Up_ptr != NULL && Elv_A.direction == UP){
		temp_Up = Track_A[Elv_A.cur_level].In_Up_ptr;
		while(temp_Up != NULL){
			/* assign each passenger to each unload_level */
			for( i = 0; i < temp_Up->passenger; i++){
				Track_A[temp_Up->unload_level[i] 	// 해당 층의 In_Up_ptr의 unload_level배열의 값 = 내릴 층			
				].Out_passenger++;
			}
			erase = temp_Up;
			temp_Up = temp_Up->next;
			free(erase);
		}
		Track_A[Elv_A.cur_level].In_Up_ptr = NULL;
	}

	/* direction : Down */
	if(Track_A[Elv_A.cur_level].In_Down_ptr != NULL && Elv_A.direction == DOWN){
		temp_Down = Track_A[Elv_A.cur_level].In_Down_ptr;
		while(temp_Down != NULL){
			/* assign each passenger to each unload_level */
			for( i = 0; i < temp_Down->passenger; i++){
				Track_A[temp_Down->unload_level[i] 	// 해당 층의 In_Down_ptr의 unload_level배열의 값 = 내릴 층			
				].Out_passenger++;
			}
			erase = temp_Down;
			temp_Down = temp_Down->next;
			free(erase);
		}
		Track_A[Elv_A.cur_level].In_Down_ptr = NULL;
	}
}
void DoorOpen_B(){

	/* = open the door and load or/and unload passengers = */
	// called from main function, only if Door_SW is ON in its tick

	/*	local definitions */
	int i;
	In_Event * temp_Up, *temp_Down, *erase;

	/* Out_Event : unload passegner */
	if(Track_B[Elv_B.cur_level].Out_passenger != 0){
		Track_B[Elv_B.cur_level].Out_passenger = 0;
	}


	/* In_Event : load pasenger */
	// 나중에 weight에 대한 코드 추가할 것!!!
	/* direction : Up */
	if(Track_B[Elv_B.cur_level].In_Up_ptr != NULL && Elv_B.direction == UP){
		temp_Up = Track_B[Elv_B.cur_level].In_Up_ptr;
		while(temp_Up != NULL){
			/* assign each passenger to each unload_level */
			for( i = 0; i < temp_Up->passenger; i++){
				Track_B[temp_Up->unload_level[i] 	// 해당 층의 In_Up_ptr의 unload_level배열의 값 = 내릴 층			
				].Out_passenger++;
			}
			erase = temp_Up;
			temp_Up = temp_Up->next;
			free(erase);
		}
		Track_B[Elv_B.cur_level].In_Up_ptr = NULL;
	}

	/* direction : Down */
	if(Track_B[Elv_B.cur_level].In_Down_ptr != NULL && Elv_B.direction == DOWN){
		temp_Down = Track_B[Elv_B.cur_level].In_Down_ptr;
		while(temp_Down != NULL){
			/* assign each passenger to each unload_level */
			for( i = 0; i < temp_Down->passenger; i++){
				Track_B[temp_Down->unload_level[i] 	// 해당 층의 In_Down_ptr의 unload_level배열의 값 = 내릴 층			
				].Out_passenger++;
			}
			erase = temp_Down;
			temp_Down = temp_Down->next;
			free(erase);
		}
		Track_B[Elv_B.cur_level].In_Down_ptr = NULL;
	}
}


void printBuilding(){

	int level;

	printf("   Elv_A   ");
	printf("+---------------+");
	printf("   Elv_B   ");
	printf("\n");
	//===========================
	for(level = Max_Level-1; level >= 0; level--){

		if(Elv_A.cur_level == level){
			printf("   < ");
			switch(Elv_A.direction){
			case UP: printf("U"); break;
			case DOWN: printf("D"); break;
			case IDLE: printf("-"); break;
			}
			printf(" >   ");
		}
		else{
			printf("           ");
		}

		printf("|     F : %2d    |", level);

		if(Elv_B.cur_level == level){
			printf("   < ");
			switch(Elv_B.direction){
			case UP: printf("U"); break;
			case DOWN: printf("D"); break;
			case IDLE: printf("-"); break;
			}
			printf(" >   ");
		}
		else{
			printf("           ");
		}

		printf("\n");
		//===========================
		if(Elv_A.cur_level == level){
			printf("weight:    ");
		}
		else{
			printf("           ");
		}
		printf("|");
		printf("A_in: ");

		if(Track_A[level].In_Up_ptr != NULL && Track_A[level].In_Down_ptr == NULL){
			printf("U %2d     ", Count_Load_Passenger_Up(Track_A[level]));
		}
		else if(Track_A[level].In_Down_ptr != NULL && Track_A[level].In_Up_ptr == NULL){
			printf("D %2d     ", Count_Load_Passenger_Down(Track_A[level]));
		}
		else if(Track_A[level].In_Down_ptr != NULL && Track_A[level].In_Up_ptr != NULL){
			printf("U/D %2d   ", Count_Load_Passenger_Up(Track_A[level]) + Count_Load_Passenger_Down(Track_A[level]));
		}
		else{
			printf("         ");
		}
		printf("|");

		if(Elv_B.cur_level == level){
			printf("weight:    ");
		}
		else{
			printf("           ");
		}
		printf("\n");
		//===========================
		printf("           ");
		printf("|");
		printf("B_in: ");

		if(Track_B[level].In_Up_ptr != NULL && Track_B[level].In_Down_ptr == NULL){
			printf("U %2d     ", Count_Load_Passenger_Up(Track_B[level]));
		}
		else if(Track_B[level].In_Down_ptr != NULL && Track_B[level].In_Up_ptr == NULL){
			printf("D %2d     ", Count_Load_Passenger_Down(Track_B[level]));
		}
		else if(Track_B[level].In_Down_ptr != NULL && Track_B[level].In_Up_ptr != NULL){
			printf("U/D %2d   ", Count_Load_Passenger_Up(Track_B[level]) + Count_Load_Passenger_Down(Track_B[level]));
		}
		else{
			printf("         ");
		}
		printf("|");
		printf("\n");
		//===========================
		printf("           ");
		printf("|");
		printf("A_out: ");
		if(Track_A[level].Out_passenger != 0){
			printf("%2d      ", Track_A[level].Out_passenger);
		}
		else{
			printf("        ");
		}
		printf("|");
		printf("\n");
		//===========================
		printf("           ");
		printf("|");
		printf("B_out: ");
		if(Track_B[level].Out_passenger != 0){
			printf("%2d      ", Track_B[level].Out_passenger);
		}
		else{
			printf("        ");
		}
		printf("|");
		printf("\n");
		//===========================
		printf("           ");
		printf("+---------------+");
		printf("\n");
	}

	printf("tick : %d\n", tick);

}
/*
int Count_Load_Passenger(Track T){
	int total_passenger = 0;

	total_passenger = Count_Load_Passenger_Up(T) + Count_Load_Passenger_Down(T);

	return total_passenger;
}
*/
int Count_Load_Passenger_Up(Track T){

	/* = count number of passengers who are waiting the elevator to load in the given level = */
	// call from void printBuidling()
	// return int total_passenger

	/*	local definitions */
	int total_passenger = 0;
	In_Event *temp;

	/* count passenger number who go up */
	temp = T.In_Up_ptr;
	do{
		total_passenger += T.In_Up_ptr->passenger; 
		temp = temp->next;
	}while(temp != NULL);

	return total_passenger;
}
int Count_Load_Passenger_Down(Track T){

	/* = count number of passengers who are waiting the elevator to load in the given level = */
	// call from void printBuidling()
	// return int total_passenger

	/*	local definitions */
	int total_passenger = 0;
	In_Event *temp;

	/* count passenger number who go down */
	temp = T.In_Down_ptr;
	do{
		total_passenger += T.In_Down_ptr->passenger; 
		temp = temp->next;
	}while(temp != NULL);

	return total_passenger;
}


void TextReader2Memory2Scheduler(){
	FILE *fp = NULL;
	Input_Info temp = {0, 0, 0, 0, {0, }};
	int i, j;

	fp = fopen("Input_Data.txt", "r");
	if(fp == NULL){
		printf("file open error\n");
		exit(1);
	}

	for(i = 0; i < 4; i++){
		fscanf(fp, "%d %d %d %d",&temp.tick, &temp.load_level, &temp.direction, &temp.passenger );
		for(j = 0; j < temp.passenger; j++)
		{
			fscanf(fp, "%d",&temp.unload_level[j]);
		}
		temp.next = NULL;

		Memory2Scheduler(temp);
	}

	if(feof(fp) != 0){
		printf("TextReader2Memory success!\n");
		Sleep(3000);
	}
	else{
		printf("TextReader2Memory error\n");
		Sleep(3000);
	}

	if(fclose(fp) == EOF){
		printf("file close error\n");
		exit(1);
	}
	system("cls"); 
}
void RunEV(){

	int pushBlevel;
	int term_A = 0, term_B = 0;
	int i;

	tick = 0;

	while(1){

		if(term_A == 0){
			Move_A();
			printBuilding();
			//printf("Moving\n");
			Sleep(1000);
			system("cls");
		}

		else{
				term_A--;
				printBuilding();
				printf("Door A is Opened!!!\n");
				printf("time left : %d\n", term_A);
				Sleep(1000);
				system("cls"); 
		}

		if(term_B == 0){
			Move_B();
			printBuilding();
			//printf("Moving\n");
			Sleep(1000);
			system("cls");
		}

		else{
				term_B--;
				printBuilding();
				printf("Door B is Opened!!!\n");
				printf("time left : %d\n", term_B);
				Sleep(1000);
				system("cls"); 
		}

		tick++;
		
		/* main의 tick이 Scheduler의 첫번째 Schedule의 tick과 일치할 때 */
		if(tick == Schedule4EV.head->next->tick){
			
			/* connect In_Event to Track_Main */
			if(Schedule4EV.head->next->Info_ptr != NULL){
				pushBlevel = Scheduler2Track(Schedule4EV.head->next->Info_ptr);
				printBuilding();
				printf("Someone Push the Butten on level %d!!!\n", pushBlevel);
				Sleep(3000);
				system("cls");
			}

			
			/* Event_DoorOpen */
			if(Schedule4EV.head->next->Door_SW_A == ON){
				printBuilding();
				DoorOpen_A();
				printf("Door A is Opened!!!\n");

				

				term_A = 5;
				printf("time left : %d\n", term_A - 1);
				Sleep(3000);
				system("cls");
				
			}
			if(Schedule4EV.head->next->Door_SW_B == ON){
				printBuilding();
				DoorOpen_B();
				printf("Door B is Opened!!!\n");

				

				term_B = 5;
				printf("time left : %d\n", term_B - 1);
				Sleep(3000);
				system("cls");
				
			}
			
			EraseScheculer();
		}
				

		/*send/recv 함수*/
	}
}

/*
int Generate_Event(){
	FILE *fp = NULL;
	int Event_num;
	int i;

	
	printf("input a number of events : ");
	scanf("%d", &Event_num);



	fp = fopen("Input_Data.txt", "w");
	if(fp == NULL){
		printf("file open error\n");
		exit(1);
	}

	for(i = 0; i < Event_num; i++){


	}




	if(fclose(fp) == EOF){
		printf("file close error\n");
		exit(1);
	}

	return Event_num;
}
*/

int Priority_Selector(int level){

	int distance_A, distance_B;

	distance_A = abs(Elv_A.cur_level - level);
	distance_B = abs(Elv_B.cur_level - level);

	if(distance_A <= distance_B)
		return A;	
	else
		return B;
}

