#include <time.h>
#include <stdio.h>
#include <pthread.h>

static int money = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t pro = PTHREAD_COND_INITIALIZER;
void *minus(void *arg){
    while(1){
	printf("*** enter minus loop m:%d ***\n", money);
	if (money == 0){
	    pthread_cond_wait(&pro, &mutex);
	}
	pthread_mutex_lock(&mutex);
	printf("23234232\n");
	int x = money;
	money = 0;
	pthread_mutex_unlock(&mutex);
	printf("*** minus money: %d ***\n", x);
	sleep(1);
    }
}

void *add(void *arg){
    while(1){
	pthread_mutex_lock(&mutex);
	money += rand() % 1000+1;
	pthread_mutex_unlock(&mutex);
	printf("--- add money over ---\n");
	pthread_cond_signal(&pro);
	sleep(5);
    }
}
int main(int argc, char **argv){
    pthread_t pidA, pidB;
    srand(time(NULL));
    pthread_create(&pidA, NULL, add, NULL);
    pthread_create(&pidB, NULL, minus, NULL);
    pthread_join(pidA, NULL);
    pthread_join(pidB, NULL);

    return 0;
}
