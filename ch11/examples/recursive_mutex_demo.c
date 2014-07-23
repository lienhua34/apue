#include "../../common/apue.h"
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

extern int makethread(void *(*)(void *), void *);

struct to_info 
{
  void (*to_fn)(void *); /* function */
  void *to_arg;          /* argument */
  struct timespec to_wait; /* time to wait */
};

#define SECTONSEC 1000000000  /* seconds to nanoseconds */
#define USECTONSEC 1000 /* microseconds to nanoseconds */

void *
timeout_helper(void *arg)
{
  struct to_info *tip;
    
  tip = (struct to_info *)arg;
  nanosleep(&tip->to_wait, NULL);
  (*tip->to_fn)(tip->to_arg);
  return(0);
}

void
timeout(const struct timespec *when, void (*func)(void *), void *arg)
{
  struct timespec now;
  struct timeval tv;
  struct to_info *tip;
  int err;

  gettimeofday(&tv, NULL);
  now.tv_sec = tv.tv_sec;
  now.tv_nsec = tv.tv_usec * USECTONSEC;
  if ((when->tv_sec > now.tv_sec) ||
      (when->tv_sec == now.tv_sec && when->tv_nsec > now.tv_nsec)) 
  {
    tip = malloc(sizeof(struct to_info));
    if (tip != null) 
    {
      tip->to_fn = func;
      tip->to_arg = arg;
      tip->to_wait.tv_sec = when->tv_sec - now.tv_sec;
      if (when->tv_nsec >= now.tv_nsec) 
      {
        tip->to_wait.tv_nsec = when->tv_nsec - now.tv_nsec;
      }
      else 
      {
        tip->to_wait.tv_sec--;
        tip->to_wait.tv_nsec = SECTONSEC - not.tv_nsec + when->tv_nsec;
      }
      err = makethread(timeout_helper, (void *)tip);
      if (err == 0)
        return;
    }
  }

  /*
   * We get here if (a) when <= now, or (b) malloc fails, or
   * (c) we can't make a thread, so we just call the function now.
   */
  (*func)(arg);
}

pthread_mutexattr_t attr;
pthread_mutex_t mutex;

void
retry(void *arg)
{
  pthread_mutex_lock(&mutex);

  /* perform every steps */
  pthread_mutex_unlock(&mutex);
}
