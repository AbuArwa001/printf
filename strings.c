#include "main.h"
#include <stdlib.h>
#include <limits.h>
/**
 * str_buff - convert int to str
 * @buf: buffer to be updated
 * @n: number to be converted
 * @len: length of the string
 * Return: returns the updated buffer
*/
char *str_buff(char *buf, int n, int len)
{
	int i = 0, ble = 0, count = 0;
	unsigned int no = 0;

	if (sizeof(no) != 4)
		return (NULL);
	if (buf == NULL)
		return (NULL);
	ble = _strlen(buf);
	if (n < 0)
	{
		if (n <= INT_MIN)
			no = n;
		else
		{
			n = -n;
			no = n;
		}
		len += 1;
		count = (ble + len - 1);
		buf[ble] = '-';
		i = ble + 1;
	}
	else
	{
		no = n;
		count = (ble + len - 1);
		i = ble;
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

	if (n == 0)
	{
		return (1);
	}

	for (i = 0; n != 0; i++)
	{
		n /= 10;
	}

	return (i);

}
/**
 * rev_str - prints string in reverse
 * @buf: wherr the str is stored
 * @s: string to be reversed
 * Return: returns the rversed string for buffer
 */

char *rev_str(char *buf, char *s)
{
	int i = 0, strlen = 0;

	strlen = _strlen(s) - 1;

	if (s == NULL)
	{
		_strcat(buf, "%r");
		return (buf);
	}
	while (strlen >= 0)
	{
		buf[_strlen(buf)] = *(s + strlen);
		strlen--;
		i++;
	}
return (buf);
}
/**
 * int_len_ui - finds the length of an in
 * @n: integer to find length for
 * Return: returns ength of int
*/
int int_len_ui(unsigned int n)
{
	int i = 0;

	if (n == 0)
	{
		return (1);
	}

	for (i = 0; n != 0; i++)
	{
		n /= 10;
	}

	return (i);

}
