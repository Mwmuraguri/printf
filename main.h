#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _printschar(va_list variety);
int _reverse(va_list variety);
int string_rot13(va_list variety);
int _charpointer(va_list variety);
int _printstring(va_list variety);
int _charpointer(va_list variety);
int convert_binary(va_list variety);
int _hexadecimal(va_list variety);
int _printinteger(va_list variety);
int _printoctal(va_list variety);
int _hexupper(va_list variety);
int _printunsigned(va_list variety);


#endif
