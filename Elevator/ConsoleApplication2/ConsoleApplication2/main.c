/* main.c */


#include "header.h"
#include "func.h"

int main(){

      Init_Scheduler();
      Init_Track(Track_A);
      Init_Elevator(&Elv_A);

      TextReader2Memory2Scheduler();
       //TextReader2Memory2Scheduler(Generate_Event());

       /*소켓 연결 하는 프로그램 connect*/

      RunEV();
}
