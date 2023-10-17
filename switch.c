#include "main.h"
/**
 * switch_function - switch in printf function
 * @format: input
 * @ap: va_list
 * Return: count
 */
int switch_function(va_list ap, const char format)
{
	int count = 0, d;
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
			if (str)
			{
				count += write_str(str);
			}
			else
				free(str);
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
		default:
			count += search_advanced(format, ap);
	}
	return (count);
}
/**
 * search_advanced - searches for advanced tasks
 * @c: char to be searched
 * @ap: number of given data
 * Return: number of count.
 */
int search_advanced(const char c, va_list ap)
{
	unsigned int u;
	int count = 0;

	switch (c)
	{
		case ('u'):
		{
			u = va_arg(ap, unsigned int);
			count += print_unsign(u);
			break;
		}
		case ('o'):
		{
			u = va_arg(ap, unsigned int);
			if (u != 0)
				count += print_octal(u);
			else
			{
				write_char('0');
				count++;
			}
			break;
		}
		case ('x'):
		{
			u = va_arg(ap, unsigned int);
			if (u != 0)
				count += print_s_hexa(u);
			else
			{
				write_char('0');
				count++;
			}
			break;
		}
		default:
			count += search_advanced_2(c, ap);
	}
	return (count);
}

/**
 * search_advanced_2 - searches for advanced tasks
 * @c: char to be searched
 * @ap: number of given data
 * Return: number of count.
 */
int search_advanced_2(const char c, va_list ap)
{
	char *ch;
	int count = 0;
	unsigned int u;

	switch (c)
	{
		case ('S'):
		{
			ch = va_arg(ap, char *);
			if (ch)
				count += print_S(ch);
			break;
		}
		case ('b'):
		{
			u = va_arg(ap, unsigned int);
			if (u != 0)
				count += print_binary(u);
			else
			{
				write_char('0');
				count++;
			}
			break;
		}
		case ('X'):
		{
			u = va_arg(ap, unsigned int);
			if (u != 0)
				count += print_c_hexa(u);
			else
			{
				write_char('0');
				count++;
			}
			break;
		}
		default:
			count += search_advanced_3(c, ap);
	}
	return (count);       }

/**
 * search_advanced_3 - searches for more cases
 * @c: char to be searched
 * @ap: number of given data
 * Return: number of count.
 */
int search_advanced_3(const char c, va_list ap)
{
	void *pointer;
	int counter = 0;
	char *str;

	switch (c)
	{
		case ('p'):
			{
				pointer = va_arg(ap, void *);
				if (pointer)
				{
					if (pointer)
						counter += print_address(pointer);
					else
						counter += write_str("(nil)");
				}
				break;
			}
		case ('r'):
			{
				str = va_arg(ap, char *);
				if (str)
					counter += print_reversed(str);
				break;

			}
		case ('R'):
			{
				str = va_arg(ap, char *);
				if (str)
					counter += print_R(str);
				break;
			}

	}
	return (counter);
}
