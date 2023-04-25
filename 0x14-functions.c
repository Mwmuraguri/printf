#include "main.h"

/**
 * print_rot13 - prints rot 13 string
 * @buffer: buffer array
 * @flag: active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * @variety: var
 *
 *
 * Return: chars printed
 */
int string_rot13(va_list variety, char buffer[], int flag,
	int width, int precision, int size)
{
	char s;
	char *string;
	unsigned int x, y;
	int count = 0;
	char alin[]  = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char alout[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(variety, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (x = 0; string[x]; x++)
	{
		for (y = 0; alin[y]; y++)
		{
			if (alin[y] == string[x])
			{
				s = alout[y];
				write(1, &s, 1);
				count++;
				break;
			}
		}
		if (!alin[y])
		{
			s = string[x];
			write(1, &s, 1);
			count++;
		}
	}
	return (count);
}
