#include <stdlib.h>
#include <stdio.h>

void
func1(void)
{
  printf("enter func1\n");
  abort();
  printf("exit func1\n");
}

int
main(void)
{
  printf("enter main\n");
  func1();
  printf("exit main\n");
  exit(0);
}
