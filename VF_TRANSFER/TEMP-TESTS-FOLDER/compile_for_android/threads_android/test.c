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

void empty(void)
{

}

void *change_proc_name(char *argv[])
{
    strncpy(argv[0], "child_prog", strlen(argv[0]));
    empty();
    printf("Child process %d (%s)\n", getpid(), argv[0]);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
  pid_t pid = fork();
  if (pid == 0)
  {
    /* child process changes its name */
    pthread_t th1;
    pthread_create(&th1, NULL, change_proc_name, (char *)argv);
    pthread_join(th1, NULL);
    run_child_code();
    exit(0);
  }
  else if (pid > 0)
  {
    /* parent */
    run_parent_code();
    int status;
    pid_t r = waitpid(pid, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0 && r != -1)
      exit(0);
    else
      exit(1);
  }
  else
    err(1, "fork failed");
}
