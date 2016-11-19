/// DESC: Test whether we produce use-after-free on pthread_cond_wait
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// = calloc(1, sizeof(int));
int t_counter = 0;
int counter = 0;
pthread_mutex_t lock;
pthread_cond_t con;
pthread_t th[2];
struct timespec wakeUp;
struct timeval now;

void *ptr_func(void *arg)
{
  //pthread_mutex_init(&lock, NULL);
  pthread_mutex_lock(&lock);
  //void *ptr = (void*) arg;
  t_counter++;
  printf("Thread %d is being created \n", t_counter);
  pthread_cond_signal(&con);
  counter--;
  printf("Thread %d increases the counter by %d\n", t_counter, counter);
  pthread_mutex_unlock(&lock);
  return NULL;
}
void *ptr_func1(void *arg)
{
  pthread_mutex_lock(&lock);
  gettimeofday(&now, NULL);
  wakeUp.tv_sec = now.tv_sec+20;
  wakeUp.tv_nsec = (now.tv_usec+1000UL)*1000UL;
  t_counter++;
  int i;
  int ret = 15;
  printf("Thread %d is being created \n", t_counter);
 // while (i<5)
//  {
//    if (i == 3)
      ret = pthread_cond_timedwait(&con, &lock, &wakeUp);
      printf ("Ret code: %d\n", ret);
      i++;
    printf("Thread %d increases the counter by %d\n", t_counter, counter);
    counter++;
 // }
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main()
{
  if (pthread_mutex_init(&lock, NULL) == 0)
  {
    printf("Mutex init success.\n");
  }

  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&con, NULL);
  pthread_create(&(th[0]), NULL, ptr_func1, NULL);
  pthread_create(&(th[1]), NULL, ptr_func, NULL);
  pthread_join(th[0], NULL);
  pthread_join(th[1], NULL);
  pthread_mutex_destroy(&lock);
  return EXIT_SUCCESS;
}
