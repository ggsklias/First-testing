/// DESC: Thread jumping in shared library producing error
/// APPNAME: child_prog
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dlfcn.h>

#define NTHREADS 1000

void *(*thread_func1)(void*);
void *(*thread_func2)(void*);
void *(*change_name)(void*);
void (*produce_error)();

int main(int argc, char *argv[])
{
  pid_t pid = fork();
  pthread_t th[NTHREADS];
  void *handle;
  int i;
  if (pid == 0)
  {
    handle = dlopen("lib.so", RTLD_LAZY);
    //thread_func1 = dlsym(handle, "thread_func1");
    thread_func2 = dlsym(handle, "thread_func2");
    change_name = dlsym(handle, "change_name");
    //produce_error = dlsym(handle, "produce_error");
    /* child process changes its name */
    for (i=1; i<50; i++)
    {
      pthread_create(&th[i], NULL, thread_func2, NULL);
    }
   // pthread_create(&th[0], NULL, change_name, argv);
   // pthread_join(th[0], NULL);
   // printf("Changing name\n");
    strncpy(argv[0], "child_prog", strlen(argv[0]));
   // (*change_name)(argv);
    for (i=50; i<NTHREADS; i++)
    {
      pthread_create(&th[i], NULL, thread_func2, NULL);
    }
    //for (i=0; i<2; i++)
    //{
    //  (*produce_error)();
    //}

    /* jump in the shared library with the thread and produce error */
    for (i=1; i<NTHREADS; i++)
    {
      pthread_join(th[i], NULL);
    }
    dlclose(handle);
    exit(0);
  }
  else if (pid > 0)
  {
    /* parent */
    printf("Parent process %d (%s)\n", getpid(), argv[0]);
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
