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
