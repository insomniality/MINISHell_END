/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:03:46 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/10 19:42:03 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/errno.h>
#include "../inc/builtins.h"
#include "../libft/libft.h"

int	set_get_exit_status(t_data *data, int exit_status)
{
	if (!data)
	{
		ft_putstr_fd("NULL pointer\n", 2);
		return (1);
	}
	else
	{
		data->exit_status = exit_status;
	}
	return (data->exit_status);
}

static int	cd_helper(const char *new_path, t_data *data)
{
	char	*buf;
	char	*old_path;

	buf = NULL;
	old_path = get_env("PWD", data->envp);
	if (!old_path)
	{
		ft_putstr_fd("cd: NULL pointer", 2);
		free(old_path);
		return (set_get_exit_status(data, 1));
	}
	if ((new_path && 0 != chdir(new_path)) || \
		(!new_path && 0 != chdir(get_env("HOME", data->envp))))
	{
		perror("cd");
		free(old_path);
		return (set_get_exit_status(data, errno));
	}
	update_env("PWD", getcwd(buf, 1), data);
	update_env("OLDPWD", old_path, data);
	free(buf);
	free(old_path);
	return (set_get_exit_status(data, 0));
}

int	cd(char **new_path, t_data *data)
{
	int	len;

	if (!new_path || !data)
	{
		ft_putstr_fd("cd: NULL pointer", 2);
		return (1);
	}
	len = 0;
	while (new_path[len])
		++len;
	data->exit_status = 1;
	if (1 < len)
		ft_putstr_fd("cd: too many arguments\n", 2);
	if (0 == len)
		cd_helper(NULL, data);
	if (1 == len)
	{
		if ('~' == new_path[0][0])
			cd_helper(NULL, data);
		else
			cd_helper(new_path[0], data);
	}
	return (data->exit_status);
}

//static void	fill_env(char **envp, t_data *data)
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
//}

//int main(int argc, char **argv, char **envp)
//{
//	t_data	*data;
//	data = (t_data *)malloc(sizeof(t_data));
//	fill_env(envp, data);
//	//env(data->envp);
//	printf("\n----------------- MAIN cd 1 ---------------------\n");
//	char *s[] = {"..", NULL};
//	cd(s, data);
//	env(data);
////	printf("\n----------------- MAIN cd 2 ---------------------\n");
////	cd ("", data);
////	env(data->envp);
//	return (0);
//}
