#include "main.h"


/**
 * find_flag - function that extracts flags
 *
 * @format: formatted string
 * @p: parameter to the function
 *
 * Return: a flag
 */

int find_flag(const char *format, int *p)
{
	int flag = 0;
	int q;
	int now_ind;
	const char FLAGC[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGB[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (now_ind = *p + 1 ; format[now_ind] != '\0' ; now_ind++)
	{
		for (q = 0 ; FLAGC[q] != '\0' ; q++)
			if (format[now_ind] == FLAGC[q])
			{
				flag = flag | FLAGB[q];
				break;
			}
		if (FLAGC[q] == 0)
		{
			break;
		}

	}
	*p = now_ind - 1;
	return (flag);
}
