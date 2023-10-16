#include "main.h"

/**
 * print_S - prints ASCII value
 * @c: char to be printed
 *
 * Return: count.
 */

int print_S(char *c)
{
	int count = 0, i = 0;

	while (c[i] != '\0')
	{
		if (c[i] < 32 || c[i] >= 127)
		{
			count += write_char('\\');
			count += write_char('n');
			if (c[i] / 16 < 10)
			{
				count += write_char((c[i] / 16) + '0');

			}
			else
			{
				count += write_char((c[i] / 16) - 10 + c[i]);
			}
			if ((c[i] % 16) < 10)
			{
				count += write_char((c[i] % 16) + '0');
			}
			else
			{
				count += write_char((c[i] % 16) - 10 + c[i]);
			}
			i++;
		}
		else
		{
			write_char(*c);
			count++;
			i++;
		}
	}
	return (count);
}
