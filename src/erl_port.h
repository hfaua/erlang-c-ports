#ifndef ERL_PORT_H_
#define ERL_PORT_H_

#define STDIN  0
#define STDOUT 1

int erl_read(unsigned char *buffer);
int erl_write(const unsigned char *buffer, int n);

#endif
