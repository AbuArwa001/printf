#include "main.h"
/**
 * chk_buf_len - chcks if buffer has reached its limit
 * @buffer: buffer to be freed if str is null
 * @format: format string to use
 * @BUF:  buffer for updating
 * @ch: character to be used to check and update buffer
 * @i: index of current pointer to buffer
 * Return: return 1 if not null and -1 if null
*/
int chk_buf_len(char *buffer, char const *format, int *BUF, char *ch, int *i)
{
	int len = 0;

	if (buffer == NULL)
	{
		len = 0;
	}
	else
	{
		len =  _strlen(buffer) + 1;
	}

	if (len >= *BUF)
	{
		return (1);
	}

	*ch = format[*i];
	_strncat(buffer, ch, 1);
	*i += 1;
	return (0);
}
/**
 * chk_buf_le_str - chcks if buffer has reached its limit
 * @buffer: buffer to be freed if str is null
 * @BUF:  buffer for updating
 * @str: string to be used to check and update buffer
 *
 * Return: return 1 if not null and -1 if null
*/
int chk_buf_le_str(char **buffer, int *BUF, char **str)
{

	int len1 = 0;
	int lenbuf = 0;

	if (*str == NULL)
	{
		len1 = 0;
	}
	else
	{
		len1 = _strlen(*str);
		lenbuf = _strlen(*buffer);
	}

	if (((len1 + lenbuf - 1)  >= *BUF) && (*str != *buffer))
	{
		return (-1);
	}

	return (1);
}
/**
 * chk_buflen - chcks if buffer has reached its limit
 * @buffer: buffer to be freed if str is null
 * @BUF:  buffer for updating
 * @len: string to be used to check and update buffer
 *
 * Return: return 1 if not null and -1 if null
*/
int chk_buflen(char *buffer, int *BUF, int len)
{
	int lenbuf = 0;

	lenbuf = _strlen(buffer);

	if ((len + lenbuf - 1)  >= *BUF)
	{
		return (-1);
	}

	return (1);
}
