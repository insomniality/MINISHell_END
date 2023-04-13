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
#include <stdio.h>

void	main2_p2_f(int out, int fblt)
{
	if (t_glob->t_cmnds[0].inp == -1 || t_glob->t_cmnds[0].out == -1)
		exit (1);
	if (t_glob->t_cmnds[0].inp != 0)
		dup2(t_glob->t_cmnds[0].inp, 0);
	if (t_glob->t_cmnds[0].out != 1)
		dup2(t_glob->t_cmnds[0].out, 1);
	if (fblt == 1)
	{
		builtin_exec(t_glob->t_cmnds->cmd[0], t_glob->t_cmnds->cmd, t_glob);
		dup2(out, 1);
	}
	search(&(t_glob->t_cmnds->cmd[0]), getenv("PATH"));
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	if (fblt == 0)
	{
		execve(t_glob->t_cmnds->cmd[0], t_glob->t_cmnds->cmd, NULL);
		exit(1);
	}
}

void	main2_p1(char *txt)
{
	int		i;
	char	*txt2;
	char	**m_argv;

	t_glob->t_cmnds = (t_cmds *)malloc(sizeof(t_cmds));
	t_glob->t_cmnds->inp = 0;
	t_glob->t_cmnds->out = 1;
	i = 0;
	while (txt != NULL && c_check(txt, i, " 	"))
		i += 1;
	txt2 = ft_substr(txt, i, i + ft_strlen(txt));
	i = 0;
	while (!c_check(txt2, i, " 	") && (txt2)[i])
		i += 1;
	if ((txt2)[i] == '\0')
		m_argv = split_fk(txt2, " 	");
	else
		m_argv = split2(txt2, " 	", 0);
	lowerc(&(m_argv));
	t_glob->t_cmnds->cmd = m_argv;
	m_argv = NULL;
	free(txt2);
}

void	main2(char *txt)
{
	pid_t	pid;
	int		fblt;
	int		out;

	out = dup(1);
	pid = 0;
	main2_p1(txt);
	fblt = is_builtin(t_glob->t_cmnds->cmd[0], t_glob->t_cmnds->cmd[1], t_glob);
	if (fblt == 0)
		pid = fork();
	if (pid == 0)
		main2_p2_f(out, fblt);
	if (t_glob->t_cmnds[0].inp != 0)
		close (t_glob->t_cmnds[0].inp);
	if (t_glob->t_cmnds[0].out != 1)
		close (t_glob->t_cmnds[0].out);
	close(out);
	free_ar((void **)t_glob->t_cmnds->cmd);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	my_waitpid(pid);
	define_signals();
	free(t_glob->t_cmnds);
}
