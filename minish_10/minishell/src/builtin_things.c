/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:01:05 by mikarzum          #+#    #+#             */
/*   Updated: 2023/02/10 19:01:10 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pastoren "" es haskanum ei vorpes arandzin argument

#include "../libft/libft.h"
#include "src.h"

int	l(char *s)
{
	return (ft_strlen(s));
}

void	builtin_exec(char *s, char **arg, t_data *data)
{
	char	**dup;
	int		i;

	dup = get_argv(arg);
	if (ft_memcmp(s, "echo", l("echo")) == 0 && l(s) == l("echo"))
		echo(dup, data);
	else if (ft_memcmp(s, "cd", l("cd")) == 0 && l(s) == l("cd"))
		cd(dup, data);
	else if (ft_memcmp(s, "pwd", l("pwd")) == 0 && l(s) == l("pwd"))
		pwd(data);
	else if (ft_memcmp(s, "export", l("export")) == 0 && l(s) == l("export"))
		export(dup, data);
	else if (ft_memcmp(s, "unset", l("unset")) == 0 && l(s) == l("unset"))
		unset(dup, data);
	else if (ft_memcmp(s, "env", l("env")) == 0 && l(s) == l("env"))
		env(data);
	else if (ft_memcmp(s, "exit", l("exit")) == 0 && l(s) == l("exit"))
	{
		i = exit_for_prj(dup, data);
		free_ar((void **)dup);
		exit(i);
	}
	free_ar((void **)dup);
}

int	is_builtin(char *s, char *arg, t_data *data)
{
	int	i;

	i = 0;
	if (ft_memcmp(s, "echo", l("echo")) == 0 && l(s) == l("echo"))
		i = 1;
	else if (ft_memcmp(s, "cd", l("cd")) == 0 && l(s) == l("cd"))
		i = 1;
	else if (ft_memcmp(s, "pwd", l("pwd")) == 0 && l(s) == l("pwd"))
		i = 1;
	else if (ft_memcmp(s, "export", l("export")) == 0 && l(s) == l("export"))
		i = 1;
	else if (ft_memcmp(s, "unset", l("unset")) == 0 && l(s) == l("unset"))
		i = 1;
	else if (ft_memcmp(s, "env", l("env")) == 0 && l(s) == l("env"))
		i = 1;
	else if (ft_memcmp(s, "exit", l("exit")) == 0 && l(s) == l("exit"))
		i = 1;
	return (i);
}
