#include "main.h"

/**
 * print_number - prints a number with options
 *
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, p_sct *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_justify_right(str, params));
	else
		return (print_justify_left(str, params));
}

/**
 * print_justify_right - prints a number with options
 *
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_justify_right(char *str, p_sct *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';

	neg = neg2 = (!params->unsign && *str == '-');

	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2)
			|| (!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar ('+');
	else if (!params->plus_flag && params->space_flag
			&& !neg2 && !params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar (pad_char);
	if (neg && pad_char == ' ')
		n += _putchar ('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar ('+');
	else if (!params->plus_flag && params->space_flag
			&& !neg2 && !params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_justify_left - prints a number with options
 *
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_justify_left(char *str, p_sct *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';

	neg = neg2 = (!params->unsign && *str == '-');

	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar ('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
