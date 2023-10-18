#include "shell.h"

/**
 * _myenv - CURRENT ENVIRONMENT PRINTED
 * @info: STRUCTURE OF POTENTIAL ARGUMENTS CONTAINED. USED TO MAINTAIN
 *         CONSTANT FUNCTION PROTOTYPE.
 * Return: ALWAYS 0 (SUCCESS)
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - VALUE OF AN ENVIRON VARIABLE
 * @info: STRUCTURE OF POTENTIAL ARGUMENTS CONTAINED. USED TO MAINTAIN
 * @name: ENV VAR NAME
 *
 * Return: THE VALUE
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - A NEW ENVIRONMENT VARIABLE INITIALIZED,
 *            OR MODIFY AN EXISTING ONE
 * @info: STRUCTURE OF POTENTIAL ARGUMENTS CONTAINED. USED TO MAINTAIN
 *         CONSTANT FUNCTION PROTOTYPE.
 *  Return: ALWAYS 0 (SUCCESS)
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - AN ENVIRONMENT VARIABLE REMOVED
 * @info: STRUCTURE OF POTENTIAL ARGUMENTS CONTAINED. USED TO MAINTAIN
 *         CONSTANT FUNCTION PROTOTYPE.
 * Return: ALWAYS 0(SUCCESS)
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - ENV LINKED LIST POPULATED
 * @info: STRUCTURE OF POTENTIAL ARGUMENTS CONTAINED. USED TO MAINTAIN
 *         CONSTANT FUNCTION PROTOTYPE.
 * Return: ALWAYS 0 (SUCCESS)
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
