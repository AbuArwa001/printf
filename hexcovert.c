#include "main.h"
/**
 * convert_hex - converts string to a specified specifier
 *  @buf: buffer to be updated
 *  @c: character to be checked
 *  @a: list to travers and keep track of
 * Return: returns updated buffer;
*/
char *convert_hex(char *buf, char c, va_list a)
{
	char *str = NULL, ch = '\0';
	int intlen = 0, va = 0;
	unsigned int vi = 0;

	switch (c)
	{
		case 'x':
			ch = va_arg(a, int);
			buf[_strlen(buf)] = ch;
			str = buf;
			break;

		case 'X':
			va = va_arg(a, int);
			intlen = int_len(va);
			str = str_buff(buf, va, intlen);
			break;

		case 'u':
			va = va_arg(a, int);
			intlen = int_len(va);
			str = str_buff(buf, va, intlen);
			str = (str != NULL ? str : NULL);
			break;

		case 'o':
			vi = va_arg(a, unsigned int);
			str = octal(buf, vi);
			break;

		default:
			break;
	}

	return (str);
}
