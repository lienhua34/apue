#include "../../common/apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

/*
 * off_t lseek(int filedes, off_t offset, int whence);
 * 
 * argument "offset" can large than the file current length,
 * then writing content at the new offset will generates a hole between
 * the current file end offset to the new offset.
 */

int
main(void)
{
  int fd;
  if ((fd = open("file.hole", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE)) < 0) {
    err_sys("create error");
  }

  if (write(fd, buf1, 10) != 10) {
    err_sys("buf1 write error");
  }
  /* offset now = 10 */

  if (lseek(fd, 16384, SEEK_SET) == -1) {
    err_sys("lseek error");
  }
  /* offset now = 16384 */

  if (write(fd, buf2, 10) != 10) {
    err_sys("buf2 write error");
  }
  /* offset now = 16394 */

  exit(0);
}

  
