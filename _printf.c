#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *str;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				_putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				str = va_arg(args, char *);
				while (*str)
				{
					_putchar(*str);
					str++;
					count++;
				}
				break;
			case '%':
				_putchar('%');
				count++;
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
