/* header.h */


#define UP 1
#define DOWN 2
#define IDLE 3

#define ON 1
#define OFF 0

#define A 0
#define B 1

#define Max_Level 9



/* Elevator */

typedef struct EV {
	int cur_level;
	int direction;
	int weight;
} EV;



/* Input Information Format from textfile */

typedef struct Input_Info {
	int tick;
	int load_level;
	int direction;
	int passenger;
	int unload_level[20];
	struct Input_Info *next;
} Input_Info;



/* Scheduler */

typedef struct Scheduler {
	int tick;
	struct Scheduler *next;
	Input_Info *Info_ptr;
	
	
	int Door_SW_A;
	int Door_SW_B;
	//Event_Move *M_ptr;
	//Event_DoorOpen *DO_ptr;
} Scheduler;

typedef struct Scehdule { 
	Scheduler *head; 
	Scheduler *tail;
} Schedule;



/* Track structure */

typedef struct Track {
	struct In_Event *In_Up_ptr;
	struct In_Event *In_Down_ptr;
	int Out_passenger;
} Track;



/* In_Event Schedule structure */

typedef struct In_Event{
	int direction;
	int passenger;
	int unload_level[20];
	struct In_Event *next;
} In_Event;






/*
typedef struct Out_Event{
	int passenger;
	//int unload_level[20];
	struct Out_Event *next;
} Out_Event;

typedef struct Event_Move {
	int wer;
	//int tick;
	//void( *Move)();
} Event_Move;

typedef struct Event_DoorOpen {
	int wer;
	//int tick;
	//void ( *DoorOpen)();
}Event_DoorOpen;
*/
