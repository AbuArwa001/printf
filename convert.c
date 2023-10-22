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
char *toBinary(char *buf, unsigned int b)
{
	int i = 0, len = _strlen(buf);
	unsigned int b2 = b;

	if (b2 == 0)
	{
		buf[len] = 0 + '0';
		return (buf);
	}

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
/**
* _abs - computes absolute value of an integer
* @in: the integer to be converted
*
* Return: it returns an absolute value
*/

int _abs(int in)
{
	if (in < 0)
	{
		return (in * -1);
	}
	else
		return (in);
}
