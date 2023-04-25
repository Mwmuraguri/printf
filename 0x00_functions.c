#include "main.h"

/**
 * _printchar - function prints charactes to output buffer
 *
 * @buffer: this shows arrays characters printed
 * @flag: controls formating of output showing flags present
 * @width: minimum number of characters when printing
 * @precision: decimal points in float daata type
 * @size: the size of buffer
 * @variety: the variable argument list
 *
 * Return: the characters printed
 */


int _printchar(va_list variety, char buffer[], int flag,
		int width, int precision, int size)
{
	char n = va_arg(variety, int);/*char seen as int*/

	return (_handlechar(n, buffer, flag, width, precision, size));
}


/**
 * _printstring - function prints string to buffer
 *
 * @buffer: where the output will be stored
 * @flag: shows flags controlling format of output
 * @width: minimum characters to use
 * @precision: max characters printing from string
 * @size: the size of buffer
 * @variety: the variable argument list
 *
 * Return: the characters printed
 */

int _printstring(va_list variety, char buffer[], int flag,
		int width, int precision, int size)
{
	char *string = va_arg(variety, char *);
	int length = 0;
	int p;

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flag);
	UNUSED(width);

	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
		{
			string = "      ";

		}
	}
	while (string[length] != '\0')
	{
		length++;
	}
	if (precision < length && precision >= 0)
		length = precision;
	if (width > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &string[0], length);
			for (p = width - length; p > 0; p--)
				write(1, " ", 1);
			return (width);
		}
			for (p = width - length ; p > 0 ; p--)
				write(1, " ", 1);
			write(1, &string[0], length);
			return (width);
	}
	return (write(1, string, length));
}

/**
 * _printpercent - function that prints a percent sign
 *
 * @buffer: stores the output
 * @flag: shows flags controlling formatting output
 * @width: the minimum characters to be printed
 * @precision: the specified precision
 * @size: the size of buffer
 * @variety: the variable argument list
 *
 * Return: the characters printed
 */

int _printpercent(va_list variety, char buffer[], int flag,
		int width, int precision, int size)
{
	UNUSED(variety);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(width);
	return (write(1, "%%", 1));
}

/**
 * _putchar -  function that prints out a character to the stdout
 * @c: The character to be printed
 * Return: value of the character being printed
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
