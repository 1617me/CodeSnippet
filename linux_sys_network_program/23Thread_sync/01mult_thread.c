#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NLOOP 10
int counter;

void *doit(void *arg){
    int i, val;
    for(i = 0; i < NLOOP; i++){
	val = counter;
	printf("%x: %d\n", (unsigned int)pthread_self(), val+1);
	counter = val+1;
	sleep(1);
    }
    return NULL;
}
int main(int argc, char **argv){
    pthread_t tidA, tidB;
    pthread_create(&tidA, NULL, doit, NULL);
    pthread_create(&tidB, NULL, doit, NULL);
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    return 0;
}
