#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int write_str(char *str, int count);
int write_char(char c);
int _printf(const char *format, ...);
int _strlen(char *s);
int print_number(int n, int count);
int print_binary(int n);
int switch_function(va_list, char c);
int advanced_function(va_list, char c);
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
