#include <stdio.h>
#include <stdlib.h>

void
main()
{
  printf("%s\n", *environ);
  exit(0);
}
