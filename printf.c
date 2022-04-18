#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
 *_printf - print args
 *@format: 1st param
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list p;
	int  d, bytes_written = 0;
	char c, *s;
	unsigned int u;
	short int i;

	if (format == NULL)
		return (0);
	va_start(p, format);
	c = *format;
	while (c != '\0')
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					c = (char) va_arg(p, int);
					bytes_written += write(1, &c, 1);
					break;
				case '%':
					c = '%';
					bytes_written += write(1, &c, 1);
					break;
				case 's':
					s = va_arg(p, char *);
					bytes_written += write(1, s, strlen(s));
					break;
				case 'd':
					d = va_arg(p, int);
					bytes_written += write_nbr(d);
					break;
				case 'i':
					i = va_arg(p, int);
					bytes_written += write_nbr(i);
					break;
				case 'u':
					u = va_arg(p, unsigned int);
					bytes_written += write_unsign_nbr(u);
					break;
				default:
					bytes_written += write(1, &c, 1);
					c = *format;
					bytes_written += write(1, &c, 1);
			}
		} else
		{
			bytes_written += write(1, format, 1);
		}
		c = *(++format);
	}
	va_end(p);
	return (bytes_written);
}
