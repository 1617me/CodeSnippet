#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* doit(void *arg){
    int i = 0;
    for(; i < 5;i++){
	printf("pthread :%x\n", (unsigned int)pthread_self);
	sleep(1);
    }
    pthread_exit((void *)i);
}
int main(int argc, char **argv){
    pthread_t pth;
    int i, ret;
    void *result;

    ret = pthread_create(&pth, NULL, doit, NULL);
    if(ret != 0){
	printf("create thread\n");
	exit(1);
    }
    i = 0;
    while(1){
	if(i++ == 5)
	    break;
	printf("main thread : %x\n", (unsigned int)pthread_self());
	sleep(1);
    }

    pthread_join(pth, &result);
    printf("pthread exit code : %d\n", (int)result);
    return 0;
}
