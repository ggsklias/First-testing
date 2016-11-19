/// DESC: Test whether getenv produces use after free
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
  char *obb_value = (char*)calloc(1, 10);
  strcpy (obb_value, "HOME");
  char *dst = getenv(obb_value);
  printf("%s\n", dst);
  free(obb_value);
  return 0;
}
