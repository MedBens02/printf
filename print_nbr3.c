#include "main.h"

/**
 * print_binary - prints unsigned binry number
 *
 * @ap: argument pointer
 * @params: params struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, p_sct *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - prints unsigned octal number
 *
 * @ap: argument pointer
 * @params: params struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, p_sct *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 8, UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c + print_number(str, params));
}
