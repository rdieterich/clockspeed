#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#include "substdio.h"
#include "strerr.h"
#include "exit.h"

#define FATAL "clockadd: fatal: "

unsigned char buf[16];
struct timespec tv;

int main(int argc, char **argv)
{
  unsigned long u;
  unsigned long v;
  long adj;
  struct timespec tvselect;

  if (read(0,buf,sizeof buf) != sizeof buf)
    strerr_die2x(111,FATAL,"data split across packets");

  u = buf[4];
  u <<= 8; u += buf[5];
  u <<= 8; u += buf[6];
  u <<= 8; u += buf[7];

  if (u < 2147483648UL)
    adj = u;
  else
    adj = -(4294967295UL + 1 - u);

  v = buf[8];
  v <<= 8; v += buf[9];
  v <<= 8; v += buf[10];
  v <<= 8; v += buf[11];

  /* XXX: Solaris stupidity */
  clock_gettime(CLOCK_REALTIME, &tv);
  tvselect.tv_sec = 0;
  tvselect.tv_nsec = 1000000000L - ((tv.tv_nsec + v) % 1000000000L);
  pselect(1, (fd_set *) 0, (fd_set *) 0, (fd_set *) 0, &tvselect, NULL);

  clock_gettime(CLOCK_REALTIME, &tv);
  tv.tv_sec += adj;
  tv.tv_nsec += v;
  if (tv.tv_nsec > 999999999L) {
    tv.tv_nsec -= 1000000000L;
    tv.tv_sec += 1;
  }

  if (clock_settime(CLOCK_REALTIME, &tv) == -1)
    strerr_die2sys(111,FATAL,"unable to clock_settime: ");

  _exit(0);
  return 0;
}
