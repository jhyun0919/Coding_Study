/* func.h */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include "header.h"


int Generate_Event();
void Init_Scheduler();
void Init_Track(Track T[]);
void Init_Elevator(EV *Elv);
void TextReader2Memory2Scheduler();
void Memory2Scheduler(Input_Info Info);
void RunEV();
void Append_Schedule4Independent_Event(Input_Info Info);
void Append_Schedule4Dependent_Event();
void Append_Input_Info(Input_Info Info);
void EraseScheculer();
int Scheduler2Track(Input_Info *Info);
void printBuilding();
int Track_On_Off(Track T);
int Count_Load_Passenger_Up(Track T);
int Count_Load_Passenger_Down(Track T);
int Priority_Selector(int level);


/*    global definitions */
Schedule Schedule4EV;
Track Track_Main[Max_Level];
Track Track_A[Max_Level];
Track Track_B[Max_Level];
EV Elv_A;
EV Elv_B;
int tick;
