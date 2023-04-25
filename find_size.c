#include "main.h"

/**
 * find_size - brings back size of a format specifier
 *
 * @format: format string to find size from
 * @p: points to the current character in format string
 *
 * Return: the size
 */

int find_size(const char *format, int *p)
{
	int size = 0;
	int now_ind = *p + 1;

	if (format[now_ind] ==  'l')
	{
		size = S_LONG;
	}
	else if (format[now_ind] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*p = now_ind - 1;
	}
	else
		*p = now_ind;
	return (size);

}
