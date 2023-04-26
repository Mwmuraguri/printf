#include "main.h"

/**
 * _formatoutput - print argument
 * @stf: formatted string
 * @p: char
 * @buffer: buffer array
 * @allist: char
 * @width: width
 * @precision: precision specifier
 * @flag: active flags
 * @size: size
 *
 * Return: printed char
 */
int _formatoutput(const char *stf, int *p, va_list allist,
	char buffer[], int flag, int width, int precision, int size)
{
	int x;
	int unknown_length = 0;
	int print_char = -1;

	stf_t stf_tlist[] = {
		{'c', _printchar},
		{'s', _printstring},
		{'%', _printpercent},
		{'i', _printint},
		{'d', _printint},
		{'b', _printbinary},
		{'u', _unsigned},
		{'o', _printoctal},
		{'x', _hexadecimal},
		{'X', _hexadecimal_upper}, {'\0', NULL}
	};
	for (x = 0; stf_tlist[x].stf != '\0'; x++)
		if (stf[*p] == stf_tlist[x].stf)
			return (stf_tlist[x].fn(allist, buffer, flag, width, precision, size));
	if (stf_tlist[x].stf == '\0')
	{
		if (stf[*p] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (stf[*p - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*p);
			while (stf[*p] != ' ' && stf[*p] != '%')
				--(*p);
			if (stf[*p] == ' ')
				--(*p);
			return (1);
		}
		unknown_length += write(1, &stf[*p], 1);
		return (unknown_length);
	}
	return (print_char);
}
