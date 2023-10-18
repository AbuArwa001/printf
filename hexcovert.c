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
	unsigned int vi = 0, u = 0, intlen = 0, hx = 0;
	long int  li = 0;

	switch (c)
	{
		case 'x':
			hx = va_arg(a, unsigned int);
			intlen = int_len(hx);
			str = smHex_conv(buf, hx);
			break;

		case 'X':
			hx = va_arg(a, unsigned int);
			intlen = int_len(hx);
			str = hex_conv(buf, hx);
			break;

		case 'u':
			li = va_arg(a, long int);
			u = li;
			intlen = int_len_ui(u);
			str = str_buff_ui(buf, u, intlen, li);
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
