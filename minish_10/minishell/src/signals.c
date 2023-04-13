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

void	my_waitpid(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		t_glob->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		t_glob->exit_status = 128 + WTERMSIG(status);
		if (t_glob->exit_status == 130)
			ft_putstr_fd("\n", 2);
		else if (t_glob->exit_status == 131)
			ft_putstr_fd("Quit: 3\n", 2);
	}
	else
		t_glob->exit_status = status;
}

void	ignore_symbols(void)
{
	struct termios	new_settings;

	if (tcgetattr(0, &new_settings))
		perror("minishell: tcsetattr");
	new_settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &new_settings))
		perror("minishell: tcsetattr");
}

void	reprompt(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	ignore_symbols();
	rl_replace_line("", 0);
	rl_redisplay();
	t_glob->exit_status = 1;
}

void	define_signals(void)
{
	signal(SIGINT, reprompt);
	signal(SIGQUIT, SIG_IGN);
}
