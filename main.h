#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


#define PRINT -1

#define LOWC 1
#define UNSIGNED 2

/**
 * struct parameters - parameters
 *
 * @unsign: flag if unsigned value
 * @plus_flag: if plus
 * @space_flag: if space
 * @hashtag_flag: if #
 * @zero_flag: if 0
 * @minus_flag: if minus
 * @width: if width specified
 * @precision: if precision spec
 * @h_modifier: if h
 * @l_modifier: if l
 */
typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} p_sct;

/**
 * struct specifier - struct
 *
 * @specifier: format token
 * @f: fct associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, p_sct *);
} sp_sct;

int _printf(const char *format, ...);

int _puts(char *str);
int _putchar(int c);

int print_char(va_list ap, p_sct *params);
int print_int(va_list ap, p_sct *params);
int print_string(va_list ap, p_sct *params);
int print_percent(va_list ap, p_sct *params);
int print_S(va_list ap, p_sct *params);

char *convert(long int num, int base, int flags, p_sct *params);

int (*get_specifier(char *c))(va_list ap, p_sct *params);
int get_fct(char *c, va_list ap, p_sct *params);
int get_flag(char *c, p_sct *params);
int get_modifier(char *c, p_sct *params);
char *get_width(char *c, p_sct *params, va_list ap);

int print_number(char *str, p_sct *params);
int print_justify_right(char *str, p_sct *params);
int print_justify_left(char *str, p_sct *params);

int print_unsigned(va_list ap, p_sct *params);
int print_address(va_list ap, p_sct *params);
int print_hex(va_list ap, p_sct *params);
int print_HEX(va_list ap, p_sct *params);
int print_binary(va_list ap, p_sct *params);
int print_octal(va_list ap, p_sct *params);

int print_from_to(char *start, char *stop, char *execute);
int print_rev(va_list ap, p_sct *params);
int print_rot13(va_list ap, p_sct *params);

int _isdigit(int i);
int _strlen(char *str);

void init_params(p_sct *params, va_list ap);

char *get_precision(char *p, p_sct *params, va_list ap);

#endif /* _PRINTF_H */
