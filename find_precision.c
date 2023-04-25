#include "main.h"


/**
 * find_precision - brings back precision of a format string
 *
 * @format: the format string used
 * @p: points to the current index in format string
 * @allist: the va_list with arguments
 *
 * Return: the precision
 */

int find_precision(const char *format, int *p, va_list allist)
{
	int now_ind = *p + 1;
	int precision = -1;

	if (format[now_ind] != '.')
		return (precision);

	precision = 0;

	for (now_ind += 1; format[now_ind] != '\0'; now_ind++)
	{
		if (_isdigit(format[now_ind]))
		{
			precision = precision * 10;
			precision = precision + format[now_ind] - '0';
		}
		else if (format[now_ind] == '*')
		{
			now_ind++;
			precision = va_arg(allist, int);
			break;
		}
		else
			break;
	}

	*p = now_ind - 1;

	return (precision);
}

