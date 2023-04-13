/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:41:45 by tumolabs          #+#    #+#             */
/*   Updated: 2023/04/12 22:45:44 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/builtins.h"
#include "../libft/libft.h"

int	is_valid_identifier(char *text)
{
	if (!text)
	{
		ft_putstr_fd("export: NULL pointer\n", 2);
		return (0);
	}
	if (ft_isalpha(text[0]) || \
			('_' == text[0] && ('=' != text[1] || '\0' != text[1])))
	{
		return (1);
	}
	return (0);
}

int	is_valid_export_arg_for_env(char *text)
{
	int	pos;
	int	i;

	pos = equal_sign_pos(text);
	if (!is_valid_identifier(text) || 1 > pos)
	{
		return (0);
	}
	i = 0;
	while (i < pos)
	{
		if (!ft_isprint(text[i]))
			return (0);
		++i;
	}
	if ((!ft_isprint(text[pos + 1]) && '\0' != text[pos + 1]) || \
			' ' == text[pos + 1])
	{
		ft_putstr_fd("export: invalid command arg\n", 2);
		return (0);
	}
	return (1);
}

int	is_valid_export_arg_for_export(char *text)
{
	int	pos;
	int	i;

	pos = equal_sign_pos(text);
	if (!text || !is_valid_identifier(text))
		return (0);
	if (is_valid_export_arg_for_env(text))
		return (1);
	i = 0;
	while (text[i])
	{
		if (!ft_isprint(text[i]) || ' ' == text[i])
			return (0);
		++i;
	}
	return (1);
}

int	is_var_only_in_export(char *var_name, char **exportp)
{
	int	i;

	if (!var_name || !exportp)
		return (0);
	i = 0;
	while (exportp[i])
	{
		if (0 == ft_strncmp(var_name, exportp[i], ft_strlen(var_name)))
			return (1);
		++i;
	}
	return (0);
}

//get var_name from string: <var_name>=[...]
char	*get_env_var(char *text)
{
	char	*var_name;
	int		pos;
	int		i;

	if (is_valid_export_arg_for_env(text))
	{
		pos = equal_sign_pos(text);
		var_name = malloc (sizeof(char) * (pos + 1));
		if (!var_name)
			return (NULL);
		i = 0;
		while (i < pos)
		{
			var_name[i] = text[i];
			++i;
		}
		var_name[pos] = '\0';
		return (var_name);
	}
	return (NULL);
}
