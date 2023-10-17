#include "main.h"
/**
 *  _isdigit - checks if a character is  a digit
 *  @c: charater to be checked
 *  Return: returns 1 if upper
 *          returns 0 if otherwise
 */

int _isdigit(int c)
{

	int i = 0;

	for (; i <= 9; i++)
	{

		if (c == i)
		{
			return (1);
		}
	}

	return (0);
}
/**
 *  toBinary - checks if a character is  a digit
 *  @buf: charater to be checked
 *  @b: number to be converted
 *  Return: returns 1 if upper
 *          returns 0 if otherwise
 */
char *toBinary(char *buf, int b)
{
	int i = 0, len = _strlen(buf), b2 = b;


	while (b > 0)
	{
		b /= 2;
		i++;
	}

	while (b2 > 0)
	{
		buf[(len + i) - 1] = (b2 % 2) + '0';
		b2 /= 2;
		i--;
	}

	return (buf);
}
