#include "../../common/apue.h"
#include <setjmp.h>
#include <time.h>

/*
lienhua34:examples$ ./sigjmpdemo &
[1] 2608
lienhua34:examples$ starting main: 
kill -USR1 2608
lienhua34:examples$ starting sig_usr1: SIGUSR1 
in sig_alrm: SIGUSR1 SIGALRM 
finishing sig_usr1: SIGUSR1 
ending main: 

[1]+  完成                  ./sigjmpdemo
lienhua34:examples$ 
 */

static void sig_usr1(int), sig_alrm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

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
  if (signal(SIGUSR1, sig_usr1) == SIG_ERR) {
    err_sys("signal(SIGUSR1) error");
  }
  if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
    err_sys("signal(SIGUSR2) error");
  }
  pr_mask("starting main: ");
  
  if (sigsetjmp(jmpbuf, 1)) {
    pr_mask("ending main: ");
    exit(0);
  }
  canjump = 1;

  for ( ; ; ) {
    pause();
  }
}

static void
sig_usr1(int signo)
{
  time_t starttime;
  
  if (canjump == 0) {
    return;
  }

  pr_mask("starting sig_usr1: ");
  alarm(3);
  starttime = time(NULL);
  for ( ; ; ) {
    if (time(NULL) > starttime + 5) {
      break;
    }
  }
  pr_mask("finishing sig_usr1: ");
  
  canjump = 0;
  siglongjmp(jmpbuf, 1);
}

static void
sig_alrm(int signo)
{
  pr_mask("in sig_alrm: ");
}
