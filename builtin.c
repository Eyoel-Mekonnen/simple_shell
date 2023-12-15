#include "header.h"

/**
 * _myexit - exits the shell
 * @custom_info: Structure containing potential arguments.
 *  Return: 0 if info argv 0 != exit
 */
int _myexit(info_t *custom_info)
{
	int exit;

	if (custom_info->argv[1])
	{
		exit = _erratoi(custom_info->argv[1]);
		if (exit == -1)
		{
			custom_info->status = 2;
			print_error(custom_info, "unwanted number: ");
			_eputs(custom_info->argv[1]);
			_eputchar('\n');
			{
				return (1);
			}
		}
		custom_info->err_num = _erratoi(custom_info->argv[1]);
		return (-2);
	}
	custom_info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @counter1: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: 0
 */
int _mycd(info_t *counter1)
{
	char *soft, *darken, buffer[1024];
	int buff2;

	soft = getcwd(buffer, 1024);
	if (!soft)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!counter1->argv[1])
	{
		darken = _getenv(counter1, "HOME=");
		if (!darken)
			buff2 = chdir((darken = _getenv(counter1, "PWD=")) ? darken : "/");
		else
			buff2 = chdir(darken);
	}
	else if (_strcmp(counter1->argv[1], "-") == 0)
	{
		if (!_getenv(counter1, "OLDPWD="))
		{
			_puts(soft);
			_putchar('\n');
			{
				return (1);
			}
		}
		_puts(_getenv(counter1, "OLDPWD=")), _putchar('\n');
		buff2 = chdir((darken = _getenv(counter1, "OLDPWD=")) ? darken : "/");
	}
	else
		buff2 = chdir(counter1->argv[1]);
	if (buff2 == -1)
	{
		print_error(counter1, "can't cd to ");
		_eputs(counter1->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(counter1, "OLDPWD", _getenv(counter1, "PWD="));
		_setenv(counter1, "PWD", getcwd(buffer, 1024));
	}
	{
		return (0);
	}
}

/**
 * _myhelp - changes the current directory of the process
 * @context: Structure containing potential arguments.
 *  Return: 0
 */
int _myhelp(info_t *context)
{
	char **argu;

	argu = context->argv;
	_puts("function not yet implemented \n");
	if (argu != NULL && *argu != NULL)
	{
		_puts(*argu);
	}
	return (0);
}
