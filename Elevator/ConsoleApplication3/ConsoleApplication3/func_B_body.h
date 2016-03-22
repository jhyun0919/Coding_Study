/* func_B_body.h */



#include "func.h"
#include "func_B.h"


void Append_Event_DoorOpen_B(){

       /* = connect Event_DoorOpen to proper Schedule = */
       // called from void MoveUp(), only if the door need to be open at next tick
       // called from void MoveDown(), only if the door need to be open at next tick

       /*    local definitions */
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
void Move_B(){

       /* = determine where to move : up/down/idle = */
       // called from main function at every tick

       /*    local definitions */
       int anyUp;
       int anyDown;

      anyUp = anyUpRequest_B();
      anyDown = anyDownRequest_B();

       if (Elv_B.direction == UP )
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

       if (Elv_B.direction == UP ){
            MoveUp_B();
      }
       else{
             if (Elv_B.direction == DOWN )
                  MoveDown_B();
             else{
                  printBuilding();
                  printf( "\n***** NO BUTTON PRESSED ***** \n" );
                  Sleep(1000);
                  system( "cls");
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
             if(Elv_B.cur_level == Max_Level ){
                  Append_Event_DoorOpen_B();
                  Elv_B.direction = DOWN;
            }
             else if (anyUpForecast_B() == OFF){
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
             else if (anyDownForecast_B() == OFF){
                  Append_Event_DoorOpen_B();
                  Elv_B.direction = UP;
            }
      }
            
}
int anyUpRequest_B(){

       /* = check any up request = */
       //called from void Move()

       /*    local definitions */
       int check;
       int isAny = OFF ;

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

       /*    local definitions */
       int check;
       int isAny = OFF ;

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

       /*    local definitions */
       int check;
       int isAny = OFF ;

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

       /*    local definitions */
       int check;
       int isAny = OFF ;

       /* check is there any request to move down */
       // request exit : isAny = ON
       // no request : isAny = OFF
       for(check = Elv_A.cur_level - 1; check >= 0; check--){
            isAny = isAny || Track_On_Off(Track_B[check]);
      }

       return isAny;
}
void DoorOpen_B(){

       /* = open the door and load or/and unload passengers = */
       // called from main function, only if Door_SW is ON in its tick

       /*    local definitions */
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
             while(temp_Up != NULL ){
                   /* assign each passenger to each unload_level */
                   for( i = 0; i < temp_Up->passenger; i++){
                        Track_B[temp_Up->unload_level[i]     // 해당 층의 In_Up_ptr의 unload_level배열의 값 = 내릴 층             
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
             while(temp_Down != NULL ){
                   /* assign each passenger to each unload_level */
                   for( i = 0; i < temp_Down->passenger; i++){
                        Track_B[temp_Down->unload_level[i]   // 해당 층의 In_Down_ptr의 unload_level배열의 값 = 내릴 층                 
                        ].Out_passenger++;
                  }
                  erase = temp_Down;
                  temp_Down = temp_Down->next;
                  free(erase);
            }
            Track_B[Elv_B.cur_level].In_Down_ptr = NULL;
      }
}
