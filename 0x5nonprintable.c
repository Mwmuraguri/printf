#include "main.h"

/**
 * _non_printable - function that prints non printable
 * characters in ascii codes in hexa
 *
 * @flag: flag controlling formatted output
 * @width: minimum characters to be printed
 * @precision: specifies decimal precision
 * @buffer: stores output data
 * @variety: variable list of arguments
 * @size: the size of the buffer
 *
 * Return: the characters printed
 */

int _non_printable(va_list variety, char buffer[],
		int flag, int width, int precision, int size)
{
	int added_ch = 0;
	int p = 0;
	char *string = va_arg(variety, char *);

	UNUSED(flag);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(width);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[p] != '\0')
	{
		if (canbe_printed(string[p]))
			buffer[p + added_ch] = string[p];
		else
			added_ch = added_ch + hexa_encode(string[p], buffer, p + added_ch);

		p++;
	}

	buffer[p + added_ch] = '\0';

	return (write(1, buffer, p + added_ch));
}

