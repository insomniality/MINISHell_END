/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:22:06 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/20 23:09:59 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	pieces(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		if (s[i] != c)
			i++;
		else if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
	}
	if (i != 1)
	{
		if (!(s[--i] == c))
			j++;
		if (s[0] == c)
			j--;
	}
	return (j);
}

int	sp1(char const *s, int *x, char c)
{
	while (s[x[0]] && x[0] - x[1] == 0 && s[x[0]] == c)
	{
		x[0]++;
		x[1]++;
	}
	return (x[1]);
}

int	sp2(char const *s, int *x, char c)
{
	while (s[x[0]] != c && s[x[0]])
		x[0]++;
	return (x[0]);
}

void	motor(char const *s, char c, char **ddy, int *x)
{
	while ((x[0] <= ft_strlen((char *)s)) && ft_strlen(s) != 0)
	{
		if (s[x[0]] == c || !(s[x[0]]))
		{
			x[1] = sp1(s, x, c);
			if (!(!(s[x[0]]) && s[x[0] - 1] == c))
			{
				x[0] = sp2(s, x, c);
				ddy[x[2]++] = ft_substr(s, x[1], x[0] - x[1]);
				x[1] = x[0] + 1;
			}
		}
		x[0]++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**ddy;
	int				x[3];

	if (!s)
		return (NULL);
	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	if (ft_strlen(s) == 0)
	{
		ddy = (char **)malloc(sizeof(char *) * 1);
		ddy[0] = NULL;
		return (ddy);
	}
	ddy = (char **)malloc(sizeof(char *) * ((pieces(s, c) + 1)));
	if (!ddy)
	{
		free(ddy);
		return (NULL);
	}
	motor(s, c, ddy, x);
	ddy[x[2]] = NULL;
	return (ddy);
}
