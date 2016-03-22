/* func_body.h */



#include "func.h"






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

void Init_Scheduler(){
      Schedule4EV.head = ( Scheduler *) malloc(sizeof (Scheduler));
      Schedule4EV.tail = ( Scheduler *) malloc(sizeof (Scheduler));

      Schedule4EV.head->next = Schedule4EV.tail;

      Schedule4EV.head->tick = -1;
      Schedule4EV.tail->tick = 99999999;
}
void Init_Track(Track T[]){
       int i;

       for(i = 0; i < Max_Level ; i++){
             T[i].In_Up_ptr = NULL ;
             T[i].In_Down_ptr = NULL ;
             T[i].Out_passenger = 0;
      }
}
void Init_Elevator(EV *Elv){
       Elv->cur_level = 0;
       Elv->direction = IDLE ;
       Elv->weight = 0;
}
void TextReader2Memory2Scheduler(){
       FILE *fp = NULL ;
       Input_Info temp = {0, 0, 0, 0, {0, }};
       int i, j;

      fp = fopen( "Input_Data.txt", "r" );
       if(fp == NULL ){
            printf( "file open error\n");
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
            printf( "TextReader2Memory success!\n" );
            Sleep(3000);
      }
       else{
            printf( "TextReader2Memory error\n" );
            Sleep(3000);
      }

       if(fclose(fp) == EOF ){
            printf( "file close error\n");
            exit(1);
      }
      system( "cls");
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
                  system( "cls");
            }

             else{
                        term_A--;
                        printBuilding();
                        printf( "Door A is Opened!!!\n" );
                        printf( "time left : %d\n", term_A);
                        Sleep(1000);
                        system( "cls");
            }

             if(term_B == 0){
                  Move_B();
                  printBuilding();
                   //printf("Moving\n");
                  Sleep(1000);
                  system( "cls");
            }

             else{
                        term_B--;
                        printBuilding();
                        printf( "Door B is Opened!!!\n" );
                        printf( "time left : %d\n", term_B);
                        Sleep(1000);
                        system( "cls");
            }

            tick++;
            
             /* main의 tick이 Scheduler의 첫번째 Schedule의 tick과 일치할 때 */
             if(tick == Schedule4EV.head->next->tick){
                  
                   /* connect In_Event to Track_Main */
                   if(Schedule4EV.head->next->Info_ptr != NULL){
                        pushBlevel = Scheduler2Track(Schedule4EV.head->next->Info_ptr);
                        printBuilding();
                        printf( "Someone Push the Butten on level %d!!!\n", pushBlevel);
                        Sleep(3000);
                        system( "cls");
                  }

                  
                   /* Event_DoorOpen */
                   if(Schedule4EV.head->next->Door_SW_A == ON){
                        printBuilding();
                        DoorOpen_A();
                        printf( "Door A is Opened!!!\n" );

                        

                        term_A = 5;
                        printf( "time left : %d\n", term_A - 1);
                        Sleep(3000);
                        system( "cls");
                        
                  }
                   if(Schedule4EV.head->next->Door_SW_B == ON){
                        printBuilding();
                        DoorOpen_B();
                        printf( "Door B is Opened!!!\n" );

                        

                        term_B = 5;
                        printf( "time left : %d\n", term_B - 1);
                        Sleep(3000);
                        system( "cls");
                        
                  }
                  
                  EraseScheculer();
            }
                        

             /*send/recv 함수*/
      }
}
void Memory2Scheduler(Input_Info Info){

       /* = read data from textfile and make Schedule = */
       // called from main function

       /* make a schedule on given tick for Independent Event */
       // Schedule tick = Info.tick
      Append_Schedule4Independent_Event( Info);
      
       /* connet Input_Info to the schedule */
      Append_Input_Info( Info);
}
void Append_Schedule4Independent_Event(Input_Info Info){

       /* = make a Schedule on given tick for Independent Event = */
       // called form void Text2Scheduler(Input_Info Info)

       /*    local definitions */
       Scheduler * New_Schedule, *append_right;

       /* assign memory space */
      New_Schedule = ( Scheduler *) malloc(sizeof (Scheduler));

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
void Append_Schedule4Dependent_Event(){

       /* = make a Schedule on given tick for Dependent Event = */
       // called form void Append_Event_Move()
       // called form void Append_Event_DoorOpen()

       /*    local definitions */
       Scheduler * New_Schedule, *append_right;

       /* assign memory space */
      New_Schedule = ( Scheduler *) malloc(sizeof (Scheduler));
      
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
void Append_Input_Info(Input_Info Info){
      
       /* = connect Input_Info to proper Schedule = */
       // called form void Text2Scheduler(Input_Info Info)
      
       /*    local definitions */
       Scheduler *search;
       Input_Info * New_Input_Info, *append_right;
       int i;

       /* assign memory space */
      New_Input_Info = ( Input_Info *) malloc(sizeof (Input_Info));

       /* assign data */
      New_Input_Info->tick = Info.tick;
      New_Input_Info->load_level = Info.load_level;
      New_Input_Info->direction = Info.direction;
      New_Input_Info->passenger = Info.passenger;
       for(i = 0; i < Info .passenger; i++){
            New_Input_Info->unload_level[i] = Info.unload_level[i];
      }
       for(i = Info .passenger; i < 20; i++){
            New_Input_Info->unload_level[i] = 0;
      }
      New_Input_Info->next = NULL;

       /* connect Input_Info to Schedule */
      search = Schedule4EV.head;
       do{
            search = search->next;
      } while(search->tick != Info .tick);

       if(search->Info_ptr == NULL ){
            search->Info_ptr = New_Input_Info;
      }
       else{
            append_right = search->Info_ptr;
             while(append_right->next != NULL ){
                  append_right = append_right->next;
            }
            append_right->next = New_Input_Info;
      }
}
void EraseScheculer(){

       /* = erase passed Schedule = */
       // called from main funtion

       /*    local definitions */
       Scheduler *hold;

       /* erase the Schedule */
      hold = Schedule4EV.head->next->next;
      free(Schedule4EV.head->next);
      Schedule4EV.head->next = hold;
}
int Scheduler2Track(Input_Info *Info){

       /* = transfer information from Scheduler to Track when there is a Schedule at the tick = */
       // called from main function

       /*    local definitions */
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
            chosen_Elv = Priority_Selector(temp->load_level);            //    누른 층 정보만 날린뒤, 엘베 선택받는다

            
            pushBlevel = temp->load_level;
            
             /* connect In_Event to chosen Track */
             switch(chosen_Elv){
             case A :
                  {
                         if(chosen->direction == UP ){
                              target = Track_A[temp->load_level].In_Up_ptr;
                               if(target == NULL )
                                    Track_A[temp->load_level].In_Up_ptr = chosen;
                               else{
                                     while(target->next != NULL ){
                                          target = target->next;
                                    }
                                    target->next = chosen;
                              }
                        }
                         else if (chosen->direction == DOWN){
                              target = Track_A[temp->load_level].In_Down_ptr;
                               if(target == NULL )
                                    Track_A[temp->load_level].In_Down_ptr = chosen;
                               else{
                                     while(target->next != NULL ){
                                          target = target->next;
                                    }
                                    target->next = chosen;
                              }
                        }
                  }
                   break;
             case B :
                  {
                         if(chosen->direction == UP ){
                              target = Track_B[temp->load_level].In_Up_ptr;
                               if(target == NULL )
                                    Track_B[temp->load_level].In_Up_ptr = chosen;
                               else{
                                     while(target->next != NULL ){
                                          target = target->next;
                                    }
                                    target->next = chosen;
                              }
                        }
                         else if (chosen->direction == DOWN){
                              target = Track_B[temp->load_level].In_Down_ptr;
                               if(target == NULL )
                                    Track_B[temp->load_level].In_Down_ptr = chosen;
                               else{
                                     while(target->next != NULL ){
                                          target = target->next;
                                    }
                                    target->next = chosen;
                              }
                        }
                  }
                   break;
             default:
                  printf( "connect In_Event to chosen Track error" );
                  exit(1);
            }
            


             /* move Input_Info *temp to the next one */
             /* erase garbage Input_Info memory space */
            erase = temp;
            temp = temp->next;
            free(erase);
      } while(temp !=NULL );

       //Append_Event_Move();

       return pushBlevel;
}
void printBuilding(){

       int level;

      printf( "   Elv_A   " );
      printf( "+---------------+");
      printf( "   Elv_B   " );
      printf( "\n");
       //===========================
       for(level = Max_Level-1; level >= 0; level--){

             if(Elv_A.cur_level == level){
                  printf( "   < ");
                   switch(Elv_A.direction){
                   case UP : printf("U"); break;
                   case DOWN : printf("D"); break;
                   case IDLE : printf("-"); break;
                  }
                  printf( " >   ");
            }
             else{
                  printf( "           " );
            }

            printf( "|     F : %2d    |" , level);

             if(Elv_B.cur_level == level){
                  printf( "   < ");
                   switch(Elv_B.direction){
                   case UP : printf("U"); break;
                   case DOWN : printf("D"); break;
                   case IDLE : printf("-"); break;
                  }
                  printf( " >   ");
            }
             else{
                  printf( "           " );
            }

            printf( "\n");
             //===========================
             if(Elv_A.cur_level == level){
                  printf( "weight:    " );
            }
             else{
                  printf( "           " );
            }
            printf( "|");
            printf( "A_in: ");

             if(Track_A[level].In_Up_ptr != NULL && Track_A[level].In_Down_ptr == NULL ){
                  printf( "U %2d     " , Count_Load_Passenger_Up(Track_A[level]));
            }
             else if (Track_A[level].In_Down_ptr != NULL && Track_A[level].In_Up_ptr == NULL ){
                  printf( "D %2d     " , Count_Load_Passenger_Down(Track_A[level]));
            }
             else if (Track_A[level].In_Down_ptr != NULL && Track_A[level].In_Up_ptr != NULL ){
                  printf( "U/D %2d   " , Count_Load_Passenger_Up(Track_A[level]) + Count_Load_Passenger_Down(Track_A[level]));
            }
             else{
                  printf( "         " );
            }
            printf( "|");

             if(Elv_B.cur_level == level){
                  printf( "weight:    " );
            }
             else{
                  printf( "           " );
            }
            printf( "\n");
             //===========================
            printf( "           " );
            printf( "|");
            printf( "B_in: ");

             if(Track_B[level].In_Up_ptr != NULL && Track_B[level].In_Down_ptr == NULL ){
                  printf( "U %2d     " , Count_Load_Passenger_Up(Track_B[level]));
            }
             else if (Track_B[level].In_Down_ptr != NULL && Track_B[level].In_Up_ptr == NULL ){
                  printf( "D %2d     " , Count_Load_Passenger_Down(Track_B[level]));
            }
             else if (Track_B[level].In_Down_ptr != NULL && Track_B[level].In_Up_ptr != NULL ){
                  printf( "U/D %2d   " , Count_Load_Passenger_Up(Track_B[level]) + Count_Load_Passenger_Down(Track_B[level]));
            }
             else{
                  printf( "         " );
            }
            printf( "|");
            printf( "\n");
             //===========================
            printf( "           " );
            printf( "|");
            printf( "A_out: ");
             if(Track_A[level].Out_passenger != 0){
                  printf( "%2d      " , Track_A[level].Out_passenger);
            }
             else{
                  printf( "        " );
            }
            printf( "|");
            printf( "\n");
             //===========================
            printf( "           " );
            printf( "|");
            printf( "B_out: ");
             if(Track_B[level].Out_passenger != 0){
                  printf( "%2d      " , Track_B[level].Out_passenger);
            }
             else{
                  printf( "        " );
            }
            printf( "|");
            printf( "\n");
             //===========================
            printf( "           " );
            printf( "+---------------+");
            printf( "\n");
      }

      printf( "tick : %d\n", tick);

}
int Track_On_Off(Track T){

       /* = check is there any reguest in given level = */
       //called from int anyUpRequest()
       //called from int anyDownRequest()


       if(T .In_Up_ptr == NULL && T.In_Down_ptr == NULL && T.Out_passenger == 0) 
             return OFF ;
       else
             return ON ;
}

int Count_Load_Passenger_Up(Track T){

       /* = count number of passengers who are waiting the elevator to load in the given level = */
       // call from void printBuidling()
       // return int total_passenger

       /*    local definitions */
       int total_passenger = 0;
       In_Event *temp;

       /* count passenger number who go up */
      temp = T.In_Up_ptr;
       do{
            total_passenger += T.In_Up_ptr->passenger;
            temp = temp->next;
      } while(temp != NULL );

       return total_passenger;
}
int Count_Load_Passenger_Down(Track T){

       /* = count number of passengers who are waiting the elevator to load in the given level = */
       // call from void printBuidling()
       // return int total_passenger

       /*    local definitions */
       int total_passenger = 0;
       In_Event *temp;

       /* count passenger number who go down */
      temp = T.In_Down_ptr;
       do{
            total_passenger += T.In_Down_ptr->passenger;
            temp = temp->next;
      } while(temp != NULL );

       return total_passenger;
}
int Priority_Selector(int level){

       int distance_A, distance_B;

      distance_A = abs(Elv_A.cur_level - level);
      distance_B = abs(Elv_B.cur_level - level);

       if(distance_A <= distance_B){
             return A ;
      }
       else{
             return B ;
      }
}

