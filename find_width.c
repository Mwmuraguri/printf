#include "main.h"

/**
 * find_width - brings back the width from format string
 *
 * @format: the format string to be used
 * @p: points to current position in format string
 * @allist: va_list with the arguments
 *
 * Return: width specifier value
 */

int find_width(const char *format, int *p, va_list allist)
{
	int width = 0;
	int now_ind;

	for (now_ind = *p + 1; format[now_ind] != '\0'; now_ind)
	{
		if (_isdigit(format[now_ind]))
		{
			width = width * 10;
			width += format[now_ind] - '0';
		}
		else if (format[now_ind] == '*')
		{
			now_ind++;
			width = va_arg(allist, int);
			break;
		}
		else
			break;
	}

	*p = now_ind - 1;

	return (width);
}
