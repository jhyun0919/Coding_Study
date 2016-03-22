#include "header.h"
#include "func.h"
#include "sock.h"

int main(int argc, char *argv[]){

	Input_Info temp = {0, 0, 0, 0, {0, }};
	int i, j;
	int ret;
	int term = 10;
	int pushBlevel;
	int sock;
	char msg[8]="1234";

	FILE *fp = NULL;

	if(argc!=3)
		printf("Usage : %s <ip> <port>",argv[0]);

	sock = sock_connect(&argv[1], &argv[2]);
	printf("sock\n");

	Init_Scheduler();
	Init_Track(Track_1);
	Init_Elevator(&Elv);

	fp = fopen("Input_Data.txt", "r");
	if(fp == NULL){
		printf("file open error\n");
		exit(1);
	}

	for(i = 0; i < 3; i++)
	{
		fscanf(fp, "%d %d %d %d",&temp.tick, &temp.load_level, &temp.direction, &temp.passenger );

		printf("%d\n", temp.tick);
		printf("%d\n", temp.load_level);
		printf("%d\n", temp.direction);
		printf("%d\n", temp.passenger);

		for(j = 0; j < temp.passenger; j++)
		{
			fscanf(fp, "%d",&temp.unload_level[j]);
			printf("%d\n", temp.unload_level[j]);
		}
		temp.next = NULL;
		printf("\n");

		Text2Scheduler(temp);

	}


	/*소켓 연결 하는 프로그램 connect*/





	tick = 0;

	while(1){

		tick++;

		/* main의 tick이 Scheduler의 첫번째 Schedule의 tick과 일치할 때 */
		if(tick == head->next->tick){

			/* In_Event is connected to Track */
			if(head->next->Info_ptr != NULL){
				pushBlevel = Scheduler2Track(head->next->Info_ptr);
				printBuidling();
				printf("Someone Push the Butten on level %d!!!\n", pushBlevel);
				sleep(1);
			}

			/* Event_Move */
			if(head->next->Move_SW != OFF ){

				Move();

				head->next->Move_SW = OFF;

				printBuidling(); 
				printf("Just Moved!!!\n");
				sleep(1);
			}
			/* Event_DoorOpen */
			else if(head->next->Door_SW != OFF){
				printBuidling();
				DoorOpen();
				printf("Door is Opened!!!\n");

				printf("time left : %d\n", term);
				sleep(1);
				/*
				   term--;

				   if(term == 0){
				   head->next->Door_SW = OFF;
				   term =10;
				   }
				   */
				head->next->Door_SW = OFF;
			}
			EraseScheculer();
		}
		else{
			printBuidling();
			printf("No Event\n");
			sleep(1);
		}
		ret = send_msg(sock, msg);
		printf("str_len : %d\n",ret);
//		recv_msg(sock, msg);

		sleep(1);
		system("cls");
	}
		

}
