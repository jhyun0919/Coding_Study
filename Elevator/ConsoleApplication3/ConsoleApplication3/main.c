#include "func_body.h"
#include "func_A_body.h"
#include "func_B_body.h"

int main(){

      Init_Scheduler();

      Init_Track(Track_Main);
      Init_Track(Track_A);
      Init_Track(Track_B);

      Init_Elevator(&Elv_A);
      Init_Elevator(&Elv_B);

      TextReader2Memory2Scheduler();
       //TextReader2Memory2Scheduler(Generate_Event());

       /*���� ���� �ϴ� ���α׷� connect*/

      RunEV();
}
