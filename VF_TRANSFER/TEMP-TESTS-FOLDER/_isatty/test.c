/// DESC: test whether isatty produces use after free
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
  char *obb = calloc(1, 10);
  strcpy(obb, "test");
  FILE* fp = stdin;
  printf ("%d\n", isatty(fileno(fp)));
}
