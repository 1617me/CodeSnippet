#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *th_func(void *arg){
    int *p = (int *)arg;
    printf("thread pid: %d\n", getpid());
    // 1.....
    printf("thread id: %x\n", (unsigned int)pthread_self());
    printf("thread *arg:%d\n", *p);
    //sleep(1);
}

int main(int argc, char **argv){
    pthread_t tid;
    int n = 10;
    // 这里获取到的tid和上面回调函数中pthread_self获取到id不完全等价
    pthread_create(&tid, NULL, th_func, (void *)&n);
    printf("main thread id = %x\n", (unsigned int)pthread_self());
    printf("main child thread ID: %x\n", (unsigned int)tid);
    printf("main pid: %d\n", getpid());
    sleep(10);
    return 0;
}
