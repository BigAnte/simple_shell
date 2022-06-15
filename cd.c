#include "shell.h"

/**
 * build_var - builds a full environment variable from given name and value.
 * @name: Variable name.
 * @value: Variable value.
 *
 * Return: String containing full environment variable.
 */
char *build_var(char *name, char *value)
{
	char *new_var;
	size_t var_len;

	var_len = _strlen(name) + _strlen(value) + 2;
	new_var = malloc(sizeof(char) * var_len);
	if (!new_var)
	{
		putstr("Error: build_var->malloc\n");
		return (NULL);
	}

	_memset(new_var, 0, var_len);

	new_var = _strcat(new_var, name);
	new_var = _strcat(new_var, "=");
	new_var = _strcat(new_var, value);

	return (new_var);
}


/**
 * _setenv - updates or adds an environment variable.
 * @name: Variable name.
 * @value: Variable value.
 * @env: Array of strings containing environment variables.
 *
 * Return: 0 on success otherwise -1.
 */
int _setenv(char *name, char *value, char **env)
{
	size_t name_len;
	char *new_var;
	int i;

	name_len = _strlen(name);
	for (i = 0; env[i]; i++)
	{
		if (_strncmp(env[i], name, name_len) == 0)
		{
			new_var = build_var(name, value);
			free(env[i]);
			env[i] = _strdup(new_var);
			free(new_var);
			return (0);
		}
	}

	new_var = build_var(name, value);
	free(env[i]);
	env[i] = _strdup(new_var);
	env[++i] = NULL;
	free(new_var);

	return (0);
}



/**
 * cd_prev - change to previous directory and update environment variables.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: 0.
 */
int cd_prev(char **env)
{
	char *prevdir;
	char *cwd;

	cwd = _getcwd(env);

	prevdir = _getenv("OLDPWD");
	chdir(prevdir);
	free(prevdir);

	_setenv("OLDPWD", cwd, env);
	free(cwd);

	cwd = _getcwd(env);
	_setenv("PWD", cwd, env);
	free(cwd);

	return (0);
}

/**
 * cd_home - changes directory to home as well as updates environment vars.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: 0.
 */
int cd_home(char **env)
{
	char *home;
	char *cwd;

	cwd = _getcwd(env);
	_setenv("OLDPWD", cwd, env);
	free(cwd);

	home = _getenv("HOME");
	chdir(home);
	free(home);

	cwd = _getcwd(env);
	_setenv("PWD", cwd, env);
	free(cwd);

	return (0);
}


/**
 * _cd - handles the change directory built-in function.
 * @tokens: The parsed command line from stdin.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: 0.
 */
int _cd(char **tokens, char **env)
{
	char *cwd;

	if (tokens[1] != NULL)
	{
		if (_strncmp(tokens[1], "-", 1) == 0)
		{
			cd_prev(env);
		}
		else
		{
			cwd = _getcwd(env);
			_setenv("OLDPWD", cwd, env);
			free(cwd);
			if (chdir(tokens[1]) == -1)
			{
				perror(tokens[1]);
			}

			cwd = _getcwd(env);
			_setenv("PWD", cwd, env);
			free(cwd);
		}
	}
	else
	{
		cd_home(env);
	}
	return (0);
}