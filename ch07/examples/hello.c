#include <stdio.h>

/***************************
lienhua34:examples$ cc hello.c
lienhua34:examples$ ./a.out
Hello, World
lienhua34:examples$ echo $?
13
lienhua34:examples$ cc -std=c99 hello.c
hello.c:3:1: 警告： 返回类型默认为‘int’ [默认启用]
lienhua34:examples$ ./a.out 
Hello, World
lienhua34:examples$ echo $?
0
**************************/

main()
{
  printf("Hello, World\n");
}
