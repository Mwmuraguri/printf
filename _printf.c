#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 * @format: char string format
 * @...: variable number of arguments
 * Return: the number of characters printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
		switch (*format)
		{
			case 'c':
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				count += printf("%s", va_arg(args, char *));
				break;
			case '%':
				putchar('%');
				count++;
				break;
			default:
				break;
		}
	}
	else
	{
		putchar(*format);
			count++;
	}
	format++;
	}
	va_end(args);
	return (count);
}
