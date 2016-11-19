/// DESC: Test whether we produce use-after-free on pthread_create
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Compile and link with -pthread
void *ptr_func(void *y)
{
  int *i;
  i = (int*)y;
  int j = 0;
  printf("%d\n", *i);
  for (j=0; j<10; j++)
  {
    printf("%d\n", ++(*i));
  }
  pthread_exit(NULL);
}

int main()
{
  int *x = calloc(1,10);
  pthread_t th1;
  int ret;
  free(x);
  ret = pthread_create(&th1, NULL, ptr_func, (void*)x);
  printf("%d\n", ret);
  pthread_exit(NULL);
}


