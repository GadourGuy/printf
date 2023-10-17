#include "main.h"
/**
 * print_long - a function to print long int
 * @n: long int to be printed
 * Return: count of printed chars
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
 * print_long_unsign - a function to print long unsigned int
 * @u: long unsigned int to be printed
 * Return: count of printed chars
 */
int print_long_unsign(unsigned long int u)
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
