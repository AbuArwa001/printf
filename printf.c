#include <stdarg.h>
#include "main.h"
/**
 * char_checck - checks if chrarcter is available
 * @c: character to be checked
 * Return: returns 0 if not fount and 1 if foud
*/
int char_checck(char c)
{
	char *arr = "cdixXuos%%";
	int i = 0;

	for (i = 0; i < _strlen(arr); i++)
	{
		if (c == arr[i])
		{
			return (1);
		}
	}

	return (0);


}
/**
 * print_buff - prints buffer
 *  @buff: buffer to be updated
 *  @len: length of the buffer
 * Return: returns number of bytes printed;
*/
int print_buff(char *buff, int len)
{
	int writen = 0;

	writen = write(1, buff, len);

	return (writen);
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
	char *str = NULL, ch[2];
	int intlen = 0, va = 0;

	switch (c)
	{
		case 'c':
			ch[0] = va_arg(a, int);
			ch[1] = '\0';
			str = c_tostr(buf, ch);
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
			break;

		case '%':
			ch[0] = '%';
			ch[1] = '\0';
			str = c_tostr(buf, ch);
			break;

		case 's':
			add_str(buf, va_arg(a, char *));
			break;

		default:
			break;
	}

	return (str);
}
/**
 * _printf - perfrms printing on stdout
 *  @format: format string to be used
 *  Return: returns the number of characters printed excluding nullbyte
 *
*/
int _printf(const char *format, ...)
{
	int pr = 0, i = 0;
	char *buffer = _calloc(1024, sizeof(char)), ch = ' ';
	/*int trcker = 0;*/
	va_list args;

	if (buffer == NULL || format == NULL)
	{
		return (-1);
	}

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			ch = format[i + 1];

			if (char_checck(ch))
			{
				convert(buffer, ch, args);
				/*_strcat(buffer, str);*/
				i += 2;
			}
			else
			{
				free(buffer);
				exit(1);
			}
		}
		else
		{
			ch = format[i];
			_strncat(buffer, &ch, 1);
			i++;
		}
	}
	pr = print_buff(buffer, _strlen(buffer));
	free(buffer);
	return (pr);
}
