#include "../../common/apue.h"

/*
 * run examples:
 * lienhua34:examples$ ./lseek_demo < /etc/motd
 * seek OK
 * lienhua34:examples$ cat < /etc/motd | ./lseek_demo
 * cannot seek
 */

int
main(void)
{
  if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
    printf("cannot seek\n");
  } else {
    printf("seek OK\n");
  }
  exit(0);
}
