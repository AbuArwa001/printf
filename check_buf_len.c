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
int chk_buf_len(char *buffer, char const *format, int *BUF, char ch, int *i)
{
	int len = _strlen(buffer);

	if (len >= *BUF)
	{
		return (1);
	}

	ch = format[*i];
	_strncat(buffer, &ch, 1);
	*i += 1;
	return (0);
}
