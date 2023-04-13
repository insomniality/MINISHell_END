/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:03:46 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/13 05:06:32 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/builtins.h"
#include "../libft/libft.h"

static int	unset_env_var(char *env_var, t_data *data)
{
	char	**envp_new;
	int		len;
	int		i;
	int		pos;
	int		j;

	pos = get_env_var_pos_by_name(env_var, data->envp);
	if (-1 == pos)
		return (set_get_exit_status(data, 1));
	len = envp_len(data->envp);
	envp_new = (char **)malloc(sizeof(char *) * (len - 1));
	i = 0;
	j = 0;
	while (i < len - 1)
	{
		if (i != pos)
			envp_new[j++] = ft_strdup(data->envp[i]);
		++i;
	}
	envp_new[len - 2] = NULL;
	ft_free(data->envp, envp_len(data->envp));
	data->envp = envp_new;
	return (set_get_exit_status(data, 0));
}

static int	unset_export_var(char *var, t_data *data)
{
	char	**exportp_new;
	int		len;
	int		i;
	int		pos;
	int		j;

	pos = get_export_var_pos_by_name(var, data->exportp);
	if (-1 == pos)
		return (set_get_exit_status(data, 1));
	len = envp_len(data->exportp);
	exportp_new = (char **)malloc(sizeof(char *) * (len - 1));
	i = 0;
	j = 0;
	while (i < len - 1)
	{
		if (i != pos)
			exportp_new[j++] = ft_strdup(data->exportp[i]);
		++i;
	}
	exportp_new[len - 2] = NULL;
	ft_free(data->exportp, envp_len(data->exportp));
	data->exportp = exportp_new;
	return (set_get_exit_status(data, 0));
}

int	unset(char **vars, t_data *data)
{
	int	i;
	int	st;

	i = 0;
	while (vars[i])
	{
		st = unset_export_var(vars[i], data);
		unset_env_var(vars[i], data);
		++i;
	}
	if (st != 0)
		data->exit_status = st;
	return (data->exit_status);
}
