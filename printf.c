#include "main.h"

/**
 * print_buff - prints buffer
 *  @buff: buffer to be updated
 *  @len: length of the buffer
 * Return: returns number of bytes printed;
*/
int print_buff(char *buff, int len)
{
	int writen = 0;

	if (buff == NULL)
	{
		return (-1);
	}

	writen = write(1, buff, len);

	return (writen);
}
/**
 * custom_convert - converts string to a specified specifier
 *  @buf: buffer to be updated
 *  @c: character to be checked
 *  @a: list to travers and keep track of
 * Return: returns updated buffer;
*/
char *custom_convert(char *buf, char c, va_list a)
{
	char *str = NULL;
	int b = 0;

	switch (c)
	{
		case 'b':
			b = va_arg(a, int);
			str = toBinary(buf, b);
			break;

		case 'R':
			str = va_arg(a, char *);
			str = rot13(buf, str);
			break;

		case 'r':
			str = va_arg(a, char *);
			str = rev_str(buf, (str != NULL) ? str : NULL);
			break;

		default:
			break;
	}

	return (str);
}
/**
 * convert - converts string to a specified specifier
 *  @buf: buffer to be updated
 *  @c: character to be checked
 *  @a: list to travers and keep track of
 * Return: returns updated buffer;
*/
char *convert(char *buf, char c, va_list a)
{
	char *str = NULL, ch = '\0', **ptr = NULL;
	int intlen = 0, va = 0;

	switch (c)
	{
		case 'c':
			ch = va_arg(a, int);
			buf[_strlen(buf)] = ch;
			str = buf;
			break;

		case 'd':
			va = va_arg(a, int);
			intlen = int_len(va);
			str = str_buff(buf, va, intlen);
			break;

		case 'i':
			va = va_arg(a, int);
			intlen = int_len(va);
			str = str_buff(buf, va, intlen);
			str = (str != NULL ? str : NULL);
			break;
		case '%':
			buf[_strlen(buf)] = c;
			str = buf;
			break;
		case 's':
			str = va_arg(a, char *);
			str = add_str(buf, (str != NULL) ? str : NULL);
			break;
		case 'p':
			ptr = va_arg(a, char **);
			str = add_str(buf, (*ptr != NULL) ? *ptr : NULL);
			break;
		default:
			break;
	}
	return (str);
}
/**
 * fmt - validifies format string to a specified specifier
 *  @format: buffer to be updated
 *  @buffer: character to be checked
 *  @c: list to travers and keep track of
 *  @args: va list
 *  @i: character index
 *  @B: buffer length to keep track
 * Return: returns updated buffer;
*/
int fmt(const char *format, char *buffer, char c, va_list args, int *i, int *B)
{
	char ch = c,  *str = NULL;
	int chk = 0;

	if (format[*i] == '%')
	{
		ch = format[*i + 1];
		if (char_checck(ch))
		{
			convert(buffer, ch, args);
			if (chk_str(buffer) == -1)
				return (-1);
			*i += 2;
		}
		else if (custom_checck(ch))
		{
			str = custom_convert(buffer, ch, args);
			*i += 2;
			return ((chk_str(str) == -1) ? -1 : 1);
		}
		else if (octal_checck(ch))
		{
			str = convert_hex(buffer, ch, args);
			if (chk_str(str) == -1)
				return (-1);
			*i += 2;
		}
		else if (ch != '\0')
		{
			chk = chk_buf_len(buffer, format, B, ch, i);
			return ((chk == 1) ? 2 : 1);
		}
		else
			return (-1);
	}
	else
	{
		chk = chk_buf_len(buffer, format, B, ch, i);
		return ((chk == 1) ? 2 : 1);
	}
	return (1);
}
/**
 * _printf - perfrms printing on stdout
 *  @format: format string to be used
 *  Return: returns the number of characters printed excluding nullbyte
 *
*/
int _printf(const char *format, ...)
{
	int pr = 0, i = 0, tracker = 0;
	int BUFFSIZE = 1024, old = 1024;
	char *buffer = _calloc(BUFFSIZE, sizeof(char)), ch = '\0';
	va_list args;

	if (chk_buf(buffer, format) == -1)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		tracker = fmt(format, buffer, format[i], args, &i, &BUFFSIZE);

		if (tracker == 1)
		{
			continue;
		}
		else if (tracker == 2)
		{
			BUFFSIZE = (BUFFSIZE * 2);
			buffer = _realloc(buffer, old, BUFFSIZE);
			ch = format[i];
			_strncat(buffer, &ch, 1);
			i += 1;
			continue;
		}
		else if (tracker == -1)
		{
			va_end(args);
			return (-1);
		}
	}

	pr = print_buff(buffer, _strlen(buffer));
	va_end(args);
	free(buffer);
	return (pr);
}
