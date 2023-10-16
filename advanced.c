#include "main.h"

/**
 * print_binary - prints a number in binary
 * @n: number to be printed
 *
 * Return: number of digits
 */

int print_binary(unsigned int n)
{
	int count = 0;

	if (n != 0)
	{
		count = print_binary(n / 2);
		if (n % 2 == 0)
		{
			write_char(0 + '0');
		}
		else
		{
			write_char(1 + '0');
		}
		count++;
	}
	return (count);
}
/**
 * print_unsign - print unsigned number
 * @u: number to be printed
 * Return: count
 */
int print_unsign(unsigned int u)
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
 * print_octal - prints a number in octal
 * @n: number to be printed
 * Return: count
 */

int print_octal(unsigned int n)
{
	int count = 0;

	if (n != 0)
	{
		count = print_octal(n / 8);
		write_char(n % 8 + '0');
		count++;
	}
	return (count);
}

/**
 * print_s_hexa - prints a number in hexa
 * @n: number to be printed
 * Return: count
 */
int print_s_hexa(unsigned int n)
{
	unsigned int x, count = 0;
	char c;

	if (n != 0)
	{
		count = print_s_hexa(n / 16);
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
 * * print_c_hexa - prints a number in hexa
 * @n: number to be printed
 * Return: count
 */
int print_c_hexa(unsigned int n)
{
	unsigned int x, count = 0;
	char c;

	if (n != 0)
	{
		count = print_c_hexa(n / 16);
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
