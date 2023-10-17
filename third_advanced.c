#include "main.h"
/**
 * switch_flags - searches for flags
 * @ap: va list
 * @format: format
 * @i: counter
 * Return: count
 */
int switch_advanced_three(va_list ap, const char *format, int i, int *i_p)
{
	int d, count = 0, j;
	unsigned int u;
	char b, c;
	
	*i_p = 0;
	b = format[i];
	c = format[i + 1];
	for (j = i; b != '\0'; j++)
	{
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
			return (-1);
	}
	return (count);
}
