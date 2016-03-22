/* func.h */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <math.h>



/*	prototype declaration */
int Generate_Event();
void TextReader2Memory2Scheduler();
void RunEV();
void Memory2Scheduler(Input_Info Info);
void Append_Schedule4Independent_Event(Input_Info Info);
void Append_Schedule4Dependent_Event();
void Append_Input_Info(Input_Info Info);
void Append_Event_DoorOpen_A();
void Append_Event_DoorOpen_B();
void EraseScheculer();
int Scheduler2Track(Input_Info *Info);
void Move_A();
void MoveUp_A();
void MoveDown_A();
int anyUpRequest_A();
int anyDownRequest_A();
int anyUpForecast_A();
int anyDownForecast_A();
void DoorOpen_A();
void Move_B();
void MoveUp_B();
void MoveDown_B();
int anyUpRequest_B();
int anyDownRequest_B();
int anyUpForecast_B();
int anyDownForecast_B();
void DoorOpen_B();
void printBuilding();
//int Count_Load_Passenger(Track T);
int Count_Load_Passenger_Up(Track T);
int Count_Load_Passenger_Down(Track T);
int Priority_Selector(int level);




/*	global definitions */ 
Schedule Schedule4EV;
Track Track_Main[Max_Level];
Track Track_A[Max_Level];
Track Track_B[Max_Level];
EV Elv_A;
EV Elv_B;
int tick;