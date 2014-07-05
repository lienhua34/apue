#include "../../common/apue.h"
#include <sys/wait.h>

char *env_init[] = { "USER=unknown", "PATH=/tmp:", NULL};

int
main(void)
{
  pid_t pid;

  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    if (execl("/home/lienhua34/program/c/apue/ch08/examples/waitdemo",
	       "MY ARG2", (char *)0) < 0) {
      err_sys("execle error");
    }
  }

  if (waitpid(pid, NULL, 0) < 0) {
    err_sys("waitpid error");
  }

  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    if (execlp("waitdemo", "echoall", "only 1 arg", (char *)0) < 0) {
      err_sys("execlp error");
    }
  }

  exit(0);
}
