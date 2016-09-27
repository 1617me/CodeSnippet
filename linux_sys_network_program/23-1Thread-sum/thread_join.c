#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *doit(void *arg){
    int i = 0;
    while(i++ < 5){
	printf("other thread: %x\n", (unsigned int)pthread_self());
	sleep(1);
    }
    return arg;
}
int main(int argc, char **argv){
    pthread_t pth;
    void      *result;
    void *p = malloc(4);
    *(char *)(p) = 65;
    int ret = pthread_create(&pth, NULL, doit,p);
    if (ret){
	printf("pthread create\n");
	exit(1);
    }
    pthread_detach(pth);
    pthread_join(pth, &result);
    printf("join over, result = %d\n", *(char *)(result));
    free(p);
    return 0;
}
