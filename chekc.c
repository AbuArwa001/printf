#include "main.h"
/**
 * chk_str - chcks if string is null
 * @buffer: buffer to be freed if str is null
 * Return: return 1 if not null and -1 if null
*/
int chk_str(char *buffer)
{
	if (buffer == NULL)
	{
		free(buffer);
		return (-1);
	}
	return (1);
}
/**
 * chk_buf - chcks if buff or fmt string is null
 * @format: string to be checked
 * @buffer: buffer to be freed if str is null
 * Return: return 1 if not null and -1 if null
*/
int chk_buf(char *buffer, const char *format)
{
	if (buffer == NULL || format == NULL)
	{
		free(buffer);
		return (-1);
	}
	return (1);
}
