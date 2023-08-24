#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
int _printf(const char *format, ...);
int print_int(int n);
int print_hex(unsigned int n, int uppercase);
int print_octal(unsigned int n);
int print_unsigned_int(unsigned int n);
int _putchar(char c);

