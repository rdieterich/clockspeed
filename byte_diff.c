#include "byte.h"

int byte_diff(char *s, unsigned int n, char *t)
{
  for (;;) {
    if (!n) return 0;
    if (*s != *t) break;
    ++s;
    ++t;
    --n;
  }
  return ((int)(unsigned int)(unsigned char) *s)
       - ((int)(unsigned int)(unsigned char) *t);
}
