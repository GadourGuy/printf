#include "main.h"

/**
 * _strlen - gives the length of a string.
 * @s: the string.
 * Return: len.
 */
int _strlen(char *s)
{
	int len;

	while (*s != '\0')
		len++;
	return (len);
}
/**
 * write_str - writes a string
 * @str: string to be written.
 * Return: written string
 */

int write_str(char *str)
{
	int count = 0;

	while (str != NULL && *str != '\0')
	{
		write_char(*str);
		str++;
		count++;
	}
	return (count);
}
/**
 * write_char - writes a char
 * @c: char to be written
 *
 * Return: char to be written
 */

int write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 *print_number - prints an integer.
 *@n: input number
 *@count: number of input data.
 *
 * Return: count.
 */
int print_number(int n, int count)
{
	unsigned int i;

	if (n < 0)
	{
		n *= -1;
		write_char('-');
	}
	i = n;
	count++;
	i /= 10;
	if (i != 0)
	{
		count++;
		print_number(i, count);
	}
	write_char((unsigned int)n % 10 + '0');
	return (count);
}
