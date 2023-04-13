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

int	ispipe(char *s)
{
	int		i;
	char	a;

	i = 0;
	while (s[i] && s[i] != '|')
	{
		a = s[i];
		if (a == '\'' || a == '\"')
		{
			i++;
			while (s[i] != a)
				i++;
		}
		i++;
	}
	if (s[i] && s[i] == '|')
		return (1);
	return (0);
}

int	validornot(char *txt)
{
	int		i;
	char	*a;

	if (*txt == '\0')
		return (0);
	i = 0;
	while (txt[i] == ' ' || txt[i] == '	')
		i++;
	if (txt[i] == '\0')
		return (0);
	a = pipfin(txt);
	if (a == NULL)
		return (0);
	else
		free(a);
	if (qt_check(txt) == 0)
		return (0);
	return (1);
}

void	free_ar(void **spl)
{
	int	i;

	i = 0;
	while (spl[i] != NULL)
		free(spl[i++]);
	free(spl);
}

void	lowerc(char ***m_argv)
{
	int	j;

	j = 0;
	while ((*m_argv)[0][j])
	{
		(*m_argv)[0][j] = ft_tolower((*m_argv)[0][j]);
		j++;
	}
}
