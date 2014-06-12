#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  char *envVal;
  char *myenv;

  envVal = getenv("PATH");
  if (envVal == NULL) {
    printf("not environment variable PATH\n");
  } else {
    printf("PATH=%s\n", envVal);
  }

  if (setenv("myenv", "li enhua", 0) == -1) {
    printf("setenv error\n");
  } else {
    myenv = getenv("myenv");
    printf("myenv=%s\n", myenv);
  }

  if (putenv("myenv1=haha") != 0) {
    printf("putenv error\n");
  } else {
    myenv = getenv("myenv1");
    printf("myenv1=%s\n", myenv);
  }

  exit(0);
}
