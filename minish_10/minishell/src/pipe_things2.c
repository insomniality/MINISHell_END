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

void	m_pipe_p5_fr1(int pipn, int ***fd, char **txt, int **pid)
{
	int	j;

	j = 0;
	while (j < pipn + 1)
		my_waitpid((*pid)[j++]);
	define_signals();
	free((*txt));
	free((*pid));
	free_ar((void **)(*fd));
	free(t_glob->t_cmnds);
}

void	m_pipe_p4_c1(int pipn, int ***fd)
{
	int	j;

	j = 0;
	while (j < pipn)
	{
		close(((*fd)[j])[0]);
		close(((*fd)[j])[1]);
		j++;
	}
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	m_pipe_p3_f2(int pipn, int *j)
{
	if (!(is_builtin(t_glob->t_cmnds[(*j)].cmd[0], \
	t_glob->t_cmnds[(*j)].cmd[0], t_glob)))
	{
		search(&(t_glob->t_cmnds[(*j)].cmd[0]), getenv("PATH"));
		execve(t_glob->t_cmnds[(*j)].cmd[0], t_glob->t_cmnds[(*j)].cmd, 0);
	}
	else
		builtin_exec(t_glob->t_cmnds[(*j)].cmd[0], \
		t_glob->t_cmnds[(*j)].cmd, t_glob);
	exit(1);
}

void	m_pipe_p3_f1(int pipn, int *j, int ***fd)
{
	int	i;

	i = 0;
	if (t_glob->t_cmnds[(*j)].inp == -1 || t_glob->t_cmnds[(*j)].out == -1)
		exit (1);
	if (t_glob->t_cmnds[(*j)].out != 1)
		dup2(t_glob->t_cmnds[(*j)].out, STDOUT_FILENO);
	else if ((*j) != pipn)
		dup2(((*fd)[(*j)])[1], STDOUT_FILENO);
	if (t_glob->t_cmnds[(*j)].inp != 0)
		dup2(t_glob->t_cmnds[(*j)].inp, 0);
	else if ((*j) != 0)
		dup2(((*fd)[(*j) - 1])[0], STDIN_FILENO);
	i = 0;
	while (i < pipn)
	{
		close(((*fd)[i])[1]);
		close(((*fd)[i])[0]);
		i++;
	}
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

void	m_pipe_p2_1(char **txt, char **txt2)
{
	int	i;

	i = 0;
	(*txt2) = (*txt);
	if (ft_strchr((*txt), '|') != NULL)
	{
		while ((*txt2) != NULL && &((*txt2)[i]) != nxt_pipe((*txt2)))
			i++;
		(*txt2) = ft_substr((*txt2), 0, i);
	}
	else
	{
		while ((*txt2) != NULL && c_check((*txt2), i, " 	"))
			i++;
		(*txt2) = ft_substr((*txt2), i, i + ft_strlen((*txt2)));
	}
}
