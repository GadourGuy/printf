#include "main.h"
/**
 * switch_advanced_long - a function to print long int
 * @ap: valist
 * @format: format
 * @i: format counter
 * @i_p: pointer to i in previous loop.
 * Return: count
 */
int switch_advanced_long(va_list ap, const char *format, int i, int *i_p)
{
	long int d;
	int count = 0;
	unsigned long int u;
	char b, c;

	*i_p = 0;
	b = format[i];
	c = format[i + 1];
	if (((b == 'l') && (c == 'd')) || (c == 'i'))
	{
		d = va_arg(ap, long int);
		count += print_long(d);
		*i_p += 1;
	}
	else if ((b == 'l') && (c == 'u'))
	{
		u = va_arg(ap, long int);
		count += print_long_unsign(u);
		*i_p += 1;
	}
	else if ((b == 'l') && (c == 'o'))
	{
		u = va_arg(ap, long int);
		 count += print_un_octal(u);
		 *i_p += 1;
	}
	else
		return (-1); /*temperory*/
	return (count);
}
