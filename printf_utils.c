#include "main.h"

/**
 * canbe_printed - finds out if character can be printed
 *
 * @n: the character to be checked
 *
 * Return: 1 if it can be printed, otherwise 0
 */

int canbe_printed(char n)
{
	if (n >= 32 && n < 127)/*127 is delete control*/
	{
		return (1);
	}
	else
		return (0);
}

/**
 * hexa_encode - ascci code appended in hexadecimal format
 *
 * @i: where appending should start
 * @buffer: stores the output
 * @ascii: the ascii code
 *
 * Return: 3
 */

int hexa_encode(char ascii, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii = ascii * -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii / 16];
	buffer[i] = map[ascii % 16];

	return (3);

}

/**
 * _isdigit - evaluates if character is a digit
 *
 * @d: the character to be checked
 * Return: 1 if digit and 0 otherwise
 */

int _isdigit(char d)
{

	if (d >= '0' && d <= '9')
	{
		return (1);
	}
	else
		return (0);
}

/**
 * change_sizeunsgned - changes number to a size
 *
 * @number: number being change
 * @size: number showing the change
 *
 * Return: changed value
 */
long int change_sizeunsgned(unsigned long int number, int size)
{
	if (size == S_SHORT)
	{
		return ((unsigned short)number);
	}
	else if (size == S_LONG)
		return (number);
	return ((unsigned int)number);
}

/**
 * change_sizenum - function  changes a number to specified size
 *
 * @number: the number to be changed
 * @size: the specified size
 *
 * Return: changed value
 */

long int change_sizenum(long int number, int size)
{
	if (size == S_LONG)
	{
		return (number);
	}
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}


