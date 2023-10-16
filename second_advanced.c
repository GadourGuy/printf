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
