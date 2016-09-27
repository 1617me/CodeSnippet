#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *doit(void *arg){

    int i = 0;
    while(1){
	printf("------other thread: %x\n", (unsigned int)pthread_self());
	if (i++ == 4){
	    pthread_testcancel();
	    break;
	}
	sleep(1);
    }
    pthread_exit((void *)10);
}
int main(int argc, char **argv){
    pthread_t pth;
    printf("sizeof(pth): %lu\n", sizeof(pth));
    int ret = pthread_create(&pth, NULL,doit, NULL);
    if (ret){
	printf("pthrad create\n");
	exit(1);
    }

    int i = 0;
    while(1){
	if (i++ == 3){
	    //pthread_cancel(pth);
	    break;
	}
	printf("main thread: %x\n", (unsigned int)pthread_self());
	sleep(1);
    }
    void *result;
    pthread_join(pth, &result);
    printf("result: %d\n", (int)result);
    free(result);
    return 0;
}
