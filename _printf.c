#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - Entry point
 * @format: format output
 *
 * Return: characters printed
 *
 */
int _printf(const char *format, ...)
{
	int x, print_ch = 0;
	int printed_char = 0;
	int flag, width, precision, size, buff_index = 0;
	va_list alist;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(alist, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_index++] = format[x];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			printed_char++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flag = find_flag(format, &x);
			width = find_width(format, &x, alist);
			precision = find_precision(format, &x, alist);
			size = find_size(format, &x);
			++x;
			print_ch = _formatoutput(format, &x, alist, buffer,
					flag, width, precision, size);
			if (print_ch == -1)
				return (-1);
			printed_char += print_ch;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(alist);
	return (printed_char);
}
/**
 * print_buffer - prints contents of buffer
 * @buff_index: index
 * @buffer: arr of chars
 *
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)

		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}
