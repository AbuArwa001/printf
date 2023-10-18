#include "main.h"
#include <limits.h>
/**
 *  octal - convert number to octal
 *  @buf: buffer to store octal
 *  @n: number to convert
 *  Return: coverted num
*/
char *octal(char *buf, unsigned int n)
{
	unsigned int  num = n, i = 0;

	if (n == 0)
	{
		buf[_strlen(buf)] = '\0';
	}

	while (num > 0)
	{
		num = num / 8;
		i++;
	}

	buf[_strlen(buf) + i] = '\0';
	i -= 1;

	while (n > 0)
	{
		buf[_strlen(buf) + i] = (n % 8) + '0';
		n = n / 8;
		i--;
	}

	return (buf);
}
/**
 *  hex_conv - convert number to hex
 *  @buf: buffer to store octal
 *  @n: number to convert
 *  Return: coverted num
*/
char *hex_conv(char *buf, unsigned int n)
{
	unsigned int i = 0, reminder = 0, num = n;

	if (n == 0)
	{
		buf[_strlen(buf)] = 0;
	}

	buf[_strlen(buf) + i] = '\0';
	i -= 1;

	while (num > 0)
	{
		num = num / 16;
		i++;
	}

	while (n > 0)
	{
		reminder = (n % 16);

		if (reminder < 16 && reminder > 9)
		{
			buf[_strlen(buf) + i] = reminder + 55;
		}
		else
			if (reminder <= 9)
			{
				buf[_strlen(buf) + i] = reminder + '0';
			}

		n = n / 16;
		i--;
	}

	return (buf);
}
/**
 *  smHex_conv - convert number to hex
 *  @buf: buffer to store octal
 *  @n: number to convert
 *  Return: coverted num
*/
char *smHex_conv(char *buf, unsigned int n)
{
	unsigned int i = 0, reminder = 0, num = n;

	if (n == 0)
	{
		buf[_strlen(buf)] = 0;
	}

	buf[_strlen(buf) + i] = '\0';
	i -= 1;

	while (num > 0)
	{
		num = num / 16;
		i++;
	}

	while (n > 0)
	{
		reminder = (n % 16);

		if (reminder < 16 && reminder > 9)
		{
			buf[_strlen(buf) + i] = reminder + 87;
		}
		else
			if (reminder <= 9)
			{
				buf[_strlen(buf) + i]  = reminder + '0';
			}

		n = n / 16;
		i--;
	}

	return (buf);
}

/**
 * _pow_recursion - Prints a power of a number
 * @x: number to be use
 * @y: power to be used
 * Return: returns the x raised to y
 *         returns -1 if y is less than 0
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}

	if (y == 0)
	{
		return (1);
	}

	return (x * _pow_recursion(x, y - 1));
}
/**
 * str_buff_ui - convert int to str
 * @buf: buffer to be updated
 * @n: number to be converted
 * @len: length of the string
 * @li:  long signed int form of n
 * Return: returns the updated buffer
*/
char *str_buff_ui(char *buf, unsigned int n, int len, long int li)
{
	int i = 0, ble = 0, count = 0;
	unsigned int no = 0;

	if (sizeof(no) != 4)
		return (NULL);
	if (buf == NULL)
	{
		return (NULL);
	}
	ble = _strlen(buf);
	if (li < 0)
	{
		n = _pow_recursion(2, 32) + li;

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
