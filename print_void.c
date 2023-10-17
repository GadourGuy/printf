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
/**
 * print_long_oct - prints long oct* @n: number to be printed
 * @n: number to be printed
 * Return: count
 */

int print_un_octal(unsigned long int n)
{
	int count = 0;

	if (n != 0)
	{
		count = print_un_octal(n / 8);
		write_char(n % 8 + '0');
		count++;
	}
	return (count);
}
/**
 * print_s_hexa - prints a long number in hexa
 * @n: number to be printed
 * Return: count
 */
int print_uns_hexa(unsigned long int n)
{
	unsigned long int x, count = 0;
	char c;

	if (n != 0)
	{
		count = print_uns_hexa(n / 16);
		x = n % 16;
		if (x < 10)
		write_char(x + '0');
		else if (x >= 10 && x < 16)
		{
			c = 'a' + (x - 10);
			write_char(c);
		}
		count++;
	}
	return (count);
}
/**
 * print_c_hexa - prints a long number in hexa
 * @n: number to be printed
 * Return: count
 */
int print_unc_hexa(unsigned long int n)
{
	unsigned long int x, count = 0;
	char c;

	if (n != 0)
	{
		count = print_unc_hexa(n / 16);
		x = n % 16;
		if (x < 10)
			write_char(x + '0');
		else if (x >= 10 && x < 16)
		{
			c = 'A' + (x - 10);
			write_char(c);
		}
		count++;
	}
	return (count);
}
