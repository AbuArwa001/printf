#include "main.h"
/**
 * _strlen - String length
 *
 * @s: The string to be measured
 *
 * Return: The length of @s
 */
int _strlen(const char *s)
{
	unsigned int l = 0;

	while (s && s[l])
		++l;
	return (l);
}
