#include "main.h"

/**
 * _printpointer - prints the value of a pointer
 * @flag: active flags
 * @buffer: buffer array
 * @precision: precision specifier
 * @size: size
 * @width: get width
 * @variety: arguments
 *
 * Return: char printed
 */
int _printpointer(va_list variety, char buffer[],
	int flag, int width, int precision, int size)
{
	char add_c = 0;
	char pad = ' ';
	int index = BUFF_SIZE - 2, length = 2, pad_start = 1;
	unsigned long number_add;
	char map_t[] = "0123456789abcdef";
	void *add = va_arg(variety, void *);

	UNUSED(width);
	UNUSED(size);

	if (add == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	number_add = (unsigned long)add;

	while (number_add > 0)
	{
		buffer[index--] = map_t[number_add % 16];
		number_add /= 16;
		length++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';
	if (flag & F_PLUS)
		add_c = '+', length++;
	else if (flag & F_SPACE)
		add_c = ' ', length++;

	index++;

	return (_writepointer(buffer, index, length,
		width, flag, pad, add_c, pad_start));
}
