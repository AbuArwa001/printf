#include "main.h"
/**
 *  isFloat - checks if number is float
 *  @num: accepts float num
 *  Return: returns 1 if true and 0 of false;
 *
*/
int isFloat(float num)
{
	int n = (int)(num);

	if ((num - n) == 0)
	{
		return (0);
	}

	return (1);
}
/**
 * precision - checks the position of  decimal point
 * @n: accepts float number
 * Return: returns a position of point;
*/
int precision(float n)
{
	int i = 0;

	for (; isFloat(n); i++)
	{
		n *= 10;
	}

	return (i);
}
/**
 * float_toInt - chanes float to int
 *  @n: float to change
 * Return: returns an in to it;
*/
int float_toInt(float n)
{
	int i = 0, digit = (int)n, multiple = 1;

	while ((n * multiple) - digit != 0)
	{
		multiple *= 10;
		digit = ((int)(n * multiple));
		i++;
	}

	digit = ((int)(n * multiple));
	return (digit);
}
/**
 * float_buff - changes float to string
 * @fb: buffer for float
 * @no: number to be changed
 * @len: legth of the float number
 * @pr: precision of decimal point
 *
 * Return: returns string converted from float;
*/
char *float_buff(char *fb, int no, int len, int pr)
{
	int i = len - 1;

	for (; i >= 0; i--)
	{
		if (i == pr)
		{
			fb[i] = '.';
		}
		else
		{
			fb[i] = (no % 10) + '0';
			no /= 10;
		}

	}

	fb[len] = '\0';

	return (fb);
}
