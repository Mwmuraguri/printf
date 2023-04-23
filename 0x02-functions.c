#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_binary - prints the binary
 * @n: unsigned int
 * Return: no of char
 *
 */
int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_binary(n >> 1);
	count += _putchar((n & 1) + '0');
	return (count);
}
/**
 * handle_binary - handle custom conversion specifiers
 * @args: va_list containing the unsigned int
 *
 * Return: no. of digits printed
 */
int handle_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_binary(n));
}
