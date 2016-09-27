#include <stdio.h>
#include <pthread.h>

static value = 0;
static pthread_mutex_t mutex;
// block
#if 0
void *doit(void *arg){
    printf("doit begin lock\n");
    pthread_mutex_lock(&mutex);

    printf("doit locked: %x\n", (unsigned int)pthread_self());
    sleep(5);

    printf("doit get value = %d\n", value++);
    
    /* unlock */
    pthread_mutex_unlock(&mutex);
    printf("mutex unlock-------------------------------\n");
    pthread_exit(arg);
}
#endif
void *doit(void *arg){
    printf("doit begin lock\n");
    int ret = pthread_mutex_trylock(&mutex);
    printf("ret: %d\n", ret);
    sleep(5);
    pthread_mutex_unlock(&mutex);
    pthread_exit(arg);
}
int main(int argc, char **argv){
    pthread_t thA, thB;
    pthread_create(&thA, NULL, doit, NULL);
    pthread_create(&thB, NULL, doit, NULL);

    pthread_join(thA, NULL);
    pthread_join(thB, NULL);
    printf("main thread exit\n");
    pthread_mutex_destroy(&mutex);
    return 0;
}
