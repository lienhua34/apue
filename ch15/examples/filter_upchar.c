#include "../../common/apue.h"
#include <ctype.h>

int
main(void)
{
  int c;

  while ((c = getchar()) != EOF) {
    if (islower(c)) {
      c = toupper(c);
    }
    if (putchar(c) == EOF) {
      err_sys("output error");
    }
    if (c == '\n') {
      fflush(stdout);
    }
  }
  exit(0);
}
