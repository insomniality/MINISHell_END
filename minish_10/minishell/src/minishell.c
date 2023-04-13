/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:01:05 by mikarzum          #+#    #+#             */
/*   Updated: 2023/02/10 19:01:10 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../inc/builtins.h"
#include <termios.h>
#include "../libft/libft.h"
#include "../inc/builtins.h"
#include "src.h"

char	**split_fk(char *txt, char *c)
{
	char	**a;
	int		x[2];

	if (!txt || !qt_check(txt) || ft_strlen(txt) == 0)
	{
		a = (char **)malloc(sizeof(char *) * 1);
		a[0] = NULL;
		return (a);
	}
	x[1] = 0;
	x[0] = ft_strlen(txt);
	a = (char **)malloc(sizeof(char *) * 2);
	a[0] = annihilator(txt, x, c);
	a[1] = NULL;
	return (a);
}

void	main_while(void)
{
	char	*txt;

	while (1)
	{
		txt = readline("minishell ");
		if (!txt)
			break ;
		if (validornot(txt) == 0)
		{
			free(txt);
			continue ;
		}
		add_history(txt);
		if (ispipe(txt))
		{
			m_pipe(ft_chrcnt(txt, '|'), txt);
			continue ;
		}
		main2(txt);
		free(txt);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_glob = (t_data *)malloc(sizeof(t_data));
	t_glob->exit_status = 0;
	fill_env(envp, &t_glob);
	define_signals();
	main_while();
	free_ar((void **)t_glob->envp);
	free(t_glob);
}
