#include <stdio.h>
/**
 * _memset - it sets the n bytes with  b pointed to by s
 * @s: pointer to memory to be manipulated
 * @b: charcter to be used to manipulate
 * @n: number of bytes to use
 *
 * Return: it returns a pointer to s;
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n ; i++)
	{
		s[i] = b;
	}

	return (s);
}
