#include "../../common/apue.h"


Sigfunc *
signal(int signo, Sigfunc *func)
{
  struct sigaction act, oact;
  
  act.sa_handler = func;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  if (signo == SIGALRM) {
#ifdef SA_INTERRUPT
    act.sa_flags |= SA_INTERRUPT;
#endif
  } else {
#ifdef SA_RESTART
    act.sa_flags |= SA_RESTART;
#endif
  }
  if (sigaction(signo, &act, &oact) < 0) {
    return(SIG_ERR);
  }
  return(oact.sa_handler);
}

volatile sig_atomic_t quitflag; /* set nonzero by signal handler */

static void
sig_int(int signo)
{
  if (signo == SIGINT) {
    printf("\ninterrupt\n");
  } else if (signo == SIGQUIT) {
    quitflag = 1; /*set flag for main loop */
  } 
}

/*
lienhua34:examples$ ./sigsuspenddemo1
C-c
interrupt
C-c
interrupt
C-c
interrupt
C-\
 */

int
main(void)
{
  sigset_t newmask, oldmask, zeromask;

  if (signal(SIGINT, sig_int) == SIG_ERR) {
    err_sys("signal(SIGINT) error");
  }
  if (signal(SIGQUIT, sig_int) == SIG_ERR) {
    err_sys("signal(SIGQUIT) error");
  }
  
  sigemptyset(&zeromask);
  sigemptyset(&newmask);
  sigaddset(&newmask, SIGQUIT);
  
  /*
   * Block SIGQUIT and save current signal mask.
   */
  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
    err_sys("SIG_BLOCK error");
  }
  
  while (quitflag == 0) {
    sigsuspend(&zeromask);
  }

  /*
   * SIGQUIT has been caught and is now blocked; do whatever.
   */
  quitflag = 0;

  /*
   * Reset signal mask which unblocks SIGQUIT.
   */
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
    err_sys("SIG_SETMASK, ERROR");
  }
  exit(0);
}
