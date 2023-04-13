/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:43:50 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/05 21:15:33 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/builtins.h"

void	fill_env(char **envp, t_data **data)
{
	int	i;
	int	cnt;

	cnt = 0;
	while (envp && envp[cnt])
		++cnt;
	(*data)->envp = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!(*data)->envp)
	{
		perror("data->env");
		return ;
	}
	i = 0;
	while (i < cnt)
	{
		(*data)->envp[i] = ft_strdup(envp[i]);
		++i;
	}
	(*data)->envp[cnt] = NULL;
}

char	**get_argv(char **argv)
{
	int		i;
	int		cnt;
	char	**n_argv;

	cnt = 0;
	while (argv && argv[cnt])
		++cnt;
	n_argv = (char **)malloc(sizeof(char *) * cnt);
	if (!n_argv)
		return (NULL);
	i = 1;
	while (i < cnt)
	{
		n_argv[i - 1] = ft_strdup(argv[i]);
		++i;
	}
	n_argv[cnt - 1] = NULL;
	return (n_argv);
}

static void	fill_exportp(t_data *data)
{
	char	**envp;
	int		i;
	int		len;
	int		pos;

	envp = data->envp;
	len = envp_len(envp);
	data->exportp = (char **)malloc(sizeof(char *) * (len - 1));
	if (!data->exportp)
	{
		perror("data->env");
		return ;
	}
	i = 0;
	while (i < len - 2)
	{
		data->exportp[i] = ft_strjoin(get_env_name(envp[i]), "=\"");
		data->exportp[i] = ft_strjoin(data->exportp[i], get_env_val(envp[i]));
		data->exportp[i] = ft_strjoin(data->exportp[i], "\"");
		++i;
	}
	data->envp[len - 1] = NULL;
}

//int	main(int argc, char **argv, char **envp)
//{
//	t_data	*data;
//
//	data = (t_data *)malloc(sizeof(t_data));
//	data->exit_status = 0;
//	fill_env(envp, data);
//	env(data);
//	fill_exportp(data);
//	printf("\n--------------------------------------\n");
//	print_export((const char **)data->exportp);
//	return (0);
//}
