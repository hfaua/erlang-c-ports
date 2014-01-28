#include <unistd.h>
#include "erl_port.h"

int erl_read(unsigned char *buffer)
{
  unsigned char length     = 0;
  int           chunk_size = 0;
  int           remaining  = 0;

  // Read packet length
  read(STDIN, &length, sizeof(length));

  remaining = length;

  do
  {
    chunk_size = read(STDIN, buffer, remaining);

    if (chunk_size == -1)
      return 0;

    buffer    += chunk_size;
    remaining -= chunk_size;
  }
  while (remaining > 0);

  return length;
}
