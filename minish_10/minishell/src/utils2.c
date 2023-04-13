/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:47:59 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/13 03:53:02 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../inc/builtins.h"

void	print_export(const char **exportp)
{
	int	i;

	i = 0;
	if (exportp)
	{
		while (exportp[i])
		{
			printf("declare -x %s\n", exportp[i]);
			++i;
		}
	}
}

void	ft_free(char **p, int count)
{
	while (count)
	{
		free((char *)p[count - 1]);
		p[count - 1] = NULL;
		count--;
	}
	free((char **)p);
	p = NULL;
}

// len includes last NULL
int	envp_len(char **envp)
{
	int	len;

	len = 0;
	if (!envp)
		return (0);
	while (envp[len])
		++len;
	return (len + 1);
}

char	*get_env_val(char *env_line)
{
	char	*val;
	int		len;
	int		i;

	if (!env_line)
		return (NULL);
	i = 0;
	while (env_line[i] && '=' != env_line[i])
	{
		++i;
	}
	if (!env_line[i])
	{
		return (NULL);
	}
	len = ft_strlen(env_line) - i;
	val = (char *)malloc(sizeof(char) * len);
	if (!val)
	{
		perror("get_env");
		return (NULL);
	}
	val = ft_strdup(env_line + i + 1);
	return (val);
}

char	*get_env_name(char *env_line)
{
	char	*var_name;
	int		pos;

	pos = equal_sign_pos(env_line);
	if (!env_line || -1 == pos)
		return (NULL);
	var_name = (char *)malloc(sizeof(char) * (pos + 1));
	if (!var_name)
		perror("var_name malloc error");
	var_name = ft_memcpy(var_name, env_line, pos);
	var_name[pos] = '\0';
	return (var_name);
}
