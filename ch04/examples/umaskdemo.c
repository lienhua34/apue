#include "../../common/apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int
main(void)
{
  umask(0);
  if (creat("foo", RWRWRW) < 0) {
    err_sys("creat error for foo");
  }
  
  mode_t oldmask = umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  printf("oldmask:%d \n", oldmask);
  if (creat("bar", RWRWRW) < 0) {
    err_sys("creat error for bar");
  }
  exit(0);
}
