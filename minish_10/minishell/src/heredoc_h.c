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
#include <readline/readline.h>
#include <readline/history.h>

void	child(char *delimiter, int fd[2], int has_quotes)
{
	char	*line;

	heredoc_signals();
	close(fd[0]);
	delimiter = remove_quotes(new_size(delimiter), delimiter);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strlen(line) == 0)
			continue ;
		if (!has_quotes)
			line = replace(line, 1);
		if (!ft_strncmp(delimiter, line, ft_strlen(line)))
			break ;
		if (ft_strlen(line) != 0)
			ft_putendl_fd(line, fd[1]);
	}
	close(fd[1]);
	exit (0);
}

int	has_quotes(char	*delimiter)
{
	int	i;

	i = 0;
	while (delimiter[i] != '\0')
	{
		if (delimiter[i] == '\'' || delimiter[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int	wait_for_heredoc(int pid)
{
	int	status;
	int	signaled;

	status = 0;
	wait(&status);
	signaled = WEXITSTATUS(status);
	if (signaled)
		ft_putstr_fd("\n", 1);
	t_glob->exit_status = signaled;
	if (signaled)
		return (1);
	else
		return (0);
}

int	heredoc(char *delimiter)
{
	int		fd[2];
	int		success;
	int		quotes;
	pid_t	pid;
	int		signaled;

	quotes = has_quotes(delimiter);
	success = pipe(fd);
	ignore_signals();
	pid = fork();
	if (pid < 0 || success == -1)
		ft_putendl_fd("can't fork\n", 2);
	else if (pid == 0)
		child(delimiter, fd, quotes);
	signaled = wait_for_heredoc(pid);
	define_signals();
	close (fd[1]);
	if (signaled)
	{
		close (fd[0]);
		return (-2);
	}
	return (fd[0]);
}
