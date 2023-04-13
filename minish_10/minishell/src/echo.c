/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:03:46 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/04 20:46:17 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/builtins.h"
#include "../libft/libft.h"

static int	is_dash_n_set(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if ('-' != s[i++])
		return (0);
	while (s[i])
	{
		if ('n' != s[i])
			return (0);
		++i;
	}
	return (1);
}

int	echo(char **text, t_data *data)
{
	int	is_dash_n;
	int	i;

	is_dash_n = 0;
	if (!text || !text[0] || 0 == ft_strlen(text[0]))
	{
		printf("\n");
	}
	else
	{
		i = 0;
		while (text[i] && is_dash_n_set(text[i]))
		{
			is_dash_n = 1;
			++i;
		}
		while (text[i])
			printf("%s ", text[i++]);
		if (!is_dash_n)
			printf("\n");
	}
	data->exit_status = 0;
	return (data->exit_status);
}

//int main()
//{
//
//	//char *s[] = {"-n", "skjdhj  hdwgeh", "5698", NULL};
//	//char *s[] = {"skjdhj  hdwgeh", "5698", NULL};
//	char *s[] = {"-nnn", "-n", "skjdhj  hdwgeh", "-n", "5698", NULL};
//	echo (s);
//	return 0;
//}
