#include "shell.h"

/**
 * own_cd - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: -1 one success, 0 otherwise.
 */
int own_cd(char **args)
{
	if (args[1])
	{	

		chdir(args[1]);
		return -1;
	}
	return (-1);
}
