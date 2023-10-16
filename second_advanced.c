#include "main.h"

/**
 * print_S - prints ASCII value
 * @c: char to be printed
 *
 * Return: count.
 */

int print_S(char *c)
{
	int count = 0, i = 0, value;

	while (c[i] != '\0')
	{
		if (c[i] < 32 || c[i] >= 127)
		{
			count += write_str("\\x");
			value = (int)c[i];
			if (value < 16)
			{
				write_char(0 + '0');
				count++;
			}
			count += print_c_hexa((unsigned int)value);
		}
		else
		{
			write_char(c[i]);
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * print_address - prints the address of any pointer
 * @addr: variable to be printed.
 *
 * Return: counter.
 */

int print_address(void *addr)
{
	unsigned long value = (unsigned long)addr;
	char holder[16];
	int i, count = 2;

	write_char('0');
	write_char('x');
	for (i = 0; i < 16; i++)
	{
		holder[i] = value % 16;
		value /= 16;
	}
	for (i = 11; i >= 0; i--)
	{
		if (holder[i] < 10)
		{
			write_char(holder[i] + '0');
			count++;
		}
		else
		{
			write_char(holder[i] - 10 + 'a');
			count++;
		}
	}
	return (count);
}

/**
 * print_reversed - prints string in reverse
 * @str: string to be reversed
 *
 * Return: count
 */

int print_reversed(char *str)
{
	int count = 0, i = 0;

	for (i = 0; str[i] != '\0'; i++)
		;
	i--;
	while (i >= 0)
	{
		write_char(str[i]);
		count++;
		i--;
	}
	return (count);
}

/**
 * print_R - prints rot13 string
 * @str: string to be printed
 *
 * Return: count.
 */

int print_R(char *str)
{
	int i = 0, count = 0;
	char alpha[] ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (*str != '\0')
	{
		for (i = 0; i <= 52; i++)
		{
			if (*str == alpha[i])
			{
				write_char(rot[i]);
				count++;
				break;
			}
		}
		str++;
	}
	return (count);
}
