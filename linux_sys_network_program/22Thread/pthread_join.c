#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



void *thr_fn1(void *arg){
    printf("thread 1 return\n");
    void *p = malloc(1);
    *(char *)p = 43;
    return p;
}

void *thr_fn2(void *arg){
    printf("thread 2 return \n");
    pthread_exit((void *)2);
}

void *thr_fn3(void *arg){
    while(1){
	printf("thread 3 running\n");
	sleep(2);
    }
}

int main(){
    pthread_t tid;
    void *t_ret;
    pthread_create(&tid, NULL, thr_fn1, NULL);
    pthread_join(tid, &t_ret);
    printf("htread 1 exit code %d\n", *(char *)t_ret);

    pthread_create(&tid, NULL, thr_fn2, NULL);
    pthread_join(tid, &t_ret);
    printf("thread 2 exit code %d\n", (int)t_ret);

    pthread_create(&tid, NULL, thr_fn3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &t_ret);
    printf("thread 3 exit code %d\n", (int)t_ret);

    return 0;
}

