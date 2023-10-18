#include "shell.h"

/**
*INTERACTIVE: IF SHELL IS INTERACTIVE MODE RETURN TRUE
*@INFO: STRUCT ADDRESS
*
*RETURN: 1 IF INTERACTIVE MODE, 0 OTHERWISE
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - CHECKS IF THE CHARACTER IS A DELIMETER
 * @c: THE CHAR TO CHECK
 * @delim: DELIMETER STRING
 * Return: 1 IF TRUE, 0 IF FALSE
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - ALPHABETIC CHARACTERS CHECKED
 * @c: CHARACTER TO INPUT
 * Return: 1 IF C IS ALPHABETIC, 0 OTHERWISE
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - CONVERTS A STRING TO AN INTEGER
 * @s: STRING TO BE CONVERTED
 * Return: 0 IF NO NUMBERS IN STRING, CONVERTED NUMBER OTHERWISE
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
