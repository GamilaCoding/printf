#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct format - struct format 
 *
 * @op: the operator
 * @f: the function associated
 */
typedef struct operation
{
	char *op;
	void (*f)(va_lst arg);
}
operation_t;
int write_to_buffer(char c, char action);
void write_format(va_list *args_list, fmt_info_t *fmt_info);
int _printf(const char *format, ...);
#endif
