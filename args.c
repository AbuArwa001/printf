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
	if (c[1] == '\0')
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
	if ((_strlen(str) + _strlen(buf) - 1)  >= _strlen(buf))
	{
		int new_len = 0;
		int old_len = 0;

		new_len = ((_strlen(str) + _strlen(buf)));
		old_len = _strlen(buf);
		buf  = _realloc(buf, old_len, new_len * 2);
		_memset((buf + old_len), 0, (new_len + old_len));
	}

	return (_strcat(buf, str));
}
