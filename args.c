#include "main.h"
/**
 * c_tostr - adds char to buffer
 * @buf: buffer to be updated
 * @c: converted charcter to str added to buffer
 *
 * Return: returns a string or null if c not a string;
*/
char *c_tostr(char *buf, char *c)
{
	if (c[0] != '\0')
	{
		return (_strncat(buf, c, 1));
	}
	else
	{
		return (NULL);
	}
}
/**
 * add_str - adds string to buffer
 *  @buf: buffer to be updated
 *  @str: string to be added to buffer
 *
 * Return: returns a string;
*/
char *add_str(char *buf, char *str)
{
	if (str == NULL)
	{
		_strcat(buf, "(null)");
		return (NULL);
	}

	return (_strcat(buf, str));
}
