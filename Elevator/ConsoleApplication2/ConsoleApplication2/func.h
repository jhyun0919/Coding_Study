/* func.h */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>



/*    prototype declaration */
int Generate_Event();
void TextReader2Memory2Scheduler();
//void TextReader2Memory2Scheduler(int Event_Num);
void RunEV();
void Memory2Scheduler(Input_Info Info);
void Append_Schedule4Independent_Event(Input_Info Info);
void Append_Schedule4Dependent_Event();
void Append_Input_Info(Input_Info Info);
void Append_Event_Move();
void Append_Event_DoorOpen();
void EraseScheculer();
int Scheduler2Track(Input_Info *Info);
void Move();
void MoveUp();
void MoveDown();
int anyUpRequest();
int anyDownRequest();
void DoorOpen();
void printBuidling();
int Count_Load_Passenger(In_Event *In_ptr);


/*    global definitions */
Schedule Schedule4EV;
Track Track_A[Max_Level];
Track Track_B[Max_Level];
EV Elv_A;
EV Elv_B;
int tick;
