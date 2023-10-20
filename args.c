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
 *	@BUFSIZE: size of the BUFFER
 * Return: returns a string;
*/
char *add_str(char *buf, char *str, int *BUFSIZE)
{

	if (str == NULL)
	{
		str = "";
		_strcat(buf, "(null)");
		return (str);
	}
	if ((_strlen(str) + _strlen(buf) - 1)  >= *BUFSIZE)
	{
		return (str);
	}

	return (_strcat(buf, str));
}
