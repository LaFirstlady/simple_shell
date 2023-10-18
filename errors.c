#include "shell.h"

/**
 * _eputs - INPUT STRING PRINTED
 * @str: THE STRING TO BE PRINTED
 *
 * Return: NOTHING
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - WRITES THE CHARACTER C TO STDERR
 * @c: THE CHARACTER TO PRINT
 *
 * Return: 1 (SUCCESS)
 * On error, -1 IS RETURNED AND ERRNO IS SET APPROPRIATELY
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - THE CHARACTER C TO GIVEN FD WRITTEN
 * @c: CHARACTER TO PRINT
 * @fd: FILEDESCRIPTOR TO WRITE TO
 *
 * Return: 1 (SUCCESS)
 * On error, -1 IS RETURNED AND ERRNO IS SET APPROPRIATELY
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - AN INPUT STRING PRINTED
 * @str: STRING TO BE PRINTED
 * @fd: FILEDESCRIPTOR TO WRITE TO
 *
 * Return: NUMBER OF CHARS PUT
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
