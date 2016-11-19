/// DESC: Test whether we produce use-after-free on pthread_cond_wait
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

pthread_mutex_t lock;
pthread_cond_t *con;
void *fun1(void *x)
{
  pthread_mutex_lock(&lock);
  pthread_cond_signal(con);
  printf("Thread 2\n");
  pthread_mutex_unlock(&lock);
  return NULL;
}
void *fun(void *x)
{
  pthread_mutex_lock(&lock);
  struct timespec wakeUp;
  struct timeval now;
  gettimeofday(&now, NULL);
  wakeUp.tv_sec = now.tv_sec+10;
  wakeUp.tv_nsec = (now.tv_usec+1000UL)*1000UL;
  printf("TEST thread1\n");
  int rt = pthread_cond_timedwait(con, &lock, &wakeUp);
  printf("%d\n", rt);
  printf("return from thread2\n");
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main(void)
{
  pthread_mutex_init(&lock, NULL);
  con = calloc(1, sizeof(pthread_cond_t));
  pthread_cond_init(con, NULL);
  free(con);
  pthread_t th[2];
  pthread_create(&th[0], NULL, fun, NULL);
  pthread_create(&th[1], NULL, fun1, NULL);
  pthread_join(th[0], NULL);
  pthread_join(th[1], NULL);
  
  pthread_mutex_destroy(&lock);
  return EXIT_SUCCESS;
}
