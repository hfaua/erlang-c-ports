#include <stdio.h>

int solve(unsigned char *buffer, int length, int n, int i, int a)
{
	if (a == n)
		return 1;

	if (i == length)
		return 0;

	return solve(buffer, length, n, i + 1, a + buffer[i])
	    || solve(buffer, length, n, i + 1, a);
}
