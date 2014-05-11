#include "../../common/apue.h"

/*
 * 1. before running chmoddemo:
 * lienhua34:examples$ ls -l bar foo
 * -rw------- 1 lienhua34 lienhua34 0  5月 11 21:36 bar
 * -rw-rw-rw- 1 lienhua34 lienhua34 0  5月 11 21:36 foo
 * 2. after running chmoddemo:
 * lienhua34:examples$ ls -l bar foo
 * -rw-r--r-- 1 lienhua34 lienhua34 0  5月 11 21:36 bar
 * -rw-rwSrw- 1 lienhua34 lienhua34 0  5月 11 21:36 foo
 */

int
main(void)
{
  struct stat statbuf;

  /* turn on set-group-ID and turn off group-execute */
  
  if (stat("foo", &statbuf) < 0) {
    err_sys("stat error for foo");
  }
  if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
    err_sys("chmod error for foo");
  }
  
  /* set aboslute mode to "rw-r--r--" */
  if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
    err_sys("chmod error for bar");
  }
 
  exit(0);
}
