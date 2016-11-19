/// DESC: testing forkchild
/// APPNAME: parent_prog
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <sys/types.h>
#include <sys/wait.h>

void run_child_code(void);
void run_parent_code(void);

int main(int argc, char *argv[])
{
    /* child process changes its name */
    strncpy(argv[0], "parent_prog", strlen(argv[0]));
    printf("Parent process %d (%s)\n", getpid(), argv[0]);
    //run_child_code();
    return EXIT_SUCCESS;
}
