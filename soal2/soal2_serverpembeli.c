#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

#define PORT 8081

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    memset(buffer, 0, sizeof(buffer));
    int *stock;
    
    key_t key = 1234; 
    pthread_t tid;
    
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666); 
    stock = shmat(shmid, NULL, 0); 
    
      
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    	 
    	char *habis = "Transaksi gagal"; 
    	char *masih = "Transaksi berhasil";    	
    	while((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))>0){ 
        while(valread=read( new_socket,buffer,1024)>0){
        	char b[10] = "beli";
            if( strcmp(buffer, b)==0 ) {
                if(*stock==0){
                	send(new_socket,habis, strlen(habis),0);
				        }       
                else {
                    *stock-=1;
                    send(new_socket,masih, strlen(masih), 0);
                }
            }
            memset(buffer, 0, sizeof(buffer));
        }
    }
    
    shmdt(stock);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}
