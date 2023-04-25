#include "main.h"

/**
 * print_buffer - coverts unsigned number to binary
 * @flag: active flags
 * @buffer: buffer array
 * @width: width
 * @precision: precision specification
 * @variety: arguments
 * @size: size
 *
 * Return: no. of char printed
 */
int _printbinary(va_list variety, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, z, add;
	unsigned int b[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(variety, unsigned int);
	y = 2147483648;
	b[0] = x / y;
	for (z = 1; z < 32; z++)
	{
		y /= 2;
		b[z] = (x / y) % 2;
	}
	for (z = 0, add = 0, count = 0; z < 32; z++)
	{
		add = add + b[z];
		if (add || z == 31)
		{
			char p = '0' + b[z];

			write(1, &p, 1);
			count++;
		}
	}
	return (count);
}
