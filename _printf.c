#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: The specified format
 *
 * Return: The number of characters that were printed
 */
int _printf(const char *format, ...)
{
	int i = 0, tmp, processing_escape = FALSE, error = 1, last_token;
	fmt_info_t fmt_info;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	write_to_buffer(0, -1);
	for (i = 0; format && *(format + i) != '\0'; i++)
	{
		if (processing_escape)
		{
			tmp = read_format_info(format + i, args, &fmt_info, &last_token);
			processing_escape = FALSE;
			set_format_error(format, &i, tmp, last_token, &error);
			if (is_specifier(fmt_info.spec))
				write_format(&args, &fmt_info);
			i += (is_specifier(fmt_info.spec) ? tmp : 0);
		}
		else
		{
			if (*(format + i) == '%')
				processing_escape = TRUE;
			else
				_putchar(*(format + i));
		}
	}
	write_to_buffer(0, 1);
	va_end(args);
	return (error <= 0 ? error : write_to_buffer('\0', -2));
}
