#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _strcat - it concantenates two strings
 * @dest: string to be appended to
 * @src: string to be appended from
 * Return: retursns combined strins
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;
	int new_length = 0;

	i =  _strlen(dest);
	new_length = i + _strlen(src);

	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	*(dest + new_length) = '\0';

	return (dest);
}
