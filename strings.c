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
	int i = 0, ble = 0, count = 0, no = n;

	if (sizeof(no) != 4)
		return (NULL);
	if (buf == NULL || n == NULL)
	{
		return (NULL);
	}
	ble = _strlen(buf);
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
