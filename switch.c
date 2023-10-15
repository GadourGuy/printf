#include "main.h"
/**
 * switch_function - switch in printf function
 * @format: input
 * @ap: va_list
 * Return: count
 */
int switch_function(va_list ap, const char format)
{
	int count = 0;
	int d;
	char c, *str;

	switch (format)
	{
		case ('c'):
		{
			c = va_arg(ap, int);
			if (c)
			{
				write_char(c);
				count++;
			}
			break;
		}
		case ('s'):
		{
			str = va_arg(ap, char *);
			if (str)
				count += write_str(str);
			break;
		}
		case ('d'):
		case ('i'):
		{
			d = va_arg(ap, int);
			if (d)
				count += print_number(d);
			break;
		}
		case ('%'):
		{
			write_char('%');
			count++;
			break;
		}
	}
	return (count);
}

/**
 * search_advanced - searches for advanced tasks
 * @c: char to be searched
 * @ap: number of given data
 *
 * Return: number of count.
 */
int search_advanced(const char c, __attribute__((unused)) va_list ap)
{
	switch (c);

	return (0);
}
