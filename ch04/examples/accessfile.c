#include "../../common/apue.h"
#include <fcntl.h>

/*
 *[run examples]:
 * lienhua34:examples$ ls -l accessfile
 * -rwxrwxr-x 1 lienhua34 lienhua34 7869  5月 11 20:30 accessfile
 * lienhua34:examples$ ./accessfile accessfile
 * read access OK
 * open for reading OK
 * lienhua34:examples$ ls -l /etc/shadow
 * -rw-r----- 1 root shadow 1143  4月  6 19:27 /etc/shadow
 * lienhua34:examples$ ./accessfile /etc/shadow
 * access error for /etc/shadow: Permission denied
 * open error for /etc/shadow: Permission denied
 *
 * If uses "chown root accessfile" and  to change the owner of file "accessfile",
 * and uses "chmod u+s accessfile" to set the set-user-ID flag of file "accessfile", then
 * lienhua34:examples$ ./accessfile /etc/shadow
 * access error for /etc/shadow: Permission denied
 * open for reading OK
 * Why?
 */

int
main(int argc, char *argv[])
{
  if (argc != 2){
    err_quit("usage: accessfile <pathname>");
  }

  if (access(argv[1], R_OK) < 0) {
    err_ret("access error for %s", argv[1]);
  } else {
    printf("read access OK\n");
  }

  if (open(argv[1], O_RDONLY) < 0) {
    err_ret("open error for %s", argv[1]);
  } else {
    printf("open for reading OK\n");
  }
  exit(0);
}
				   
