#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *doit(void *arg){
    while(1){
	printf("thread %x\n", (unsigned int)pthread_self());
	sleep(1);
    }
}
int main(int argc, char **argv){
    pthread_t thd;
    int i, ret;
    ret = pthread_create(&thd, NULL, doit, NULL);
    if(ret){
	printf("pthread create\n");
	exit(1);
    }

    while(1){
	printf("main thread: %x\n", (unsigned int)pthread_self());
	sleep(1);
    }
    return 0;
}
