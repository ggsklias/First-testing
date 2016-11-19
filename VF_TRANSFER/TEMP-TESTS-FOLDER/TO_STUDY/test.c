/// DESC: Test whether we produce use-after-free on pthread_join
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct {
  void** arr1[5];
  void** padding1[5];
  void** arr2[5];
  void** padding2[5];
} data;

void *func(void *x)
{
  return 0;
}

int main(void)
{
  pthread_t th1;
  char *tmp;
  pthread_create(&th1, NULL, func, tmp);
  void *obj = &data.arr1[0];
  printf("%p\n", obj);
  void *obj_tmp = &data.padding1[0];
  void *oob = obj_tmp[5];
  printf("%p\n", obj);

  pthread_join(th1, oob);
  return 0;
}

/*struct {
  void* arr1[5];
  void* padding1[5];
  void* arr2[5];
  void* padding2[5];
} data;

void *func(void *x)
{
  return 0;
}

int main(void)
{
  pthread_t th1;
  char *tmp;
  pthread_create(&th1, NULL, func, tmp);
  void **obj = &data.arr2[0];
  void **obj_tmp = &data.padding1[0];
  void **oob = &obj_tmp[5];

  pthread_join(th1, oob);
  return 0;
}*/


