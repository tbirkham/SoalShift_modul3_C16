#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>

int WakeUp_Status = 0;
int Spirit_Status = 100;
pthread_t t1, t2;
char request[100];
char enter;
int counterA=0;
int counterI=0;
int gas=0;
int agmal = 0, iraj = 0;

void AllStatus(){
	printf("Agmal Wake Up Status = %d\n", WakeUp_Status);
	printf("Iraj Spirit Status = %d\n", Spirit_Status);
}

void *bangun( void *arg){
	while(1){
		if( gas!= 1){
			continue;
		}
		if(gas==1){
			WakeUp_Status += 15;
			gas=0;
		}
	}	
}


void *tidur( void *arg){
	while(1){
		if( gas!=2){
			continue;
		}
		if(gas == 2){
			Spirit_Status -= 20;
			gas=0;
		}
	}
}

int main(){
	
	while(1){
			scanf("%[^\n]s", request);
			scanf("%c", &enter);
			if( strcmp(request,"All Status") == 0 ){
				AllStatus();
			}
			else if( strcmp(request,"Agmal Ayo Bangun") == 0 ){
				counterA++;
				agmal++;
				//printf("counter a : %d\n", counterA);
				
				gas=1;
				pthread_create( &t1, NULL, bangun, NULL);
				
				
				if(counterA == 3){
					counterA = 0;
					printf("Fitur Iraj Ayo Tidur disabled 10 s\n");
					sleep(10);
				}
				
			}
			else if( strcmp(request,"Iraj Ayo Tidur") == 0){
				counterI++;
				iraj++;
				//printf("counter i : %d\n", counterI);
				
				gas=2;
				pthread_create( &t2, NULL, tidur, NULL);
				
				if(counterI == 3){
					counterI = 0;
					printf("Agmal Ayo Bangun disabled 10 s\n");
					sleep(10);
				}
			}
			
			if(WakeUp_Status>=100 || agmal == 7){
			agmal=0;
			printf("Agmal Terbangun, mereka bangun pagi dan berolahraga\n\n");
			break;
			}
			if(Spirit_Status<=0 || iraj == 5){
				iraj=0;
				printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n\n");
				break;
			}
	}
	return 0;
}
		

