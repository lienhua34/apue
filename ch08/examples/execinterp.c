#include "../../common/apue.h"
#include <sys/wait.h>

int
main(void)
{
  pid_t pid;
  
  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    if (execl("/home/lienhua34/program/c/apue/ch08/examples/testinterp",
	       "myarg1", "My arg2", (char *)0) < 0) {
      err_sys("execl error");
    }
  }

  if (waitpid(pid, NULL, 0) < 0) {
    err_sys("waitpid error");
  }

  exit(0);
}
