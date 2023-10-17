#include "main.h"
/**
 *
 */
int print_long(long int n)
{
	int count = 0;
	long int i;

	if (n < 0)
	{
		n *= -1;
		write_char('-');
	}
	i = n;
	count++;
	if (i / 10 != 0)
	{
		count = print_number(i / 10);
		count++;
	}
	write_char((i % 10) + '0');
	return (count);
}

/**
 *
 * */
int print_long_unsign(long unsigned int u)
{
	int count = 1;

	if (u / 10 != 0)
	{
		count = print_unsign(u / 10);
		count++;
	}
	write_char((u % 10) + '0');
	return (count);
}
