#include "main.h"
/**
 * switch_advanced_three - searches for flags
 * @ap: va list
 * @format: format
 * @i: counter
 * @i_p: pointer to i_p
 * Return: count
 */
int switch_advanced_three(va_list ap, const char *format, int i, int *i_p)
{
	int d, count = 0;
	char b, c;
	unsigned int u;

	*i_p = 0;
	b = format[i];
	c = format[i + 1];
	if (((b == '+') || (b == ' ')) && ((c == 'd') || (c == 'i')))
	{
		d = va_arg(ap, int);
		if (d >= 0)
		{
			if (b == '+')
				write_char('+');
			if (b == ' ')
				write_char(' ');
			count++;
			*i_p += 1;
		}
			count += print_number(d);
		}
		if (((b == '+') || (b == ' ')) && (c == 'u'))
		{
			u = va_arg(ap, int);
			if (b == '+')
				write_char('+');
			if (b == ' ')
				write_char(' ');
			count++;
			*i_p += 1;
			count += print_unsign(u);
		}
		else
		{
			count += switch_ad_cont(ap, format, i, i_p);
		}
	return (count);
}
/**
 * switch_ad_cont - continue the previous function
 * @ap: va list
 * @format: format
 * @i: counter
 * @i_p: pointer
 * Return: count
 */
int switch_ad_cont(va_list ap, const char *format, int i, int *i_p)
{
	int count = 0, j;
	unsigned int u;
	char b, c;

	*i_p = 0;
	b = format[i];
	c = format[i + 1];
	for (j = i; b != '\0'; j++)
	{
		if ((b == '#') && ((c == 'X') || (c == 'x')))
		{
			for (j = i; b != '\0'; j++)
			u = va_arg(ap, int);
			write_char('0');
			write_char('x');
			count += 2;
			if (c == 'x')
				count += print_s_hexa(u);
			if (c == 'X')
				count += print_c_hexa(u);
			*i_p += 1;
			break;
		}
		else if ((b == '#') && (c == 'o'))
		{
			u = va_arg(ap, int);
			write_char('0');
			count += print_octal(u) + 1;
			*i_p += 1;
			break;
		}
		else
		{
			count += switch_advanced_long(ap, format, i, i_p);
			break;
		}
	}
	return (count);
}
