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

#include "../libft/libft.h"
#include "src.h"

void	qt_chk_tst(char const *s, int *i, int *q, char qt)
{
	(*q)++;
	(*i)++;
	if (s[(*i)] && s[(*i)] != qt)
	{
		while (s[(*i)] && s[(*i)] != qt)
			(*i)++;
		if (s[(*i)] && s[(*i)] == qt)
			(*q)++;
	}
	else if (s[(*i)] && s[(*i)] == qt)
		(*q)++;
}

int	qt_check(char const *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			qt_chk_tst(s, &i, &j, '\'');
		else if (s[i] == '\"')
			qt_chk_tst(s, &i, &k, '\"');
		if (s[i])
			i++;
	}
	if (!(j % 2 == 0 && k % 2 == 0))
	{
		ft_putstr_fd("Err; Unclosed quotes\n", 2);
		return (0);
	}
	return (1);
}

int	c_check(char const *s, int idx, char *c)
{
	int	i;

	i = 0;
	if (!s[idx])
		return (0);
	while (c[i])
	{
		if (s[idx] == c[i])
			return (1);
		i++;
	}
	return (0);
}
