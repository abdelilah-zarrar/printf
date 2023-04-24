#include "main.h"

/**
 * _printf - A a function that produces output according to a format.
 * @format: Is a character string.
 * Return: The number of characters printed excluding '\0'
 */
int _printf(const char *format, ...)
{
	int i;
	int j;
	int count;
	char *tmp;
	va_list arg;

	i = 0;
	j = 0;
	count = 0;
	if (format == NULL)
		return (1);
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			_putchar(va_arg(arg, int));
			i++;
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			tmp = va_arg(arg, char *);
			while (tmp[j] != '\0')
			{
				_putchar(tmp[j]);
				j++;
				count++;
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
