#include "shell.h"

/**
 * _strncmp - compares (n) amount of characters of two strings.
 * @s1: A string.
 * @s2: A string.
 * @n: Amount of characters to compare.
 *
 * Return: 1 if the strings don't match otherwise return 0.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}


/**
 * _strdup - duplicate a string.
 * @str: A string to duplicate.
 *
 * Return: The duplicated string.
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		putstr("Error: strdup->malloc\n");
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}

/**
 * putstr - writes a string to stdout.
 * @str: A string.
 *
 * Return: Amount of bytes writen to stdout excluding null byte.
 */
int putstr(char *str)
{
	int i;

	if (!str)
	{
		return (-1);
	}

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}


/**
 * _memset - fills memory with a constant byte
 * @s: Memory area to initialize.
 * @c: Constant byte.
 * @n: Amount of bytes to initialize.
 *
 * Return: Void.
 */
void _memset(void *s, int c, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		*((char *)s + i) = c;
	}
}