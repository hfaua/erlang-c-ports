#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SZ 256

int erl_read(unsigned char *buf, int n)
{
  int len = 0;
  int got = 0;
  int i = 0;

  read(0, &len, 1);

  do
  {
    if ((i = read(0, buf + got, len - got)) <= 0)
      return got;
    got += i;
  }
  while (got < len);

  return len;
}

int erl_write(unsigned char *buf, int n)
{
  unsigned char len = 0;
  int wrote = 0;
  int i = 0;

  assert(n <= UCHAR_MAX);

  len = (unsigned char) n;
  write(1, &len, 1);

  do
  {
    if ((i = write(1, buf + wrote, len - wrote)) <= 0)
      return wrote;
    wrote += i;
  }
  while (wrote < len);

  return n;
}

int main()
{
  unsigned char buf[BUF_SZ] = {0};
  int len = 0;

  while((len = erl_read(buf, BUF_SZ)) > 0)
  {
    erl_write(buf, len);
  }

  return 0;
}
