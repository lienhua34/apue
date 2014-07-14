#include "../../common/apue.h"

static void sig_int(int);

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

int
main(void)
{
  sigset_t newmask, oldmask, waitmask;

  pr_mask("program start: ");
 
  if (signal(SIGINT, sig_int) == SIG_ERR) {
    err_sys("signal(SIGINT) error");
  }
  sigemptyset(&waitmask);
  sigaddset(&waitmask, SIGUSR1);
  sigemptyset(&newmask);
  sigaddset(&newmask, SIGINT);
  
  /*
   * Block SIGINT and save current signal mask.
   */
  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
    err_sys("SIG_BLOCK error");
  }
  
  /*
   * Critical region of code.
   */
  pr_mask("in critical region: ");
  
  /*
   * Pause, allowing all signals except SIGUSR1.
   */
  if (sigsuspend(&waitmask) != -1) {
    err_sys("sigsuspend error");
  }
  
  pr_mask("after return from sigsuspend: ");
  
  /*
   * Reset signal mask which unblocks SIGINT.
   */
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
    err_sys("SIG_SETMASK error");
  }

  /*
   * And continue processing...
   */
  pr_mask("program exit: ");
  exit(0);
}

static void
sig_int(int signo)
{
  pr_mask("\nin sig_int: ");
}
