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
int print_binary(unsigned int n);
int switch_function(va_list, char c);
int advanced_function(va_list, char c);
int search_advanced(const char c, va_list ap);
int print_s_hexa(unsigned int n);
int print_octal(unsigned int n);
int print_c_hexa(unsigned int n);
int print_unsign(unsigned int n);
int print_S(char *c);
int search_advanced_2(const char c, va_list ap);
int print_address(void *addr);
int search_advanced_3(const char c, va_list ap);
int print_reversed(char *str);
int print_R(char *str);

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
