#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
  char *padding[2];
  char *endptr;
} buzz;

int main(void)
{
  char *str = "INF";
  buzz.endptr = str;
  char *endptr = buzz.padding[2];
  printf("To %d inity... and beyond!\n", atoi(endptr));

  return EXIT_SUCCESS;
}
