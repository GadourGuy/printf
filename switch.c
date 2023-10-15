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
			write_char(c);
			count++;
			break;
		}
		case ('s'):
		{
			str = va_arg(ap, char *);
			count += write_str(str);
			break;
		}
		case ('d'):
		case ('i'):
		{
			d = va_arg(ap, int);
			count += print_number(d, count);
			break;
		}
		case ('%'):
		{
			write_char('%');
			count++;
			break;
		}
		case ('b'):
		{
			d = va_arg(ap, int);
			print_binary(d);
			break;
		}
	}
	return (count);
}

/**
 * search_advanced - searches for advanced tasks
 * @c: char to be searched
 * @count: number of given data
 *
 * Return: number of count.
 */
int search_advanced(__attribute__((unused)) const char c, __attribute__((unused)) va_list ap)
{
	return (0);
}
