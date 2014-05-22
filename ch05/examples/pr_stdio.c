#include "../../common/apue.h"

/* run cases:
lienhua34:examples$ ./pr_stdio
enter any character
lsjdf
one line to standard error
stream = stdin, line buffered, buffer size = 1024
stream = stdout, line buffered, buffer size = 1024
stream = stderr, unbuffered, buffer size = 1
stream = /etc/motd, fully buffered, buffer size = 4096

lienhua34:examples$ ./pr_stdio < /etc/motd > std.out 2> std.err
lienhua34:examples$ cat std.err
one line to standard error
lienhua34:examples$ cat std.out
enter any character
stream = stdin, fully buffered, buffer size = 4096
stream = stdout, fully buffered, buffer size = 4096
stream = stderr, unbuffered, buffer size = 1
stream = /etc/motd, fully buffered, buffer size = 4096
 */

void pr_stdio(const char *, FILE *);

int
main(void)
{
  FILE *fp;
  fputs("enter any character\n", stdout);
  if (getchar() == EOF) {
    err_sys("getchar error");
  }

  fputs("one line to standard error\n", stderr);

  pr_stdio("stdin", stdin);
  pr_stdio("stdout", stdout);
  pr_stdio("stderr", stderr);
  
  if ((fp = fopen("/etc/motd", "r")) == NULL) {
    err_sys("fopen error");
  }
  if (getc(fp) == EOF) {
    err_sys("getc error");
  }
  pr_stdio("/etc/motd", fp);
  
  exit(0);
}

void
pr_stdio(const char *name, FILE *fp)
{
  printf("stream = %s, ", name);

  /*
   * The following is nonportable.
   */
  if (fp->_IO_file_flags & _IO_UNBUFFERED) {
    printf("unbuffered");
  } else if (fp->_IO_file_flags & _IO_LINE_BUF) {
    printf("line buffered");
  } else {
    printf("fully buffered");
  }
  printf(", buffer size = %d\n", fp->_IO_buf_end - fp->_IO_buf_base);
  
}
