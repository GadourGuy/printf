#include "main.h"
/**
 * switch_flags - searches for flags
 * @ap: va list
 * @format: format
 * @i: counter
 * Return: count
 */
int switch_advanced_three(va_list ap, const char *format, int i)
{
	int d, count = 0, j;
	unsigned int u;
	char b, c;

	b = format[i];
	c = format[i + 1];
	for (j = i; b != '\0'; j++)
	{
		if ((b == '+') && ((c == 'd') || (c == 'i')))
		{
			d = va_arg(ap, int);
			if (d >= 0)
			{
				write_char('+');
				count += 1;
			}
			count += print_number(d);
			break;
		}
		else if ((b == ' ') && ((c == 'd') || (c == 'i')))
		{
			d = va_arg(ap, int);
			if (d >= 0)
			{
				 write_char(' ');
				 count += 1;
			}
			count += print_number(d);
			break;
		}
		else if ((b == '#') && ((c == 'X') || (c == 'x')))
		{
			u = va_arg(ap, int);
			write_char('0');
			write_char('x');
			count += 2;
			if (c == 'x')
				count += print_s_hexa(u);
			if (c == 'X')
				count += print_c_hexa(u);
			break;
		}
		else if ((b == '#') && (c == 'o'))	
		{
			u = va_arg(ap, int);
			write_char('0');
			count += print_octal(u) + 1;
			break;
		}
		}
	return (count);
}
