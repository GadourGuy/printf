#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int write_str(char *str);
int write_char(char c);
int _printf(const char *format, ...);
int _strlen(char *s);
int print_number(int n);
int print_binary(int n);
int switch_function(va_list, char c);
int advanced_function(va_list, char c);
int search_advanced(const char c, va_list ap);
int print_octal(int n);
int print_s_hexa(int n);
int print_c_hexa(int n);
int print_unsigned(unsigned int n);
/**
 * struct search - searches for certain values
 * @f: function pointer
 * @search: pointer
*/
typedef struct search
{
	char *search;
	int (*f)(void);
} search_t;

#endif
