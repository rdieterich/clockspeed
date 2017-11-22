#include "str.h"

unsigned int str_len(char *s)
{
  char *t;

  t = s;
  for (;;) {
    if (!*t) return t - s;
    ++t;
  }
}
