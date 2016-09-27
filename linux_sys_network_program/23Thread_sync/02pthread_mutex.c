#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NLOOP 10

int counter;

pthread_mutex_t  counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *doit(void *arg){
    int i, val;
    val = counter;
    for(i = 0; i < NLOOP; i++){
	pthread_mutex_lock(&counter_mutex);
	val = counter;
	printf("%x: %d\n", (unsigned int)pthread_self(), val+1);
	counter = val+1;
	pthread_mutex_unlock(&counter_mutex);
	//sleep(1);

    }
    return NULL;
}
int main(int argc, char **argv){
    pthread_t tidA, tidB;
    pthread_create(&tidA, NULL, doit, NULL);
    pthread_create(&tidA, NULL, doit, NULL);
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    pthread_mutex_destroy(&counter_mutex);
    return 0;
}
