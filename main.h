#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define S_SHORT 1
#define S_LONG 2


#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

#define F_MINUS 1
#define F_SPACE 2
#define F_ZERO 4
#define F_HASH 8
#define F_PLUS 16

/**
 * struct print_format - data structure to be used
 *
 * @format: the character format specifier
 * @func: function pointer to handle formatted values
 */

struct print_format
{
	char *format;
	int (*func)(va_list);
}
;


typedef print_format print_ft;

int _printf(const char *format, ...);
int _formatoutput(const char *format, int *p, va_list allist,
		char buffer[], int flag, int width, int precision,
		int size);



/*functions printing chars, strings and percent according to format */
int _printstring(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
int _printchar(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
int _printpercent(va_list variety, char buffer[], int flag,
		int width, int precision, int size);

/*function printing integers*/
int _printint(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
int _printoctal(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
int _hexadecimal(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
int _hexadecimal_upper(va_list variety, char buffer[],
		int flag, int width, int precision, int size);
int _unsigned(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
int _printbinary(va_list variety, char buffer[], int flag,
		int width, int precision, int size);

int _printhexa(va_list variety, char map_to[], char buffer[],
		int flag, char fmt_flag, int flag, int width,
		int precision, int size);

/*function printing a string in reverse*/
int reverse_string(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
/*function printing string in rot 13*/
int string_rot13(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
/*function printing the address using pointer*/
int _printpointer(va_list variety, char buffer[], int flag,
		int width, int precision, int size);
/*function printing non printable characters*/
int _non_printable(va_list variety, char buffer[], int flag,
		int width, int precision, int size);

/*formatted output*/
int _handlechar(char n, char buffer[], int flag, int width,
		int precision, int size);
int _writepointer(char buffer[], int index, int width, int length,
		int flag, char pad, char add_c, start_pad);
int _writenum(int index, char buffer[], int flag, int width,
		int precision, int length, char pad, char add_c);
int write_number(int positive, int index, char buffer[], int flag,
		int width, int precision, int size);
int unsigned_write(int negative, int index, char buffer[], int flag,
		int width, int precision, int size);
/*extract formatting info from formatted strings*/
int find_flag(const char *format, int *p);
int find_precision(const char *format, int *p, va_list allist);
int find_width(const char *format, int *p, va_list allist);
int find_size(const char *format, int *p);

/*aiding functions*/
int canbe_printed(char);
int _isdigit(char);
int hexa_encode(char, char[], int);

long int change_sizenum(long int number, int size);
long int chsnge_sizeunsgned(unsigned long int number, int size);

#endif

