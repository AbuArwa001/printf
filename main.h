#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strcat - it concantenates two strings
 * @dest: string to be appended to
 * @src: string to be appended from
 * Return: retursns combined strins
 */

char *_strcat(char *dest, char *src);
/**
 * _strlen - computes the size of a string
 *
 * @s: the string to be examined
 * Return: returns the length in number
 */
int _strlen(char *s);
/**
 * _strncat - conctaenates a string to n characters
 * @dest: the destination of copiied characters
 * @src: the source of copied of characters
 * @n: number of characters to be copied
 * Return: returns a modified string
 */
char *_strncat(char *dest, char *src, int n);
/**
 * _calloc - Allocates memof an array nmemb elements
 *           of size bytes each
 * @nmemb: number of elements to be given memory
 * @size: size of each element
 * Return: returns a pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size);
/**
 * _memcpy - copies n bytes from memory area src to memory
 *           area dest
 * @dest: destination memory area of src
 * @src: source memory area to be copued
 * @n: number of bytes to be copied
 *
 * Return: returns dest
 */

char *_memcpy(char *dest, char *src, unsigned int n);
/**
 * _memset - it sets the n bytes with  b pointed to by s
 * @s: pointer to memory to be manipulated
 * @b: charcter to be used to manipulate
 * @n: number of bytes to use
 *
 * Return: it returns a pointer to s;
 */

char *_memset(char *s, char b, unsigned int n);
/**
 * _realloc - reallocate a memory block using malloc
 * @ptr: pointer of memory to be reallocated
 * @old_size: ptrs old memory size
 * @new_size: ptrs new size
 * Return: returns a pointer to memory f the new allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/**
 * chk_buf - chcks if buff or fmt string is null
 * @format: string to be checked
 * @buffer: buffer to be freed if str is null
 * Return: return 1 if not null and -1 if null
*/
int chk_buf(char *buffer, const char *format);
/**
 * chk_str - chcks if string is null
 * @str: string to be checked
 * @buffer: buffer to be freed if str is null
 * Return: return 1 if not null and -1 if null
*/
int chk_str(char *str, char *buffer);
int int_len(int n);
char *str_buff(char *buf, int no, int len);
char *c_tostr(char *buf, char c);
char *str_buff(char *buf, int no, int len);
int _printf(const char *format, ...);
char *add_str(char *buf, char *str);
#endif
