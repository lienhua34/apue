#include "../../common/apue.h"
#include <sys/sysmacros.h>
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

/*****************************
 *run examples:
 * lienhua34:examples$ ./st_dev_demo / /home/lienhua34 /dev/tty[01]
 * /: dev = 8/1
 * /home/lienhua34: dev = 8/1
 * /dev/tty0: dev = 0/5 (character) rdev = 4/0
 * /dev/tty1: dev = 0/5 (character) rdev = 4/1
 *****************************/

int
main(int argc, char *argv[])
{
  int i;
  struct stat buf;
  
  for (i = 1; i < argc; i++) {
    printf("%s: ", argv[i]);
    if (stat(argv[i], &buf) < 0) {
      err_ret("stat error");
      continue;
    }

    printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
    if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
      printf(" (%s) rdev = %d/%d",
	     (S_ISCHR(buf.st_mode)) ? "character" : "block",
	     major(buf.st_rdev), minor(buf.st_rdev));
    }
    printf("\n");
  }

  exit(0);
}
