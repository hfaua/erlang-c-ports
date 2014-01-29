#include "erl_port.h"
#include "recursion.h"

int main()
{
  unsigned char buffer[256] = {0};
  int           length      = 0;

  while( (length = erl_read(buffer)) > 0)
  {
  	unsigned char  expected =  buffer[0];
  	unsigned char *num_buff =  &buffer[1];
  	int            num_count = length - 1;

  	if(solve(num_buff, num_count, expected, 0, 0))
  		buffer[0] = 1;
  	else
  		buffer[0] = 0;

  	erl_write(buffer, 1);
  }

  return 0;
}
