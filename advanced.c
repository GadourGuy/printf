#include "main.h"

/**
 * print_binary - prints a number in binary
 * @n: number to be printed
 * @count: count of digits.
 *
 * Return: number of digits
 */

int print_binary(int n)
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
