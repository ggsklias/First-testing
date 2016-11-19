/// DESC: testing forkchild
/// APPNAME: child_prog
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
  pid_t *pid = calloc(1, sizeof(pid_t));
  //free(pid)
  *pid = fork();
  if (*pid == 0)
  {
    /* child process changes its name */
    strncpy(argv[0], "child_prog", strlen(argv[0]));
    printf("Child process %d (%s)\n", getpid(), argv[0]);
    run_child_code();
    exit(0);
  }
  else if (*pid > 0)
  {
    /* parent */
    printf("Parent process %d (%s)\n", getpid(), argv[0]);
    run_parent_code();
    int status;
    pid_t r = waitpid(*pid, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0 && r != -1)
      exit(0);
    else
      exit(1);
  }
  else
    err(1, "fork failed");
}
