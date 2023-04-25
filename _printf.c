#include "main.h"

/**
* _printf - A a function that produces output according to a format.
* @format: Is a character string.
* Return: The number of characters printed excluding '\0'
*/

int _printf(const char *format, ...)
{
int i = 0, count = 0;
char *str;
va_list args;

va_start(args, format);
while (format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
count += print_str(str);
break;
case '%':
count += print_char('%');
default:
count += print_char('%');
count += print_char(format[i]);
break;
}
}
else
{
count += print_char(format[i])
}
i++;
}
va_end(args);
return (count);
}

/**
 * print_char - A function that prints a character to the standard output.
 * @c: The character to be printed.
 * Return: The number of characters printed (always 1).
 */

int print_char(char c)
{
return (write(1, &c, 1));
}

/**
 * print_str - A function that prints a string to the standard output.
 * @str: The string to be printed.
 * Return: The number of characters printed (excluding the null byte).
 */

int print_str(char *str)
{
int i;

for (i = 0; str[i]; i++)
{
print_char(str[i]);
}
return (i);
}
