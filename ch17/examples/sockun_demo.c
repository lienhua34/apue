#include "../../common/apue.h"
#include <sys/socket.h>
#include <sys/un.h>

/*
lienhua34:examples$ ./sockun_demo
UNIX domain socket bound
lienhua34:examples$ ls
foo.socket  makefile  sockun_demo  sockun_demo.c  sockun_demo.o
lienhua34:examples$ ls -l foo.socket 
srwxrwxr-x 1 lienhua34 lienhua34 0  8月 14 23:39 foo.socket
lienhua34:examples$ ./sockun_demo
bind failed: Address already in use
*/

int
main(void)
{
  int fd, size;
  struct sockaddr_un un;

  un.sun_family = AF_UNIX;
  strcpy(un.sun_path, "foo.socket");
  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
    err_sys("socket failed");
  }
  size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
  if (bind(fd, (struct sockaddr *)&un, size) < 0) {
    err_sys("bind failed");
  }
  printf("UNIX domain socket bound\n");
  exit(0);
}
