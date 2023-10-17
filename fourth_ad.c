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
	else if ((b == 'l') && (c == 'X'))
	{
		u = va_arg(ap, long int);
		count += print_unc_hexa(u);
		*i_p += 1;
	}
	else
	{
		count +=  switch_long_cont(ap, format, i, i_p);
	}
	return (count);
}

/**
 * switch_long_cont - continue the previous function
 * @ap: valist
 * @format: foramat
 * @i: format counter
 * @i_p: pointer to i in previous loop.
 * Return: count
 */
int switch_long_cont(va_list ap, const char *format, int i, int *i_p)
{
	int count = 0;
	unsigned long int u;
	int d;
	char b, c;

	b = format[i];
	c = format[i + 1];
	if ((b == 'l') && (c == 'x'))
	{
		u = va_arg(ap, long int);
		count += print_unc_hexa(u);
		*i_p += 1;
	}
	else if ((b == 'h') || (c == 'x'))
	{
		d = va_arg(ap, int);
		count += print_s_hexa(d);
		*i_p += 1;
	}
	else if ((b == 'h') || (c == 'X'))
	{
		d = va_arg(ap, int);
		count += print_c_hexa(d);
		*i_p += 1;
	}
	else if ((b == 'h') || (c == 'o'))
	{
		d = va_arg(ap, int);
		count += print_octal(d);
		*i_p += 1;
	}
	else
	{
		return (-1);
	}
	return (count);
}
