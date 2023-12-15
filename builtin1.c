#include "header.h"

/**
 * _myhistory - displays the history list, one command by line,
 * @int_info: Structure containing potential arguments.
 *  Return: Always 0.
 */
int historyinfo(info_t *int_info)
{
	print_list(int_info->history);
	{
		return (0);
	}
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *ptr, count;
	int ret;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	count = *ptr;
	*ptr = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*ptr = count;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * aliasMy - mimics the alias builtin (man alias)
 * @infront: Structure containing potential arguments.
 *  Return: 0
 */
int aliasMy(info_t *infront)
{
	int count = 0;
	char *p = NULL;
	list_t *nodecount = NULL;

	if (infront->argc == 1)
	{
		nodecount = infront->alias;
		for (; nodecount; nodecount = nodecount->next)
		{
			print_alias(nodecount);
		}
		return (0);
	}
	for (count = 1; infront->argv[count]; count++)
	{
		p = _strchr(infront->argv[count], '=');
		if (p)
			set_alias(infront, infront->argv[count]);
		else
			print_alias(node_starts_with(infront->alias, infront->argv[count], '='));
	}

	return (0);
}
