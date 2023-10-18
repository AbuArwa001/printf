#include "main.h"
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
		buf[i] = (n % 8) + '0';
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
			buf[i] = reminder + 55;
		}
		else
			if (reminder <= 9)
			{
				buf[i] = reminder + '0';
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
			buf[i] = reminder + 87;
		}
		else
			if (reminder <= 9)
			{
				buf[i] = reminder + '0';
			}

		n = n / 16;
		i--;
	}

	return (buf);
}
