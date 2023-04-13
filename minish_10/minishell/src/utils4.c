/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:17:18 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/13 04:24:00 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../inc/builtins.h"

char	*concat_with_free(char *s1, char *s2)
{
	char	*new_s;

	new_s = ft_strjoin(s1, s2);
	free(s1);
	s1 = NULL;
	return (new_s);
}

int	get_export_var_pos_by_name(const char *var, char **exportp)
{
	int	i;

	i = 0;
	if (exportp)
	{
		while (exportp[i])
		{
			if (is_var_in_env(exportp[i], var) || \
					0 == ft_strncmp(var, exportp[i], ft_strlen(var)))
			{
				return (i);
			}
			++i;
		}
	}
	return (-1);
}

int	update_export(char *var, char *val, t_data *data)
{
	int			pos;
	char		*new_var;
	char		*tmp;

	if (!data || !data->exportp || !var)
		return (set_get_exit_status(data, 2));
	new_var = ft_strjoin(var, "=\"");
	new_var = concat_with_free(new_var, val);
	new_var = concat_with_free(new_var, "\"");
	if (!new_var)
		return (set_get_exit_status(data, 2));
	pos = get_export_var_pos_by_name(var, data->exportp);
	tmp = data->exportp[pos];
	data->exportp[pos] = new_var;
	free(tmp);
	return (set_get_exit_status(data, 0));
}

int	add_var_to_export(char *var, char *val, t_data *data)
{
	char	**exportp_new;
	int		pos;
	int		len;
	char	*new_var;

	if (!data || !data->exportp || !var)
		return (set_get_exit_status(data, 2));
	if ('\0' == val[0])
		new_var = ft_strdup(var);
	else
	{
		new_var = ft_strjoin(var, "=\"");
		new_var = concat_with_free(new_var, val);
		new_var = concat_with_free(new_var, "\"");
	}
	exportp_new = extend_ch_pp(data->exportp);
	if (!new_var || !exportp_new)
		return (set_get_exit_status(data, 2));
	len = envp_len(exportp_new) + 1;
	if (len >= 2)
		exportp_new[len - 2] = new_var;
	data->exportp = exportp_new;
	return (set_get_exit_status(data, 0));
}
