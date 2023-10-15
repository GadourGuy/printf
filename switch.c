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
			count += print_number(d);
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
			count += print_binary(d);
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
	unsigned int u;
	int d, count = 0;

	switch (c)
	{
		case ('u'):
		{
			u = va_arg(ap, unsigned int);
			count += print_unsigned(u);
			break;
		}
		case ('o'):
		{
			d = va_arg(ap, int);
			count += print_octal(d);
			break;
		}
		case ('x'):
		{
			d = va_arg(ap, int);
			count += print_s_hexa(d);
			break;
		}
		case ('X'):
		{
			d = va_arg(ap, int);
			count += print_c_hexa(d);
			break;
		}
	}
	return (count);
}
