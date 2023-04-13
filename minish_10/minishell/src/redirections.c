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

void	redir_p2_less(char const *s, char *fname, int *x, int cmdi)
{
	if (s[x[1]] != '\0' && s[x[1]] == '<' && s[x[1] + 1] != '<')
	{
		if (t_glob->t_cmnds[cmdi].inp != 0)
			close(t_glob->t_cmnds[cmdi].inp);
		t_glob->t_cmnds[cmdi].inp = open(fname, O_RDONLY, 0644);
	}
	if (s[x[1]] != '\0' && s[x[1]] == '<' && s[x[1] + 1] == '<')
	{
		if (t_glob->t_cmnds[cmdi].inp != 0)
			close(t_glob->t_cmnds[cmdi].inp);
		t_glob->t_cmnds[cmdi].inp = heredoc(fname);
	}	
}

void	redir_p2_more(char const *s, char *fname, int *x, int cmdi)
{
	if (s[x[1]] != '\0' && s[x[1]] == '>' && s[x[1] + 1] != '>')
	{
		if (t_glob->t_cmnds[cmdi].out != 1)
			close(t_glob->t_cmnds[cmdi].out);
		t_glob->t_cmnds[cmdi].out = open(fname, \
		O_CREAT | O_TRUNC | O_WRONLY, 0644);
	}
	if (s[x[1]] != '\0' && s[x[1]] == '>' && s[x[1] + 1] == '>')
	{
		if (t_glob->t_cmnds[cmdi].out != 1)
			close(t_glob->t_cmnds[cmdi].out);
		t_glob->t_cmnds[cmdi].out = open(fname, \
		O_CREAT | O_APPEND | O_WRONLY, 0644);
	}
}

void	redir_p1(char const *s, char *c, int *x, char **fname)
{
	int		fstrt;
	int		_x[2];
	char	*fn;

	x[0] = x[1];
	x[0]++;
	if (s[x[0]] == '>' || s[x[0]] == '<')
		x[0]++;
	while (c_check(s, x[0], c))
		x[0]++;
	if (s[x[0]] == '>' || s[x[0]] == '<')
	{
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		ft_putchar_fd(s[x[0]], 2);
		ft_putstr_fd("\'\n", 2);
	}
	fstrt = x[0];
	while (s[x[0]] && !c_check(s, x[0], c))
		x[0]++;
	(*fname) = ft_substr(s, fstrt, x[0] - fstrt);
	_x[0] = ft_strlen((*fname));
	_x[1] = 0;
	fn = (*fname);
	(*fname) = annihilator(fn, _x, c);
	free(fn);
}

void	redir(char const *s, char *c, int *x, int cmdi)
{
	char	*fname;

	redir_p1(s, c, x, &fname);
	redir_p2_more(s, fname, x, cmdi);
	redir_p2_less(s, fname, x, cmdi);
	if (t_glob->t_cmnds[cmdi].inp == -1 || t_glob->t_cmnds[cmdi].out == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(fname, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	free(fname);
}
