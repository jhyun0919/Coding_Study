/* func.c */


#include "header.h"
#include "func.h"


void Init_Scheduler(){
      Schedule4EV.head = ( Scheduler *) malloc(sizeof (Scheduler));
      Schedule4EV.tail = ( Scheduler *) malloc(sizeof (Scheduler));

      Schedule4EV.head->next = Schedule4EV.tail;

      Schedule4EV.head->tick = -1;
      Schedule4EV.tail->tick = 9999999;
}
void Init_Track(Track T[]){
       int i;

       for(i = 0; i < Max_Level ; i++){
             T[i].In_ptr = NULL ;
             T[i].Out_passenger = 0;
      }
}
void Init_Elevator(EV *Elv_A){
       Elv_A->cur_level = 0;
       Elv_A->direction = IDLE ;
       Elv_A->weight = 0;
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
      New_Schedule->Move_SW = OFF;
      New_Schedule->Door_SW = OFF;

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
      New_Schedule->Move_SW = OFF;
      New_Schedule->Door_SW = OFF;

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
void Append_Event_Move(){

       /* = connect Event_Move to proper Schedule = */
       //

       /*    local definitions */
       Scheduler *search;
      
       /* make a schedule on given tick for Dependent Event */
       // Schedule tick = Info.tick
      Append_Schedule4Dependent_Event();

       /* connet Event_Move to Scheduler */
      search = Schedule4EV.head;
       while(search->tick != tick + 1){
            search = search->next;
      }
      search->Move_SW = ON;
}
void Append_Event_DoorOpen(){

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
      search->Door_SW = ON;

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
       In_Event *New;
       Input_Info *temp, *erase;
       int i;
       int pushBlevel;


       /* transfer information from Scheduler to Track */
      temp = Info;
       do{
             /* assign memory space */
            New = ( In_Event *) malloc(sizeof (In_Event));

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
            Track_A[temp->load_level].In_ptr = New;
            pushBlevel = temp->load_level;

             /* move Input_Info *temp to the next one */
             /* erase garbage Input_Info memory space */
            erase = temp;
            temp = temp->next;
            free(erase);
      } while(temp !=NULL );

       //Append_Event_Move();

       return pushBlevel;
}



void Move(){

       /* = determine where to move : up/down/idle = */
       // called from main function at every tick

       /*    local definitions */
       int anyUp;
       int anyDown;

      anyUp = anyUpRequest();
      anyDown = anyDownRequest();

       if (Elv_A.direction == UP )
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

       if (Elv_A.direction == UP ){
            MoveUp();
      }
       else{
             if (Elv_A.direction == DOWN )
                  MoveDown();
             else{
                  printBuidling();
                  printf( "\n***** NO BUTTON PRESSED ***** \n" );
                  Sleep(1000);
                  system( "cls");
            }
      }
}
void MoveUp(){

       /* = go one level up = */
       // called from void Move()

       /* go up */
      Elv_A.cur_level++;

       /* append Event_DoorOpen at next tick if EV has arrived */
       if(Track_A[Elv_A.cur_level].Out_passenger != 0){
            Append_Event_DoorOpen();      
      }
       else if (Track_A[Elv_A.cur_level].In_ptr != NULL){
             if(Track_A[Elv_A.cur_level].In_ptr->direction == Elv_A.direction)
                  Append_Event_DoorOpen();
      }

      


}
void MoveDown(){

       /* = go one level down = */
       // called from void Move()

       /* go down */
      Elv_A.cur_level--;

       /* append Event_DoorOpen at next tick if EV has arrived */
       if(Track_A[Elv_A.cur_level].Out_passenger != 0){
            Append_Event_DoorOpen();
      }
       else if (Track_A[Elv_A.cur_level].In_ptr != NULL){
             if(Track_A[Elv_A.cur_level].In_ptr->direction == Elv_A.direction)
                  Append_Event_DoorOpen();
      }

      
}
int anyUpRequest(){

       /* = check any up request = */
       //called from void Move()

       /*    local definitions */
       int check;
       int isAny = OFF ;

       /* check is there any request to move up */
       // request exit : isAny = ON
       // no request : isAny = OFF
       for(check = Elv_A.cur_level; check < Max_Level && !isAny; check++){
            isAny = Track_On_Off(Track_A[check]);
      }

       return isAny;
}
int anyDownRequest(){

       /* = check any down request = */
       //called from void Move()

       /*    local definitions */
       int check;
       int isAny = OFF ;

       /* check is there any request to move down */
       // request exit : isAny = ON
       // no request : isAny = OFF
       for(check = Elv_A.cur_level; check >= 0; check--){
            isAny = isAny || Track_On_Off(Track_A[check]);
      }

       return isAny;
}
int Track_On_Off(Track T){

       /* = check is there any reguest in given level = */
       //called from int anyUpRequest()
       //called from int anyDownRequest()


       if(T .In_ptr == NULL && T.Out_passenger == 0)    
             return OFF ;
       else
             return ON ;
}



void DoorOpen(){

       /* = open the door and load or/and unload passengers = */
       // called from main function, only if Door_SW is ON in its tick

       /*    local definitions */
       int i;
       In_Event * search, *erase;

       /* Out_Event : unload passegner */
       if(Track_A[Elv_A.cur_level].Out_passenger != 0){
            Track_A[Elv_A.cur_level].Out_passenger = 0;
      }


       /* In_Event : load pasenger */
      search = Track_A[Elv_A.cur_level].In_ptr;
       while(search != NULL ){
             /* assign each passenger to each unload_level */
             for( i = 0; i < search->passenger; i++){
                  Track_A[search->unload_level[i]      // 해당 층의 In_ptr의 unload_level배열의 값 = 내릴 층                
                  ].Out_passenger++;
            }
            erase = search;
            search = search->next;
            free(erase);
      }
      Track_A[Elv_A.cur_level].In_ptr = NULL;
}



void printBuidling(){
      
       /* = show the whole status when its called  = */

       /*    local definitions */
       int level;

      printf( " +------------+\n");
       for(level = Max_Level-1; level >= 0; level--){
             /* show level */
            printf( " |level: %2d   |\n" , level);

             /* show in infomation */
            printf( " |in: ");
             if(Track_A[level].In_ptr != NULL ){
                   if(Track_A[level].In_ptr->direction == UP){
                        printf( "U %2d     " , Count_Load_Passenger(Track_A[level].In_ptr));
                  }
                   else if (Track_A[level].In_ptr->direction == DOWN){
                        printf( "D %2d     " , Count_Load_Passenger(Track_A[level].In_ptr));
                  }
            }
             else{
                  printf( "        " );
            }
            printf( "|");
             if(Elv_A.cur_level == level){

                  printf( " < ");
                   switch(Elv_A.direction){
                   case UP : printf("U > "); break;
                   case DOWN : printf("D > "); break;
                   case IDLE : printf("- > "); break;
                  }
                  printf( "weight: ");
            }
            printf( "\n");

             /* show out infomation */
            printf( " |out: ");
             if(Track_A[level].Out_passenger != 0){
                  printf( "%2d    " , Track_A[level].Out_passenger);
            }
             else{
                  printf( "       " );
            }
            printf( "|\n");
            printf( " +------------+\n");

      }

      printf( "tick : %d\n", tick);
}
int Count_Load_Passenger(In_Event *In_ptr){

       /* == */

       /*    local definitions */
       int total_passenger = 0;

       do{
            total_passenger += In_ptr->passenger;
             In_ptr = In_ptr ->next;
      } while(In_ptr != NULL);


       return total_passenger;
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
       int term = 0;
       int i;

      tick = 0;

       while(1){

             if(term == 0){
                  Move();
                  printBuidling();
                   //printf("Moving\n");
                  Sleep(1000);
                  system( "cls");
            }

             else{
                        term--;
                        printBuidling();
                        printf( "Door is Opened!!!\n");
                        printf( "time left : %d\n", term);
                        Sleep(1000);
                        system( "cls");
            }

            tick++;
            
             /* main의 tick이 Scheduler의 첫번째 Schedule의 tick과 일치할 때 */
             if(tick == Schedule4EV.head->next->tick){
                  
                   /* connect In_Event to Track */
                   if(Schedule4EV.head->next->Info_ptr != NULL){
                        pushBlevel = Scheduler2Track(Schedule4EV.head->next->Info_ptr);
                        printBuidling();
                        printf( "Someone Push the Butten on level %d!!!\n", pushBlevel);
                        Sleep(3000);
                        system( "cls");
                  }

                   /* Event_Move */
                   /*if(head->next->Move_SW != OFF ){

                        Move();
                        
                        head->next->Move_SW = OFF;

                        printBuidling();
                        printf("Just Moved!!!\n");
                        Sleep(1000);
                  }*/
                  
                   /* Event_DoorOpen */
                   if(Schedule4EV.head->next->Door_SW == ON){
                        printBuidling();
                        DoorOpen();
                        printf( "Door is Opened!!!\n");

                         /*
                        printf("unload_level: ");
                        for(i = 0; i < Track_A[Elv_A.cur_level].In_ptr->passenger; i++){
                              printf("3%d", Track_A[Elv_A.cur_level].In_ptr->unload_level[i]);
                        }
                        printf("\n");
                        */

                        term = 5;
                        printf( "time left : %d\n", term - 1);
                        Sleep(3000);
                        system( "cls");
                        
                         /*
                        term--;

                        if(term == 0){
                              head->next->Door_SW = OFF;
                              term =10;
                        }
                        */
                         //head->next->Door_SW = OFF;
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

void PriorityDecider(){


}
