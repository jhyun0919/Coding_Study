#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
//#include <windows.h>






Scheduler *head, *tail;

Track Track_1[Max_Level];

EV Elv;

int tick;





void Init_Scheduler(){
	head = (Scheduler *) malloc(sizeof(Scheduler));
	tail = (Scheduler *) malloc(sizeof(Scheduler));

	head->next = tail;

	head->tick = -1;
	tail->tick = 9999999;
}
void Init_Track(Track T[]){
	int i;

	for(i = 0; i < Max_Level; i++){
		T[i].In_ptr = NULL;
		T[i].Out_passenger = 0;
	}
}
void Init_Elevator(EV *Elv){
	Elv->cur_level = 0;
	Elv->direction = IDLE;
	Elv->weight = 0;
}



void Append_Schedule4Independent_Event(Input_Info Info){
	Scheduler * New_Schedule, *append_right;

	New_Schedule = (Scheduler *) malloc(sizeof(Scheduler));

	New_Schedule->tick = Info.tick;

	New_Schedule->Info_ptr = NULL;
	New_Schedule->Move_SW = OFF;
	New_Schedule->Door_SW = OFF;

	append_right = head;

	while(append_right->next != tail && append_right->next->tick < New_Schedule->tick){
		append_right = append_right->next;
	}
	if(append_right->next->tick != New_Schedule->tick){
		New_Schedule->next = append_right->next;
		append_right->next = New_Schedule;
	}
	else{
		free(New_Schedule);
	}
}
void Append_Schedule4Dependent_Event(){
	Scheduler * New_Schedule, *append_right;

	New_Schedule = (Scheduler *) malloc(sizeof(Scheduler));

	New_Schedule->tick = tick+1;

	New_Schedule->Info_ptr = NULL;
	New_Schedule->Move_SW = OFF;
	New_Schedule->Door_SW = OFF;

	append_right = head;

	while(append_right->next != tail && append_right->next->tick < New_Schedule->tick){
		append_right = append_right->next;
	}
	if(append_right->next->tick != New_Schedule->tick){
		New_Schedule->next = append_right->next;
		append_right->next = New_Schedule;
	}
	else{
		free(New_Schedule);
	}
}
void Append_Input_Info(Input_Info Info){
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

	/* link with Scheduler */
	search = head;
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
void Append_Event_Move(){
	Scheduler *search;
	
	Append_Schedule4Dependent_Event();

	/* connet Event_Move to Scheduler */
	search = head;
	while(search->tick != tick + 1){
		search = search->next;
	}
	search->Move_SW = ON;
}
void Append_Event_DoorOpen(){
	Scheduler *search;
	
	Append_Schedule4Dependent_Event();
	 
	/* connet Event_Move to Scheduler */
	search = head;
	while(search->tick != tick + 1){
		search = search->next;
	}
	search->Door_SW = ON;

}
void EraseScheculer(){
	Scheduler *hold;

	hold = head->next->next;
	free(head->next);
	head->next = hold;
}


void Text2Scheduler(Input_Info Info){
	/* make Scheduler tock = Info.tick */
	Append_Schedule4Independent_Event(Info);
	/* connet Input_Info to Scheduler */
	Append_Input_Info(Info);
}
int Scheduler2Track(Input_Info *Info){

	In_Event *New;
	Input_Info *temp, *erase;
	int i;
	int pushBlevel;


	temp = Info;
	do{
		/* assign memory space */
		New = (In_Event *) malloc(sizeof(In_Event));

		/* assign data Input_Info2In_Event */
		New->direction = Info->direction;
		New->passenger = Info->passenger;
		for(i = 0; i < New->passenger; i++){
			New->unload_level[i] = Info->unload_level[i];
		}
		for(i = New->passenger; i < 20; i++){
			New->unload_level[i] = 0;
		}
		New->next = NULL;

		/* connect In_Event to Track */
		Track_1[temp->load_level].In_ptr = New;
		pushBlevel = temp->load_level;

		/* move Input_Info *temp to the next one */
		/* erase garbage Input_Info memory space */
		erase = temp;
		temp = temp->next;
		free(erase);
	}while(temp !=NULL);

	Append_Event_Move();

	return pushBlevel;
}


void printBuidling(){
	int level;

	printf(" +------------+\n");
	for(level = Max_Level-1; level >= 0; level--){
		/* show level */
		printf(" |level: %2d   |\n", level);

		/* show in infomation */
		printf(" |in: ");
		if(Track_1[level].In_ptr != NULL){
			if(Track_1[level].In_ptr->direction == UP){
				printf("U %2d    ", Count_Load_Passenger(Track_1[level].In_ptr));
			}
			else if(Track_1[level].In_ptr->direction == DOWN){
				printf("D %2d    ", Count_Load_Passenger(Track_1[level].In_ptr));
			}
		}
		else{
			printf("        ");
		}
		printf("|");
		if(Elv.cur_level == level){

			printf(" < ");
			switch(Elv.direction){
			case UP: printf("U > "); break;
			case DOWN: printf("D > "); break;
			case IDLE: printf("- > "); break;
			}
			printf("weight: ");
		}
		printf("\n");

		/* show out infomation */
		printf(" |out: ");
		if(Track_1[level].Out_passenger != 0){
			printf("%2d", Track_1[level].Out_passenger);
		}
		else{
			printf("       ");
		}
		printf("|\n");
		printf(" +------------+\n");

	}

	printf("tick : %d\n", tick);
}

void MoveUp(){
	Elv.cur_level++;
	if(Track_On_Off(Track_1[Elv.cur_level])){
		/* ON */
		// 다음 tick에 Event_DoorOpen 예약
		Append_Event_DoorOpen();
	}
	else{
		/* OFF */
		// 다음 tick에 Event_Move 예약
		Append_Event_Move();
	}
}
void MoveDown(){
	Elv.cur_level--;
	if(Track_On_Off(Track_1[Elv.cur_level])){
		/* ON */
		// 다음 tick에 Event_DoorOpen 예약
		Append_Event_DoorOpen();
	}
	else{
		/* OFF */
		// 다음 tick에 Event_Move 예약
		Append_Event_Move();
	}
}
void Move(){
	int anyUp;
	int anyDown;

	anyUp = anyUpRequest();
	anyDown = anyDownRequest();

	if (Elv.direction == UP)
	{
		if (!anyUp && anyDown)
			Elv.direction = DOWN;
		else
			if (!anyUp && !anyDown)
				Elv.direction = IDLE;
	} /* UP */
	else if (Elv.direction == DOWN)
	{
		if (!anyDown && anyUp)
			Elv.direction = UP;
		else
			if (!anyDown && !anyUp)
				Elv.direction = IDLE;
	} /* DOWN */
	else if (Elv.direction == IDLE)
	{
		if (anyUp)
			Elv.direction = UP;
		else
			if (anyDown)
				Elv.direction = DOWN;
	} /* else if IDLE */

	if (Elv.direction == UP){
		MoveUp();
	}
	else{
		if (Elv.direction == DOWN)
			MoveDown();
		else{
			printf( "\n***** NO BUTTON PRESSED ***** " );
			sleep(1);
		}
	}

}

int anyUpRequest(){
	int check;
	int isAny = OFF;

	for(check = Elv.cur_level; check <= Max_Level && !isAny; check++){
		isAny = Track_On_Off(Track_1[check]);
	}
	return isAny;
}
int anyDownRequest(){
	int check;
	int isAny = OFF;

	for(check = Elv.cur_level; check >= 0; check--){
		isAny = isAny || Track_On_Off(Track_1[check]);
	}
	return isAny;
}


int Track_On_Off(Track T){
	if(T.In_ptr == NULL && T.Out_passenger == 0)	
		return OFF;
	else
		return ON;
}


void DoorOpen(){
	//Track_1[Elv.cur_level]

}

int Count_Load_Passenger(In_Event *In_ptr){
	int total_passenger = 0;

	do{
		total_passenger += In_ptr->passenger; 
		In_ptr = In_ptr->next;
	}while(In_ptr != NULL);


	return total_passenger;
}
