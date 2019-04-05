#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Nomer{
	int no_proses;
};

void* proses(void* arg){
	char direktori[100];
	char nama[100];
	char command[100],command2[100],command3[100];
	struct Nomer*n =  (struct Nomer*)arg;

	// membuat file .txt dan folder	
	sprintf(direktori, "~/Documents/FolderProses%d" , n->no_proses );
	sprintf(command,"mkdir ~/Documents/FolderProses%d", n->no_proses);
    system(command);
    
    sprintf(nama, "%s/SimpanProses%d.txt", direktori,n->no_proses);
    sprintf(command2,"ps -ax | head -10 > %s" , nama);
    system(command2);
    
    // membuat zip
    sprintf(command3, "zip -qmj %s/KompresProses%d.zip %s" , direktori, n->no_proses, nama);
    system(command3);
}

void* unzip(void* arg){
	char command[100];
	char direktori[100];
	char nama[100];
	struct Nomer*n = (struct Nomer*)arg;
	sprintf(direktori, "~/Documents/FolderProses%d" , n->no_proses );
    sprintf(command, "unzip -j %s/KompresProses%d.zip -d %s", direktori, n->no_proses, direktori);
    system(command);
}

int main(){
	pthread_t thread[5];
	struct Nomer nomer;
	nomer.no_proses = 0;
	for(int i=1;i<=2;i++){
		nomer.no_proses = i;
		pthread_create(&thread[i], NULL, &proses , (void *)&nomer);
        pthread_join(thread[i],NULL);
	}

	printf("Tunggu 15 detik!\n");
	for(int i=1;i<=15;i++){
		printf("%d\n", i);
		sleep(1);
	}
	for(int i=1;i<=2;i++){
		nomer.no_proses=i;
		pthread_create(&thread[i], NULL, &unzip, (void *)&nomer);
        pthread_join(thread[i],NULL);
	}
	return 0;
}
