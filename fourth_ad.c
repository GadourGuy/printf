#include "main.h"
/**
 *
 *
 */
int switch_advanced_long(va_list ap, const char *format, int i, int *i_p)
{
	long int d;
	int count = 0;
	long unsigned int u;
	char b, c;

	*i_p = 0;
	b = format[i];
	c = format[i + 1];
	if ((b == 'l') && (c == 'd'))
	{
		d = va_arg(ap, long int);
		count += print_long(d);
		*i_p += 1;
	}
	else if ((b == 'l') && (c == 'i'))
	{
		u = va_arg(ap, long int);
		count += print_long_unsign(u);
		*i_p += 1;
	}
	else
		return (-1); /*temperory*/
	return (count);
}
