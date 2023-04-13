/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:17:18 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/13 01:56:51 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../inc/builtins.h"

int	get_env_var_pos_by_name(const char *env_var, char **envp)
{
	int	i;

	i = 0;
	if (envp)
	{
		while (envp[i])
		{
			if (is_var_in_env(envp[i], env_var))
			{
				return (i);
			}
			++i;
		}
	}
	return (-1);
}

// alter for built-in setenv
int	update_env(char *env_var, char *val, t_data *data)
{
	char		**envp;
	int			pos;
	char		*new_env;
	char		*tmp;

	if (!data || !data->envp || !env_var || !val)
		return (set_get_exit_status(data, 2));
	envp = data->envp;
	new_env = ft_strjoin(env_var, "=");
	new_env = concat_with_free(new_env, val);
	if (!new_env)
		return (set_get_exit_status(data, 2));
	pos = get_env_var_pos_by_name(env_var, envp);
	tmp = envp[pos];
	envp[pos] = new_env;
	free(tmp);
	return (set_get_exit_status(data, 0));
}

int	add_env(char *env_var, char *val, t_data *data)
{
	char	**envp_new;
	char	**envp;
	int		env_pos;
	int		len;
	char	*new_env;

	if (!data || !data->envp || !env_var || !val)
		return (set_get_exit_status(data, 2));
	envp = data->envp;
	new_env = ft_strjoin(env_var, "=");
	if ('\0' != val[0])
		new_env = concat_with_free(new_env, val);
	if (!new_env)
		return (set_get_exit_status(data, 2));
	envp_new = extend_ch_pp(envp);
	if (!envp_new)
		return (set_get_exit_status(data, 2));
	len = envp_len(envp_new) + 1;
	if (len >= 2)
		envp_new[len - 2] = new_env;
	data->envp = envp_new;
	return (set_get_exit_status(data, 0));
}

char	**extend_ch_pp(char **ch_pp)
{
	char	**envp_new;
	int		i;
	int		cnt;

	cnt = 0;
	cnt = envp_len(ch_pp);
	envp_new = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!envp_new)
	{
		perror("envp_new");
		return (NULL);
	}
	i = 0;
	while (i < cnt - 1)
	{
		envp_new[i] = ft_strdup(ch_pp[i]);
		++i;
	}
	envp_new[cnt - 1] = NULL;
	envp_new[cnt] = NULL;
	ft_free(ch_pp, envp_len(ch_pp));
	return (envp_new);
}

// alter for built-in getenv
char	*get_env(char *env_var, char **envp)
{
	int		env_pos;
	int		len;
	char	*tmp;
	char	*val;

	if (!envp || !env_var)
		return (NULL);
	env_pos = get_env_var_pos_by_name(env_var, envp);
	if (-1 != env_pos)
	{
		len = ft_strlen(envp[env_pos]) - (ft_strlen(env_var) + 1);
		val = (char *)malloc(sizeof(char) * (len + 1));
		if (!val)
		{
			perror("get var");
			return (NULL);
		}
		val = ft_strdup(envp[env_pos] + ft_strlen(env_var) + 1);
		return (val);
	}
	ft_putstr_fd("There is no such var\n", 2);
	return (NULL);
}
