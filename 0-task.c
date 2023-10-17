#include "main.h"

/**
 * _printf - a function that gives a formatted output.
 * @format: format
 *
 * Return: Number of characters that are printed.
*/

int _printf(const char *format, ...)
{
	int i = 0, count = 0, check, ii;
	va_list ap;
	int *i_p = &ii;

	va_start(ap, format);
	if (format && format[i])
	{
		while (format && format[i])
		{
			if (format[i] == '%')
			{
				i++;
				check = switch_function(ap, format[i]);
				count += check;
				if (!check)
				{
					check = switch_advanced_three(ap, format, i, i_p);
					count += check;
					if (check)
						i += *i_p;
				}
			}
			else
				{
					write_char(format[i]);
					count++;
				}
				i++;
		}
	va_end(ap);
	return (count);
	}
	return (-1);
}
