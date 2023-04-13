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

char	*nxt_pipe(char *str)
{
	int		i;
	char	a;

	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (a == '\'' || a == '\"')
		{
			i++;
			while (str[i] && str[i] != a)
				i++;
		}
		else if (str[i] == '|')
			break ;
		i++;
	}
	return (&(str[i]));
}

void	m_pipe_p2(int pipn, char **txt, char **txt2, char ***m_argv)
{
	int	i;
	int	j;

	j = 0;
	while (j <= pipn)
	{
		m_pipe_p2_1(txt, txt2);
		i = 0;
		while (!c_check((*txt2), i, " 	") && (*txt2)[i])
			i++;
		if ((*txt2)[i] == '\0')
			(*m_argv) = split_fk((*txt2), " 	");
		else
			(*m_argv) = split2((*txt2), " 	", j);
		free((*txt2));
		lowerc(&(*m_argv));
		t_glob->t_cmnds[j].cmd = (*m_argv);
		if (j++ != pipn)
		{
			(*txt2) = (*txt);
			(*txt) = ft_strdup(nxt_pipe(*txt) + 1);
			free((*txt2));
		}
		(*m_argv) = NULL;
	}
}

void	m_pipe_p1(int pipn, char **txt, char **txt2, int ***fd)
{
	int	i;

	t_glob->t_cmnds = (t_cmds *)malloc(sizeof(t_cmds) * (pipn + 1));
	i = 0;
	while (i <= pipn)
	{
		t_glob->t_cmnds[i].inp = 0;
		t_glob->t_cmnds[i++].out = 1;
	}
	(*txt2) = pipfin((*txt));
	free((*txt));
	(*txt) = (*txt2);
	i = 0;
	(*fd) = malloc(sizeof(int *) * (pipn + 1));
	(*fd)[pipn] = NULL;
	while (i < pipn)
	{
		(*fd)[i] = (int *)malloc(sizeof(int) * 2);
		pipe((*fd)[i++]);
	}
}

void	*m_pipe(int pipn, char *txt)
{
	int		j;
	char	*txt2;
	int		*pid;
	int		**fd;
	char	**m_argv;

	m_pipe_p1(pipn, &txt, &txt2, &fd);
	pid = malloc(sizeof(int) * (pipn + 1));
	m_pipe_p2(pipn, &txt, &txt2, &m_argv);
	j = 0;
	while (j <= pipn)
	{
		pid[j] = fork();
		if (pid[j] == 0)
		{
			m_pipe_p3_f1(pipn, &j, &fd);
			m_pipe_p3_f2(pipn, &j);
		}
		free_ar((void **)t_glob->t_cmnds[j++].cmd);
	}
	m_pipe_p4_c1(pipn, &fd);
	m_pipe_p5_fr1(pipn, &fd, &txt, &pid);
	return (NULL);
}
