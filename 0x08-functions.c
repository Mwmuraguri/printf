#include "main.h"

/**
 * write_number - prints string
 * @is_negative: - arguments
 * @index: index
 * @buffer: buffer array
 * @flag: active flag
 * @width: width
 * @precision: specifier
 * @size: size specifier
 *
 * Return: char printed
 */
int write_number(int is_negative, int index,
		char buffer[], int flag,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flag & F_PLUS)
		extra_ch = '+';
	else if (flag & F_SPACE)
		extra_ch = ' ';

	return (_writenum(index, buffer, flag, width, precision,
		length, pad, extra_ch));
}
/**
 * _write_num - writes no. using buffer
 * @index: index
 * @buffer: buffer array
 * @flag: active flags
 * @length: size
 * @precision: precision
 * @pad: pading char
 * @add_c: extra char
 * @width: width
 *
 * Return: printed char
 */
int _writenum(int index, char buffer[], int flag, int width,
		int precision, int length, char pad, char add_c)
{
	int x;
	int pad_start = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 &&
		buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = pad = ' '; /* padding on width ' ' */
	if (precision > 0 && precision < length)
		pad = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (add_c != 0)
		length++;
	if (width > length)
	{
		for (x = 1; x < width - length + 1; x++)
			buffer[x] = pad;
		buffer[x] = '\0';
		if (flag & F_MINUS && pad == ' ')
			if (add_c)
				buffer[--index] = add_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], x - 1));
		else if (!(flag & F_MINUS) && pad == ' ')
		{
			if (add_c)
				buffer[--index] = add_c;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[index], length));
		}
		else if (!(flag & F_MINUS) && pad == '0')
		{
			if (add_c)
				buffer[--pad_start] = add_c;
			return (write(1, &buffer[pad_start], x - pad_start) +
				write(1, &buffer[index], length - (1 - pad_start)));
		}
	}
	if (add_c)
	buffer[--index] = add_c;
	return (write(1, &buffer[index], length));
}
