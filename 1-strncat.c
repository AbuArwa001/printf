#include "main.h"
/**
 * _strncat - conctaenates a string to n characters
 * @dest: the destination of copiied characters
 * @src: the source of copied of characters
 * @n: number of characters to be copied
 * Return: returns a modified string
 */


char *_strncat(char *dest, char *src, int n)
{
	int i = _strlen(dest);
	int j = 0;

	if (n > _strlen(src))
	{
		n = _strlen(src);
	}

	while (j < n && (*src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		j++;
		i++;
	}

	*(dest + i) = '\0';

	return (dest);
}
