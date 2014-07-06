#include "../../common/apue.h"
#include <unistd.h>

int
main(void)
{
  char *loginUser;

  if ((loginUser = getlogin()) == NULL) {
    err_sys("getlogin() error\n");
  }
  printf("user: %s\n", loginUser);
  exit(0);
}
