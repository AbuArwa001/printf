#include "main.h"
/**
 * str_buff - convert int to str
 * @buf: buffer to be updated
 * @n: number to be converted
 * @len: length of the string
 * Return: returns the updated buffer
*/
char *str_buff(char *buf, int n, int len)
{
	int i = 0, ble = _strlen(buf), count = 0, no = n, new_len = 0;

	if (no < 0)
	{
		no = -n;
		len += 1;
		count = (ble + len - 1);
		buf[ble] = '-';
		i = ble + 1;
	}
	else
	{
		count = (ble + len - 1);
		i = ble;
	}
	new_len = ((ble + len) * 2) + 1;
	if (count >= ble)
	{
		buf  = _realloc(buf, sizeof(char) *  ble, sizeof(char) * new_len);
		if (buf == NULL)
		{
			free(buf);
			return (NULL);
		}
		_memset((buf + ble), 0, count);
		if (n < 0)
			buf[ble] = '-';
	}
	for (; count >= i ; count--)
	{
		if (no < 10)
			buf[count] = (no + '0');
		else
		{
			buf[count] = (no % 10) + '0';
			no /= 10;
		}
	}
	buf[len + ble] = '\0';
	return (buf);
}
/**
 * int_len - finds the length of an in
 * @n: integer to find length for
 * Return: returns ength of int
*/
int int_len(int n)
{
	int i = 0;

	for (i = 0; n != 0; i++)
	{
		n /= 10;
	}

	return (i);

}
