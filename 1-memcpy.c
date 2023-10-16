#include "main.h"
/**
 * _memcpy - copies n bytes from memory area src to memory
 *           area dest
 * @dest: destination memory area of src
 * @src: source memory area to be copued
 * @n: number of bytes to be copied
 *
 * Return: returns dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n ; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
