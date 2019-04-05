#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[200];
int b;
int temp[200];

void* fact(){
    unsigned long long hasil=1;
    long n, i=1;
    n=temp[b];
    
	while(i<=n)
        {
            hasil=hasil*i; //counting factorial
			++i;
        }
    printf("%ld! = %llu \n",n,hasil);
}

void sort(int temp[], int a){
	int i, j, swap;
	a=a-1;
	
	for (i=0; i<a; i++){
    	for (j=0; j<a-i; j++){
    		if (temp[j] < temp[j-1]){
    		swap = temp[j-1];
    		temp[j-1]= temp[j];
    		temp[j]= swap;
			}	
		}
	}
}

int main(int argc, char* argv[])
{
	int err, konv;
	int i, j;
	char* ptr;
	
	for (i=0; i<argc-1; i++){
		konv=strtol(argv[i + 1], &ptr, 10);
		temp[i]=konv;
	}
	
	sort(temp, argc);
    for (i=0; i<argc-1; i++){

	}
	
	for(b=0;b<argc-1;b++)
	{ 
		err = pthread_create(&(tid[b]),NULL,&fact,NULL); //making thread
		if(err!=0) //error checking
		{
			
		}
		else
		{

		}
		pthread_join(tid[b],NULL);

	}
	return 0;

}
