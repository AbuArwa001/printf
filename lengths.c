#include "main.h"
/**
 * bin_len - finds the lenth of binry representation
 * @b: number to be converted
 *
 * Return: returns the length of the binary
*/
int bin_len(int b)
{
	int i = 0;

	while (b > 0)
	{
		b /= 2;
		i++;
	}

	return (i);
}
