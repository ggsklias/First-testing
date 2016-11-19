#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void produce_error1(void)
{
  char *memleak = calloc(1, 10);
  printf("Creating memory leak\n");
}

void produce_error2(void)
{
  char *memleak = calloc(1, 10);
  printf("Creating memory leak\n");
}
void *thread_func1(void *arg)
{
  produce_error1();
  return EXIT_SUCCESS;
}

void *thread_func2(void *arg)
{
  produce_error2();
  return EXIT_SUCCESS;
}

void *change_name(void *arg)
{
  char **argv = (char **)arg;
  printf("Changing name\n");
  strncpy(argv[0], "child_prog", strlen(argv[0]));
  printf("Child process %d (%s)\n", getpid(), argv[0]);
}

