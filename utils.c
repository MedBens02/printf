#include "main.h"

/**
 * _isdigit - checks ip_sct character is digit
 *
 * @i: the character to check
 *
 * Return: 1 ip_sct digit, 0 otherwise
 */
int _isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}

/**
 * _strlen - returns the length op_sct a string
 *
 * @str: the string whose length to check
 *
 * Return: integer length op_sct string
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; *str != '\0'; str++)
		++len;

	return (len);
}
