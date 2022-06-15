#include "shell.h"

/**
 * _putchar - writes a character to stdout.
 * @c: Character to write to stdout.
 *
 * Return: Bytes written to stdout.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * free_env - frees an array of strings containing env variables.
 * @env: Array of strings containing environment variables.
 *
 * Return: Void.
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
