/// DESC: Test whether we produce use-after-free on pthread_cond_wait
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int counter = 0;
pthread_mutex_t lock;
int t_counter = 0;

void *ptr_func(void *arg)
{
  pthread_mutex_lock(&lock);
  int *i = (int*)arg;
  int j;
  printf("Thread %d is being created \n", t_counter);
  t_counter++;
  for (j=0; j<5; j++)
  {
    printf("Thread %d increases the counter by %d\n", t_counter, counter);
    counter++;
  }
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main()
{
  pthread_t th[2];
  int *i = 0;
  int j = 0;
  if (pthread_mutex_init(&lock, NULL) == 0)
  {
    printf("Mutex init success.\n");
  }
  int pthread_mutex_lock(pthread_mutex_t *mutex);
  i = &j;
  while (j<2){
    pthread_create(&(th[j]), NULL, ptr_func, (void*)i);
    //pthread_cond_wait(pthread_cond_t *cond, lock);
    j++;
  }
  pthread_join(th[0], NULL);
  pthread_join(th[1], NULL);
  pthread_mutex_destroy(&lock);
  return EXIT_SUCCESS;
}

