/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:03:46 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/13 05:06:17 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/builtins.h"
#include "../libft/libft.h"

int	export_to_env_helper(char *text, t_data *data)
{
	char	**envp;
	char	*var_name;
	char	*var_val;
	int		pos;

	envp = data->envp;
	pos = equal_sign_pos(text);
	var_name = (char *)malloc(sizeof(char) * (pos + 1));
	var_val = (char *)malloc(sizeof(char) * (ft_strlen(text) - pos));
	if (!var_name && !var_val)
	{
		perror("export: malloc error");
		return (set_get_exit_status(data, 2));
	}
	var_name = ft_memcpy(var_name, text, pos);
	var_name[pos] = '\0';
	var_val = ft_memcpy(var_val, text + pos + 1, ft_strlen(text) - pos);
	if (-1 != get_env_var_pos_by_name(var_name, envp))
		update_env(var_name, var_val, data);
	else
		add_env(var_name, var_val, data);
	free(var_name);
	free(var_val);
	return (set_get_exit_status(data, data->exit_status));
}

int	export_to_export_helper(char *text, t_data *data)
{
	char	*var_name;
	char	*var_val;
	int		pos;

	pos = equal_sign_pos(text);
	if (-1 == pos)
	{
		var_name = ft_strdup(text);
		var_val = ft_strdup("");
	}
	else
	{
		var_name = (char *)malloc(sizeof(char) * (pos + 1));
		var_name = ft_memcpy(var_name, text, pos);
		var_val = ft_strdup(text + pos + 1);
	}
	if (-1 != pos)
		var_name[pos] = '\0';
	if (-1 == get_export_var_pos_by_name(var_name, data->exportp))
		add_var_to_export(var_name, var_val, data);
	else if (is_valid_export_arg_for_env(text))
		update_export(var_name, var_val, data);
	free(var_name);
	free(var_val);
	return (set_get_exit_status(data, data->exit_status));
}

int	export(char **text, t_data *data)
{
	int		i;

	if (!data || !text)
		return (set_get_exit_status(data, 2));
	if (NULL == text[0])
		print_export((const char **)data->exportp);
	i = -1;
	data->exit_status = 0;
	while (text[++i])
	{
		if (!is_valid_export_arg_for_env(text[i]) && \
				!is_valid_export_arg_for_export(text[i]))
		{
			ft_putstr_fd("export: Not a valid identifier\n", 2);
			data->exit_status = 1;
		}
		else
		{
			if (is_valid_export_arg_for_env(text[i]))
				export_to_env_helper(text[i], data);
			export_to_export_helper(text[i], data);
		}
	}
	return (data->exit_status);
}
//
//void	fill_env(char **envp, t_data *data)
//{
//	int	i;
//	int	cnt;
//
//	cnt = 0;
//	while (envp && envp[cnt])
//		++cnt;
//	data->envp = (char **)malloc(sizeof(char *) * (cnt + 1));
//	if (!data->envp)
//	{
//		perror("data->env");
//		return ;
//	}
//	i = 0;
//	while (i < cnt)
//	{
//		data->envp[i] = ft_strdup(envp[i]);
//		++i;
//	}
//	data->envp[cnt] = NULL;
//	data->exit_status = 0;
//}
//
//void	fill_exportp(t_data *data)
//{
//	char	*tmp;
//	int		i;
//	int		len;
//	int		pos;
//
//	len = envp_len(data->envp);
//	data->exportp = (char **)malloc(sizeof(char *) * (len - 1));
//	if (!data->exportp)
//	{
//		perror("data->env");
//		return ;
//	}
//	i = 0;
//	while (i < len - 2)
//	{
//		data->exportp[i] = concat_with_free(get_env_name(data->envp[i]), "=\"");
//		tmp = get_env_val(data->envp[i]);
//		data->exportp[i] = concat_with_free(data->exportp[i], tmp);
//		free(tmp);
//		data->exportp[i] = concat_with_free(data->exportp[i], "\"");
//		++i;
//	}
//	data->exportp[len - 1] = NULL;
//	data->exit_status = 0;
//}
//
//int main(int argc, char **argv, char **envp)
//{
//	t_data	*data;
//
//	char **p = (char **)malloc(sizeof(char *) * 6);
//	p[5] = NULL;
//	p[0] = ft_strdup("a=12345");
//	p[1] = ft_strdup("mm=45");
//	p[2] = ft_strdup("a=yutytyt45");
//	p[4] = ft_strdup("ba");
//	p[3] = ft_strdup("mmm=yutytyt45");
//	//char **p = (char **)malloc(sizeof(char *) * 1);
//	//p[0] = NULL;
//	char *s[] = {"a", "mm", "lll",  NULL};
//	//char *s2[] = {"a=kjjk12356", "a=131313", NULL};
//	//char *s[] = {"56", NULL};
//	//char *s[] = {NULL};
//
//	data = (t_data *)malloc(sizeof(t_data));
//	data->exit_status = 0;
//	fill_env(envp, data);
//	printf("\n--------env------------------------------\n");
//	//env(data);
//	printf("\n-----------export---------------------------\n");
//	fill_exportp(data);
//	//print_export((const char **)data->exportp);
//	printf("\n----------------- MAIN export1 ---------------------\n");
//	export(p, data);
//	print_export((const char **)data->exportp);
//	env(data);
//	unset(s, data);
//	print_export((const char **)data->exportp);
//	//env(data);
//	//printf("\n\n----------------- MAIN export2 --------------------\n");
//	//export(s2, data);
//	//env(data);
//	ft_free(p, envp_len(p));
//	ft_free(data->envp, envp_len(data->envp));
//	ft_free(data->exportp, envp_len(data->exportp));
//	free(data);
//
//	while (1)
//	{
//	}
//	return (0);
//}
