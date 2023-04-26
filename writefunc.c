#include "main.h"

/**
 * unsigned_write - Entry point
 * @negative: no. is negative
 * @index: where the no. starts
 * @buffer: stores character
 * @flag: specifies the flag
 * @width: specifies width
 * @size: size specifier
 * @precision: specifies precision
 *
 * Return: printed char
 */
int unsigned_write(int negative, int index, char buffer[], int flag,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1, x = 0;
	char pad = ' ';

	UNUSED(negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		pad = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';

	if (width > length)
	{
		for (x = 0; x < width - length; x++)
			buffer[x] = pad;

		buffer[x] = '\0';

		if (flag & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[index], length));
		}
	}
	return (write(1, &buffer[index], length));
}
/**
 * _writepointer - Entry point
 * @buffer: stores the char
 * @index: where no starts
 * @length: length of no
 * @width: specifier width
 * @pad: char dor pad
 * @flag: active flag
 * @add_c: added char
 * @start_pad: index where padding starts
 *
 * Return: printed chars
 */
int _writepointer(char buffer[], int index, int width, int length,
		int flag, char pad, char add_c, int start_pad)
{
	int p;

	if (width > length)
	{
		for (p = 3; p < width - length + 3; p++)
			buffer[p] = pad;
		buffer[p] = '\0';
		if (flag & F_MINUS && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (add_c)
				buffer[--index] = add_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], p - 3));
		}
		else if (!(flag & F_MINUS) && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (add_c)
				buffer[--index] = add_c;
			return (write(1, &buffer[3], p - 3) + write(1, &buffer[index], length));
		}
		else if (!(flag & F_MINUS) && pad == '0')
		{
			if (add_c)
				buffer[--start_pad] = add_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[start_pad], p - start_pad) +
				write(1, &buffer[index], length - (1 - start_pad) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (add_c)
		buffer[--index] = add_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
