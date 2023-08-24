#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				c = va_arg(args, int);
				count += _putchar(c);
				break;
			case 's':
			{
				char *str = va_arg(args, char *);

				while (*str)
				{
					count += _putchar(*str);
					str++;
				}
			}
			break;
			case '%':
				count += _putchar('%');
				break;
			default:
				break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
