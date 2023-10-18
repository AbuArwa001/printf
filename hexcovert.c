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
	char *str = NULL;
	int intlen = 0, hx = 0;
	unsigned int vi = 0;

	switch (c)
	{
		case 'x':
			hx = va_arg(a, int);
			intlen = int_len(hx);
			str = smHex_conv(buf, hx);
			break;

		case 'X':
			hx = va_arg(a, int);
			intlen = int_len(hx);
			str = hex_conv(buf, hx);
			break;

		case 'u':
			hx = va_arg(a, int);
			intlen = int_len(hx);
			str = str_buff(buf, hx, intlen);
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
