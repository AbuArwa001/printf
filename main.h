#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
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
int _strlen(const char *s);
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
 * @buffer: buffer to be freed if str is null
 * Return: return 1 if not null and -1 if null
*/
int chk_str(char *buffer);
/**
 * char_checck - checks if chrarcter is available
 * @c: character to be checked
 * Return: returns 0 if not fount and 1 if foud
*/
int char_checck(char c);
/**
 * custom_checck - checks if chrarcter is available
 * @c: character to be checked
 * Return: returns 0 if not fount and 1 if foud
*/
int custom_checck(char c);
/**
 * rev_str- prints string in reverse
 * @buf: wherr the str is stored
 * @s: string to be reversed
 * @len: length of the string
 * Return: returns the rversed string for buffe
 */
char *rev_str(char *buf, char *s, int len);
/**
 * rot13 - cyphers string with rot 13 cyphers
 * @str: string to be encrypted
 * @buf: buffer to save rot
 * Return: returs encrypted string
 */
char *rot13(char *buf, char *str);
/**
 * convert_hex - converts string to a specified specifier
 *  @buf: buffer to be updated
 *  @c: character to be checked
 *  @a: list to travers and keep track of
 * Return: returns updated buffer;
*/
char *convert_hex(char *buf, char c, va_list a);
/**
 *  hex_convert - convert number to hex
 *  @buf: buffer to store octal
 *  @n: number to convert
 *  Return: coverted num
*/
char *hex_conv(char *buf, unsigned int n);
/**
 *  smHex_conv - convert number to hex
 *  @buf: buffer to store octal
 *  @n: number to convert
 *  Return: coverted num
*/
char *smHex_conv(char *buf, unsigned int n);
/**
 * str_buff_ui - convert int to str
 * @buf: buffer to be updated
 * @n: number to be converted
 * @len: length of the string
 * @li: check for signage
 * Return: returns the updated buffer
*/
char *str_buff_ui(char *buf, unsigned int n, int len, long int li);
/**
 * int_len_ui - finds the length of an in
 * @n: integer to find length for
 * Return: returns ength of int
*/
int int_len_ui(unsigned int n);
/**
* _abs - computes absolute value of an integer
* @in: the integer to be converted
*
* Return: it returns an absolute value
*/
int _abs(int in);
/**
 * chk_buf_len - chcks if buffer has reached its limit
 * @buffer: buffer to be freed if str is null
 * @format: format string to use
 * @BUF:  buffer for updating
 * @ch: character to be used to check and update buffer
 * @i: index of current pointer to buffer
 * Return: return 1 if not null and -1 if null
*/
int chk_buf_len(char *buffer, char const *format, int *BUF, char *ch, int *i);
/**
 * chk_buf_len - chcks if buffer has reached its limit
 * @buffer: buffer to be freed if str is null
 * @BUF:  buffer for updating
 * @str: str to be used to check and update buffer
 * Return: return 1 if not null and -1 if null
*/
int chk_buf_le_str(char *buffer, int *BUF, char *str);
int octal_checck(char c);
char *octal(char *buf, unsigned int n);
int int_len(int n);
char *str_buff(char *buf, int no, int len);
char *c_tostr(char *buf, char *c);
char *str_buff(char *buf, int no, int len);
int _printf(const char *format, ...);
char *add_str(char *buf, char *str, int *BUFSIZE);
char *toBinary(char *buf, int b);
#endif
