#include "../../common/apue.h"
#include <fcntl.h>

/*
 * the first argument is a file descriptor.
 * print the file labels for the file descriptor.
 */

/*
 *[test examples]:
 * lienhua34:examples$ ./flprinter 0 < /dev/tty
 * read only
 * lienhua34:examples$ ./flprinter 1 > temp.foo
 * lienhua34:examples$ cat temp.foo
 * write only
 * lienhua34:examples$ ./flprinter 2 2>>temp.foo
 * write only, append
 */

int
main(int argc, char *argv[])
{
  int val;
  
  if (argc != 2) {
    err_quit("usage: a.out <descriptor#>");
  }

  if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
    err_sys("fcntl error for fd %d", atoi(argv[1]));
  }

  switch (val & O_ACCMODE) {
  case O_RDONLY:
    printf("read only");
    break;

  case O_WRONLY:
    printf("write only");
    break;

  case O_RDWR:
    printf("read write");
    break;

  default:
    err_dump("unknown access mode");
    break;
  }

  if (val & O_APPEND) {
    printf(", append");
  }

  if (val & O_NONBLOCK) {
    printf(", nonblocking");
  }

#if defined(O_SYNC)
  if (val & O_SYNC) {
    printf(", synchronous writes");
  }
#endif

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
  if (val & O_FSYNC) {
    printf(", synchronous writes");
  }
#endif
  
  putchar('\n');
  exit(0);

}
