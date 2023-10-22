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
 *  @B: size of BUFFER currently
 * Return: returns updated buffer;
*/
char *custom_convert(char **buf, char c, va_list a, int *B)
{
	char *str = NULL, *est = NULL;
	int b = 0, str_len = 0, ilen = 0, ble = _strlen(*buf), old = *B;

	switch (c)
	{
		case 'b':
			b = va_arg(a, int);
			ilen = bin_len(b);
			(ilen + ble >= *B) ? (*B = (*B * 2)), (*buf = _realloc(*buf, old, *B)) : 0;
			str = toBinary(*buf, b);
			break;

		case 'R':
			str = va_arg(a, char *);
			str = rot13(*buf, str);
			break;

		case 'r':
			est = va_arg(a, char *);
			str = rev_str(*buf, (est != NULL) ? est : NULL, str_len);
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
 *  @B: buffer length to keep track
 *  @cnt: charcter count for nullbyte
 * Return: returns updated buffer;
*/
char *convert(char **buf, char c, va_list a, int *B, int *cnt)
{
	char *str = NULL, ch = '\0', **ptr = NULL;
	int ilen = 0, va = 0, ble = _strlen(*buf), old = *B;

	switch (c)
	{
		case 'c':
			ch = va_arg(a, int);
			(ch == '\0') ? (_putchar('\0'), (*cnt += 1)) : 0;
			*(*buf + ble) = ch;
			str = *buf;
			break;
		case 'd':
			va = va_arg(a, int);
			ilen = int_len(va);
			(ilen + ble >= *B) ? (*B = (*B * 2)), (*buf = _realloc(*buf, old, *B)) : 0;
			str = str_buff(*buf, va, ilen);
			break;
		case 'i':
			va = va_arg(a, int);
			ilen = int_len(va);
			str = str_buff(*buf, va, ilen);
			str = (str != NULL ? str : NULL);
			break;
		case '%':
			*(*buf + ble) = c;
			str = *buf;
			break;
		case 's':
			str = va_arg(a, char *);
			str = add_str(*buf, (str != NULL) ? str : NULL, B);
			break;
		case 'p':
			ptr = va_arg(a, char **);
			str = add_str(*buf, (*ptr != NULL) ? *ptr : NULL, B);
			break;
		default:
			break;
	}
	return (str);
}
/**
 * fmt - validifies format string to a specified specifier
 *  @fm: buffer to be updated
 *  @bf: character to be checked
 *  @a: va list
 *  @i: character index
 *  @B: buffer length to keep track
 *	@s: use to track bufer
 *  @c: character count for nullbyte
 * Return: returns updated buffer;
*/
int fmt(const char *fm, char **bf, char **s, va_list a, int *i, int *B, int *c)
{
	char ch = '\0',  *str = NULL;
	int chk = 0;

	ch = (fm[*i] == '%') ?  fm[*i + 1] : fm[*i];
	if (fm[*i] == '%')
	{
		if (char_checck(ch))
		{
			*s = convert(bf, ch, a, B, c);
			chk = chk_buf_le_str(bf, B, s);
			*i += (chk == -1) ? 1 : 2;
			return ((chk == -1) ? 3 : 1);
		}
		else if (custom_checck(ch))
		{
			str = custom_convert(bf, ch, a, B);
			*i += 2;
			return ((chk_str(str) == -1) ? -1 : 1);
		}
		else if (octal_checck(ch))
		{
			str = convert_hex(*bf, ch, a);
			*i += 2;
			return ((chk_str(str) == -1) ? -1 : 1);
		}
		else if (ch != '\0')
		{
			chk = chk_buf_len(*bf, fm, B, &ch, i);
			return ((chk == 1) ? 2 : 1);
		}
		else
			return (-1);
	}
	else
	{
		chk = chk_buf_len(*bf, fm, B, &ch, i);
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
	int pr = 0, i = 0, tracker = 0, cnt = 0;
	int BUFFSIZE = 1024, old = 1024;
	char *buffer = _calloc(BUFFSIZE, sizeof(char)), ch = '\0';
	char *str = NULL;
	va_list args;

	if (chk_buf(buffer, format) == -1 ? 1 : 0)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		tracker = fmt(format, &buffer, &str, args, &i, &BUFFSIZE, &cnt);
		if (tracker == 2)
		{
			BUFFSIZE = (BUFFSIZE * 2);
			buffer = _realloc(buffer, old, BUFFSIZE);
			ch = format[i];
			_strncat(buffer, &ch, 1);
			i += 1;
		}
		else if (tracker == 3)
		{
			BUFFSIZE = (BUFFSIZE * 2);
			i += 1;
			buffer = _realloc(buffer, old, BUFFSIZE);
			if (chk_str(buffer) == -1 ? 1 : 0)
				return (-1);
			_strcat(buffer, str);
		}
		else if (tracker == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	pr = print_buff(buffer, _strlen(buffer)) + cnt;
	va_end(args);
	free(buffer);
	return (pr);
}
