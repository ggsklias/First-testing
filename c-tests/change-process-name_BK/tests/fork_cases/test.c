/// DESC: testing forkchild
/// APPNAME: child_prog3
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
  pid_t pid = fork();
  if (pid == 0)
  {
    /* child process changes its name */
    strncpy(argv[0], "child_prog", strlen(argv[0]));
    printf("Child process %d (%s)\n", getpid(), argv[0]);
    run_child_code();
    exit(0);
  }
  else if (pid > 0)
  {
    /* parent */
    printf("Parent process %d (%s)\n", getpid(), argv[0]);
    run_parent_code();
    int status;
    pid_t r = waitpid(pid, &status, 0);
    if (!(WIFEXITED(status) && WEXITSTATUS(status) == 0 && r != -1))
      exit(1);
  }
  else
    err(1, "fork failed");

  pid_t pid1 = fork();
  if (pid1 == 0)
  {
    /* child process changes its name */
    strncpy(argv[0], "child_prog1", strlen(argv[0]));
    printf("Child process1 %d (%s)\n", getpid(), argv[0]);
    run_child_code();
    exit(0);
  }
  else if (pid1 > 0)
  {
    /* parent */
    printf("Parent process %d (%s)\n", getpid(), argv[0]);
    run_parent_code();
    int status;
    pid_t r = waitpid(pid1, &status, 0);
    if (!(WIFEXITED(status) && WEXITSTATUS(status) == 0 && r != -1))
      exit(1);
  }
  else
    err(1, "fork failed");

  pid_t pid2 = fork();
  if (pid2 == 0)
  {
    /* child process changes its name */
    strncpy(argv[0], "child_prog2", strlen(argv[0]));
    printf("Child process2 %d (%s)\n", getpid(), argv[0]);
    run_child_code1();
    exit(0);
  }
  else if (pid2 > 0)
  {
    /* parent */
    printf("Parent process1 %d (%s)\n", getpid(), argv[0]);
    run_parent_code();
    int status;
    pid_t r = waitpid(pid2, &status, 0);
    if (!(WIFEXITED(status) && WEXITSTATUS(status) == 0 && r != -1))
      exit(1);
  }
  else
    err(1, "fork failed");

  pid_t pid3 = fork();
  if (pid3 == 0)
  {
    /* child process changes its name */
    strncpy(argv[0], "child_prog3", strlen(argv[0]));
    printf("Child process3 %d (%s)\n", getpid(), argv[0]);
    run_child_code2();
    exit(0);
  }
  else if (pid3 > 0)
  {
    /* parent */
    printf("Parent process1 %d (%s)\n", getpid(), argv[0]);
    run_parent_code();
    int status;
    pid_t r = waitpid(pid3, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0 && r != -1)
      exit(0);
    else
      exit(1);
  }
  else
    err(1, "fork failed");
}
