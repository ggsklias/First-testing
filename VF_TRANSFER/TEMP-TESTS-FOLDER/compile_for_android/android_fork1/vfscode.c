#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <sys/types.h>
#include <sys/wait.h>
int foo;

/* This is called from native code, after a fork.
 * We are testing that analysis kicks in when we enter this function. */
void empty(void)
{
    foo = 1;
}

void run_child_code(char *argv[])
{
    strncpy(argv[0], "child_prog", strlen(argv[0]));
    empty();
    printf("Child process %d (%s)\n", getpid(), argv[0]);
}


/* This is called from native code in fork-parent path. */
void run_parent_code(void)
{
  foo = 89;
}
