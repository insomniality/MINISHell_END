/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:17:18 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/10 19:37:41 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/builtins.h"
#include "../libft/libft.h"

int	env(t_data *data)
{
	char	**envp;
	int		i;

	if (!data)
	{
		ft_putstr_fd("env: NULL pointer", 2);
		return (1);
	}
	envp = data->envp;
	data->exit_status = 1;
	i = 0;
	if (envp)
	{
		while (envp[i])
		{
			printf("%s\n", envp[i]);
			++i;
		}
		data->exit_status = 0;
	}
	return (data->exit_status);
}
