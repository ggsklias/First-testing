/// DESC: test whether lseek produces a use after free(if possible)
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  FILE *fp;
  fp = fopen ("testfile","w");
  fclose(fp);
  printf("%d\n", isatty(fileno(fp)));
}
