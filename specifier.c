#include "main.h"

/**
 * get_specifier - finds the format func
 *
 * @c: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *c))(va_list ap, p_sct * params)
{
	sp_sct specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*c == specifiers[i].specifier[0])
			return (specifiers[i].f);

		i++;
	}
	return (NULL);
}

/**
 * get_fct - finds the format func
 *
 * @c: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_fct(char *c, va_list ap, p_sct *params)
{
	int (*f)(va_list, p_sct *) = get_specifier(c);

	if (f)
		return (f(ap, params));

	return (0);
}

/**
 * get_flag - finds the flag func.
 *
 * @c: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *c, p_sct *params)
{
	int i = 0;

	switch (*c)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func.
 *
 * @c: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *c, p_sct *params)
{
	int i = 0;

	switch (*c)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 *
 * @c: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *c, p_sct *params, va_list ap)
{
	int d = 0;

	if (*c == '*')
	{
		d = va_arg(ap, int);
		c++;
	}
	else
	{
		while (_isdigit(*c))
			d = d * 10 + (*c++ - '0');
	}
	params->width = d;
	return (c);
}

