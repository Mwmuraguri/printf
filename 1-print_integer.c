#include "main.h"
#include <stdarg.h>

/**
 * _printint - function uses the va_list as argument to print
 *                 the next integer value
 * @variety: a va_list wirh various arguments to print as integer values
 * @buffer: this stores the integers
 * @size: shows the size of the buffer
 * @width: is minimum width of integer
 * @precision: maximum gigits that are to be printed
 * @flag: character showing how to format integer value
 *
 * Return: the total characters printed as output
 */

int _printint(va_list variety, char buffer[], int flag,
		int width, int precision, int size)
{
	long int p = (va_arg(variety, long int));
	unsigned long int value;
	int _neg = 0;
	int b = BUFF_SIZE - 2;

	p = change_sizenum(p, size);

	if (p == 0)
	{
		buffer[b--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';
	value = (unsigned long int)p;

	if (p < 0)
	{
		value = (unsigned long int)((-1) * p);
		_neg = 1;
	}

	while (value > 0)
	{
		buffer[b--] = (value % 10) + '0';
		value = value / 10;
	}
	b++;

	return (write_number(_neg, b, buffer, flag, width, precision, size));


}
