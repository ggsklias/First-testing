#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

pthread_mutex_t fakeMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t fakeCond = PTHREAD_COND_INITIALIZER;

void mywait(int timeInMs)
{
    struct timespec timeToWait;
    struct timeval now;
    int rt;

    gettimeofday(&now,NULL);


    timeToWait.tv_sec = now.tv_sec+5;
    timeToWait.tv_nsec = (now.tv_usec+1000UL*timeInMs)*1000UL;
    pthread_cond_init(&fakeCond, NULL);  
    pthread_mutex_init(&fakeMutex, NULL);
    pthread_mutex_lock(&fakeMutex);
    rt = pthread_cond_timedwait(&fakeCond, &fakeMutex, &timeToWait);
    printf("Ret code: %d\n", rt);

    pthread_mutex_unlock(&fakeMutex);
    pthread_mutex_destroy(&fakeMutex);
    printf("\nDone\n");
}

void* fun(void* arg)
{
    printf("\nIn thread\n");
    mywait(1000);
    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, fun, NULL);
    pthread_join(thread, NULL);
}
