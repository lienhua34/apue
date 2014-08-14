#include "../../common/apue.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define QLEN 10

/*
 * Create a server endpoint of a connection.
 * Returns fd if all OK, <0 on error.
 */
int
serv_listen(const char *name)
{
  int fd, len, err, rval;
  struct sockaddr_un un;

  /* Create a UNIX domain stream exists */
  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
    return(-1);
  }
  unlink(name); /* in case it already exiest */

  /* fill in socket address structure */
  memset(&un, 0, sizeof(un));
  un.sun_family = AF_UNIX;
  strcpy(un.sun_path, name);
  len = offsetof(struct sockaddr_un, sun_path) + strlen(name);

  /* bind the name to the descriptor */
  if (bind(fd, (struct sockaddr *)&un, len) < 0) {
    rval = -2;
    goto errout;
  }

  if (listen(fd, QLEN) < 0) { /* tell kernal we're a server */
    rval = -3;
    goto errout;
  }
  return(fd);

 errout:
  err = errno;
  close(fd);
  errno = err;
  return(rval);
}
