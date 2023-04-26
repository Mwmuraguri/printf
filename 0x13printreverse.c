#include "main.h"

/**
 * reverse_string - function which prints string in
 *                 reverse
 * @flag: shows the flags controlling the formatted output
 * @buffer: used to store the output
 * @size: the size of buffer
 * @precision: shows the decimal precision
 * @variety: the variable argument list
 * @width: the minimum characters to be printed
 *
 * Return: the number of characters printed
 */

int reverse_string(va_list variety, char buffer[], int flag,
		int width, int precision, int size)
{
	int p = 0;
	int total = 0;
	char *string;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(size);
	UNUSED(width);

	string = va_arg(variety, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null\0(";
	}
	for (p = 0 ; string[p] ; p++)
		;

	for (p = p - 1 ; p >= 0 ; p--)
	{
		char n = string[p];

		write(1, &n, 1);
		total++;
	}
	return (total);
}
