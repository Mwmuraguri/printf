#include "main.h"

/**
 * _handlechar - print a string
 * @n: char
 * @buffer: buffer array
 * @flag: active flags
 * @width: width
 * @precision: precision specifier
 * @size: size
 *
 * Return: char printed
 */
int _handlechar(char n, char buffer[], int flag, int width,
		int precision, int size)
{
	int x = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & F_ZERO)
		pad = '0';

	buffer[x++] = n;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[BUFF_SIZE - x - 2] = pad;

		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) +
			write(1, &buffer[BUFF_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
				write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
