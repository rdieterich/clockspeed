#include <time.h>
#include "taia.h"

/* XXX: breaks tai encapsulation */

void taia_now(struct taia *t)
{
  struct timespec now;
  clock_gettime(CLOCK_REALTIME, &now);
  t->sec.x = 4611686018427387914ULL + (uint64_t) now.tv_sec;
  t->nano = now.tv_nsec;
  t->atto = 0;
}
