#include "../../common/apue.h"
#include <errno.h>

int
main(int argc, char *argv[])
{
  /*
   * #include <string.h>
   * char *strerror(int errnum);
   * 
   * maps errnum to a error message and returns a point which points to the error message
   */
  fprintf(stderr, "EACCES: %s\n", strerror(EACCES));

  /*
   * #include <stdio.h>
   * void perror(const char *msg);
   *
   * outputs the message whith msg points to, 
   * then outputs a ":" and a space,
   * then outputs the error message which errno maps to,
   * the last is a newline.
   */
  errno = ENOENT;
  perror(argv[0]);
  exit(0);
}
