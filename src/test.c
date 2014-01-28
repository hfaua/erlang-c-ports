#include "erl_port.h"

int main()
{
  unsigned char buffer[256] = {0};
  int           length      = 0;

  while( (length = erl_read(buffer)) > 0)
  {
    erl_write(buffer, length);
  }

  return 0;
}
