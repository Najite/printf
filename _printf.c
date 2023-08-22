#include <stdio.h>
#include "main.h"

/**
 * _printf - Custom printf function with limited conversion specifiers
 * @format: The format string containing directives
 * @...: Additional arguments for the directives
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				const char *str = va_arg(args, const char *);
				while (*str)
				{
					putchar(*str);
					str++;
					count++;
				}
				break;
			case '%':
				putchar('%');
				count++;
				break;
			default:
				putchar('%');
				putchar(*format);
				count += 2;
				break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
