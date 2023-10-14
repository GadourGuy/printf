#include "main.h"

/**
 * _printf - a function that gives a formatted output.
 * @format: format
 *
 * Return: Number of characters that are printed.
*/

int _printf(const char *format, ...)
{
	int i = 0, count = 0, check;
	va_list ap;

	va_start(ap, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			check = search(ap, format[i], count);
			if (!check)
			{
				search_advanced(format[i], count);
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

/**
 * search - searches for mandotary tasks
 * @c: char to be searched
 * @count: number of given data
 * @ap: va_list
 *
 * Return: number of count
 */

int search(va_list ap, const char c, int count)
{
	char *str, ch;
	int d;

	switch (c)
	{
	case ('c'):
	{
		ch =  va_arg(ap, int);
		write_char(ch);
		count++;
		break;
	}
	case ('s'):
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			return(-1);
		exit;
		count += write_str(str, count);
		break;
	}
	case 'd':
	case 'i':
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
	default:
		search_advanced(c, count);
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
int search_advanced(__attribute__((unused)) const char c, int count)
{
	count += 0;
	return (0);
}
