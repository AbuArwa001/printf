#include "main.h"
/**
 * chk_str - chcks if string is null
 * @buffer: buffer to be freed if str is null
 * Return: return 1 if not null and -1 if null
*/
int chk_str(char *buffer)
{
	if (buffer == NULL)
	{
		free(buffer);
		return (-1);
	}

	return (1);
}
/**
 * chk_buf - chcks if buff or fmt string is null
 * @format: string to be checked
 * @buffer: buffer to be freed if str is null
 * Return: return 1 if not null and -1 if null
*/
int chk_buf(char *buffer, const char *format)
{
	if (buffer == NULL || format == NULL)
	{
		free(buffer);
		return (-1);
	}

	return (1);
}

/**
 * char_checck - checks if chrarcter is available
 * @c: character to be checked
 * Return: returns 0 if not fount and 1 if foud
*/
int char_checck(char c)
{
	char *arr = "csdip%";
	int i = 0;

	for (i = 0; i < _strlen(arr); i++)
	{
		if (c == arr[i])
		{
			return (1);
		}
	}

	return (0);


}
/**
 * custom_checck - checks if chrarcter is available
 * @c: character to be checked
 * Return: returns 0 if not fount and 1 if foud
*/
int custom_checck(char c)
{
	char *arr = "bSrR";
	int i = 0;

	for (i = 0; i < _strlen(arr); i++)
	{
		if (c == arr[i])
		{
			return (1);
		}
	}

	return (0);


}
/**
 * octal_checck - checks if chrarcter is available
 * @c: character to be checked
 * Return: returns 0 if not fount and 1 if foud
*/
int octal_checck(char c)
{
	char *arr = "xXuoS";
	int i = 0;

	for (i = 0; i < _strlen(arr); i++)
	{
		if (c == arr[i])
		{
			return (1);
		}
	}
return (0);
}
