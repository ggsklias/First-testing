#include <stdlib.h>

struct {
  void* arr1[2];
  void* pad1[2];
} data;

int main(void)
{
  int a = 5;
  void **obj = &data.arr1[0];
  void **oob = &obj[2];
  int **dptr = (int**)oob;
  *dptr = &a;
  return EXIT_SUCCESS;
}


