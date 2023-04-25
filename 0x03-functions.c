#include "main.h"

/**
 * _unsigned - Entry point
 * @buffer: buffer array
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * @flag: active flags
 * @variety: variety
 *
 * Return: no of chars printed
 */
int _unsigned(va_list variety, char buffer[], int flag,
		int width, int precision, int size)
{
	unsigned long int number = va_arg(variety, unsigned long int);
	int j = BUFF_SIZE - 2;

	number = change_sizeunsgned(number, size);

	if (number == 0)
		buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[j--] = (number % 10) + '0';
		number /= 10;
	}

	j++;
	return (unsigned_write(0, j, buffer, flag,
				width, precision, size));
}
/**
 * _print_octal - prints unsigned number in ocatal
 * @size: size specifier
 * @buffer: buffer array
 * @variety: arguments
 * @precision: precision
 * @flag: active flags
 * @width: width
 *
 * Return: no of chars
 */
int _printoctal(va_list variety, char buffer[], int flag,
		int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int number = va_arg(variety, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = change_sizeunsgned(number, size);

	if (number == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[z--] = (number % 8) + '0';
		number /= 8;
	}

	if (flag & F_HASH && init_number != 0)
		buffer[z--] = '0';

	z++;
	return (unsigned_write(0, z, buffer, flag,
				width, precision, size));
}
/**
 * _hexadecimal - prints number in hexadecimal
 * @width: width
 * @variety: arguments
 * @flag: actve flags
 * @precision: precision specifier
 * @size: size specifier
 * @buffer: buffer size
 *
 * Return: no of chars printed
 */
int _hexadecimal(va_list variety, char buffer[], int flag,
		int width, int precision, int size)
{
	return (_printhexa(variety, "0123456789abcdef", buffer,
		flag, 'x', width, precision, size));
}
/**
 * _hexadecimal_upper - prints nummber in upper hexadecimal
 * @width: width
 * @variety: arguments
 * @flag: actve flags
 * @precision: precision specifier
 * @size: size specifier
 * @buffer: buffer array
 *
 * Return: no of char printed
 */
int _hexadecimal_upper(va_list variety, char buffer[],
		int flag, int width, int precision, int size)
{
	return (_printhexa(variety, "0123456789ABCDEF", buffer,
		flag, 'X', width, precision, size));
}
/**
 * _print_hexa - prints no. in lower or upper hex
 * @size: size specifier
 * @buffer: buffer array
 * @variety: active
 * @precision: precision
 * @flag: active flags
 * @width: width
 * @map_to: array
 * @flag_ch: active flags
 *
 * Return: no of chars
 */
int _printhexa(va_list variety, char map_to[], char buffer[],
	int flag, char flag_ch,
	int width, int precision, int size)
{
	int s = BUFF_SIZE - 2;
	unsigned long int number = va_arg(variety, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = change_sizeunsgned(number, size);

	if (number == 0)
		buffer[s--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[s--] = map_to[number % 16];
		number /= 16;
	}

	if (flag & F_HASH && init_number != 0)
	{
		buffer[s--] = flag_ch;
		buffer[s--] = '0';
	}
	s++;
	return (unsigned_write(0, s, buffer, flag,
				width, precision, size));
}
