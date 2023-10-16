#include "main.h"
/**
 * str_buff - convert int to str
 * @buf: buffer to be updated
 * @no: number to be converted
 * @len: length of the string
 * Return: returns the updated buffer
*/
char *str_buff(char *buf, int no, int len)
{
	int i = 0, ble = _strlen(buf), count = 0;

	count = (ble + len - 1);
	if (sizeof(no) != 4)
	{
		
		exit(2);
	}

	for (i = ble; i <= count ; i++)
	{
		if (no < 10)
		{
			buf[i] = (no + '0');
		}
		else
		{
			buf[i] = (no / 10) + '0';
			no %= 10;
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
