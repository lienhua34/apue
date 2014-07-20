#include "../../common/apue.h"
#include <pthread.h>

struct product
{
  struct product *p_next;
  int num;
};

struct product *workq;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void *
thr_consumer(void *arg)
{
  struct product *pp;

  for (;;) 
  {
    pthread_mutex_lock(&qlock);
    while (workq == NULL) 
    {
      pthread_cond_wait(&qready, &qlock);
    }
    pp = workq;
    workq = workq->p_next;
    pthread_mutex_unlock(&qlock);
    printf("[%s] product %d\n",(char *)arg, pp->num);
    free(pp);
    sleep(1);
  }
  return((void *)0);
}

void *
thr_producer(void *arg)
{
  int num = 0;
  for (;;)
  {
      pthread_mutex_lock(&qlock);
      struct product *product = (struct product *)malloc(sizeof(struct product));
      product->num = num++;
      product->p_next = workq;
      workq = product;
      printf("[producer] product %d\n", product->num);
      pthread_mutex_unlock(&qlock);
      pthread_cond_signal(&qready);
      sleep(1);
  }
  return((void *)0);
}

int
main(void)
{
  int err;
  pthread_t ptid, ctid1, ctid2;

  err = pthread_create(&ptid, NULL, thr_producer, NULL);
  if (err != 0) 
  {
    err_quit("can't create thread producer: %s\n", strerror(err));
  }

  err = pthread_create(&ctid1, NULL, thr_consumer, "consumer 1");
  if (err != 0)
  {
    err_quit("can't create thread consumer 1: %s\n", strerror(err));
  }

  err = pthread_create(&ctid2, NULL, thr_consumer, "consumer 2");
  if (err != 0) 
  {
    err_quit("can't create thread consumer 2: %s\n", strerror(err));
  }

  for(;;)
  {
  }

  exit(0);
}

    
  

