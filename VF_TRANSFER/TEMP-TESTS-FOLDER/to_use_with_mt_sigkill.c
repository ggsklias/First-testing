/// DESC: Test whether we produce use-after-free on pthread_barrier_wait
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

int main()
{
  struct itimerval timer;
  timer.it_value.tv_sec = 2;
  timer.it_value.tv_usec = 0;
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 0;
  setitimer(ITIMER_REAL, &timer, NULL);

  int nthreads = 0;
  pthread_barrier_t *barr;
  barr = calloc(1, sizeof(pthread_barrier_t));
  pthread_barrier_init(barr, NULL, nthreads);
  int i;
  free(barr);
  pthread_barrier_wait(barr);
  return EXIT_SUCCESS;
}
