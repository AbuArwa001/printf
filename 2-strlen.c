#include "main.h"
/**
 * _strlen - computes the size of a string
 *
 * @s: the string to be examined
 * Return: returns the length in number
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
	{
		length++;
	}

	return (length);
}
