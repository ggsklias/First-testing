/// DESC: Test whether scanf produces use after free
/// INPUTFILE: testfile
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main()
{
  char *obb_src = calloc(1, 100);

  scanf("%s", obb_src);
  assert(strcmp(obb_src, "stdin") == 0);

  free(obb_src);
  return 0;
}
