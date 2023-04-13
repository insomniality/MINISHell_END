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

int	_sp1(char const *s, int *x, char *c)
{
	while (s[x[0]] && (x[0] - x[1] == 0) && c_check(s, x[0], c))
	{
		x[0]++;
		x[1]++;
	}
	return (x[1]);
}

int	_sp2(char const *s, int *x, char *c)
{
	while (s[x[0]] && !(c_check(s, x[0], c)))
	{
		while (s[x[0]] && !(c_check(s, x[0], c))
			&& s[x[0]] != '\'' && s[x[0]] != '\"')
			x[0]++;
		if (s[x[0]] == '\'')
		{
			x[0]++;
			while (s[x[0]] && s[x[0]] != '\'')
				x[0]++;
			x[0]++;
		}
		else if (s[x[0]] == '\"')
		{
			x[0]++;
			while (s[x[0]] && s[x[0]] != '\"')
				x[0]++;
			x[0]++;
		}
	}
	return (x[0]);
}

void	_motor(char const *s, char **ddy, int *x, int cmdi)
{
	while (s[x[0]] && (x[0] <= ft_strlen((char *)s))
		&& (ft_strlen(s) != 0 || (!s[x[0]] && x[0] != x[1])))
	{
			x[1] = _sp1(s, x, " 	");
		if (!(!(s[x[0]]) && c_check(s, x[0] - 1, " 	")))
		{
			if (s[x[1]] == '>' || s[x[1]] == '<')
				redir(s, " 	", x, cmdi);
			x[0] = _sp2(s, x, " 	");
			if (s[x[1]] != '>' && s[x[1]] != '<')
				ddy[x[2]++] = annihilator(s, x, " 	");
			x[1] = x[0] + 1;
		}
		x[0]++;
	}
}

char	**split2(char const *s, char *c, int cmdi)
{
	char			**ddy;
	int				x[3];

	if (!s || !qt_check(s) || ft_strlen(s) == 0)
	{
		ddy = (char **)malloc(sizeof(char *) * 1);
		ddy[0] = NULL;
		return (ddy);
	}
	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	ddy = (char **)malloc(sizeof(char *) * ((_pieces(s, c) + 1)));
	_motor(s, ddy, x, cmdi);
	ddy[x[2]] = NULL;
	x[0] = 0;
	return (ddy);
}
