#include <unistd.h>
#include "erl_port.h"

int erl_write(const unsigned char *buffer, int n)
{
  unsigned char length     = n;
  int           chunk_size = 0;
  int           remaining  = n;

  // Write packet length
  write(STDOUT, &length, sizeof(length));

  do
  {
    chunk_size = write(STDOUT, buffer, remaining);

    if (chunk_size == -1)
      return 0;

    buffer    += chunk_size;
    remaining -= chunk_size;
  }
  while (remaining > 0);

  return n;
}
