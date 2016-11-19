/// DESC: Test whether setenv produces use after free
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
  char *obb_value = (char*)calloc(1, 10);
  strcpy(obb_value, "HOME=test");
  putenv(obb_value);
  printf ("%s\n", getenv("HOME"));
  free(obb_value);
  return 0;
}
