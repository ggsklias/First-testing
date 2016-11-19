#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int main(){
  pthread_mutex_t t;
  pthread_cond_t cond;
  int rc;
  struct timespec ts;
  pthread_mutex_init(&t, NULL);
  pthread_mutex_lock(&t);
  //t.waiters++;
  clock_gettime(CLOCK_REALTIME, &ts);
  ts.tv_sec += 5;
  rc = 0;
  //while (! mypredicate(&t) && rc == 0)
    rc = pthread_cond_timedwait(&cond, &t, &ts);
  //t.waiters--;
  printf("%d\n", rc);
//  if (rc == 0 || mypredicate(&t))
  //  setmystate(&t);
  pthread_mutex_unlock(&t);
}

