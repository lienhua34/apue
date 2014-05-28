#include "../../common/apue.h"
#include <time.h>

int
main(void)
{
  time_t ti;
  struct tm *tmptr; 
  char *asctptr, *ctptr;
  char buf[2048];

  ti = time(NULL);

  /* gmtime & localtime
   * struct tm *gmtime(const time_t *calptr);
   * struct tm *localtime(const time_t *calptr);
  */
  //tmptr = gmtime(&ti);
  tmptr = localtime(&ti);
  printf("tm_sec: %d\n", tmptr->tm_sec); /* seconds after the minute: [0 - 60] */
  printf("tm_min: %d\n", tmptr->tm_min); /* minutes after the hour: [0 - 59] */
  printf("tm_hour: %d\n", tmptr->tm_hour); /* hours after midnight: [0 - 23] */
  printf("tm_mday: %d\n", tmptr->tm_mday); /* day of the month: [1 - 31] */
  printf("tm_mon: %d\n", tmptr->tm_mon); /* months since January: [0 - 11] */
  printf("tm_year: %d\n", tmptr->tm_year + 1900); /* years since 1900 */
  printf("tm_wday: %d\n", tmptr->tm_wday); /* days since Sunday: [0 - 6] */
  printf("tm_yday: %d\n", tmptr->tm_yday); /* days since January 1: [0 - 365] */
  printf("tm_isdst: %d\n", tmptr->tm_isdst); /* daylight saving time flag: <0, 0, >0 */


  /*
   * char *asctime(const struct tm*tmptr);
   * char *ctime(const time_t *calptr);
   */
  asctptr = asctime(tmptr);
  ctptr = ctime(&ti);
  printf("asctime: %s\n", asctptr);
  printf("ctime: %s\n", ctptr);

  /*
   * size_t strftime(char *restrict buf, size_t maxsize,
                     const char *restrict format,
		     const struct tm *restrict tmptr);
   *
   */
  strftime(buf, 2048,
	   "[%%a]abbr week day: %a\n"
	   "[%%A]completely week day: %A\n"
	   "[%%b]abbr month: %b\n"
	   "[%%B]completely month: %B\n"
	   "[%%c]date and time: %c\n"
	   "[%%C]year/100: [00~99]: %C\n"
	   "[%%d]day of the month[01~31]: %d\n"
	   "[%%D]date[MM/DD/YY]: %D\n"
	   "[%%e]day of the month[1~31]: %e\n"
	   "[%%F]ISO 8601 date format[YYYY-MM-DD]: %F\n"
	   "[%%g]ISO 8601 the last two number of the year[00~99]: %g\n"
	   "[%%G]ISO 8601 the year: %G\n"
	   "[%%h]the same as %%b: %h\n"
	   "[%%H]the hour[00~23]: %H\n"
	   "[%%I]the hour[00~12]: %I\n"
	   "[%%j]day of the year[001~366]: %j\n"
	   "[%%m]the month[01~12]: %m\n"
	   "[%%M]minutes of the hour[00~59]: %M\n"
	   "[%%n]newline:%n"
	   "[%%p]AM/PM: %p\n"
	   "[%%r]local time: %r\n"
	   "[%%R]the same as \"%%H:%%M\": %R\n"
	   "[%%S]seconds of the hour[00~60]: %S\n"
	   "[%%T]the same as \"%%H:%%M:%%S\": %T\n"
	   "[%%u]days since Monday[Monday=1, 1~7]: %u\n"
	   "[%%U]: %U\n"
	   "[%%V]: %V\n"
	   "[%%w]days since Sunday[Sunday=0, 0~6]: %w\n"
	   "[%%W]: %W\n"
	   "[%%x]date: %x\n"
	   "[%%X]time: %X\n"
	   "[%%y]the last two number of the year[00~99]: %y\n"
	   "[%%Y]the year: %Y\n"
	   "[%%z]: %z\n"
	   "[%%Z]: %Z\n",
	   tmptr);
  printf("%s", buf);

  exit(0);
}
