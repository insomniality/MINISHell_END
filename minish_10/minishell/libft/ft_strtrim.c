/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:00:40 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 23:31:17 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_char_find_from_left(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j] && s1[i])
		{
			j = 0;
			i++;
			continue ;
		}
		if (!(set[j]))
			j = 0;
		j++;
	}
	if (!(s1[i]))
		return (0);
	return (i);
}

int	my_char_find_from_right(char const *s1, char const *set, int end)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
		i++;
	i--;
	j = 0;
	while (s1[i] && set[j] && i != end)
	{
		if (s1[i] == set[j] && s1[i])
		{
			j = 0;
			i--;
			continue ;
		}
		j++;
		if (set[j] == '\0')
			break ;
	}
	if (!i)
		return (0);
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		x;
	int		y;
	char	*trm;
	int		i;

	if (!s1 || !set)
		return (0);
	x = my_char_find_from_left(s1, set);
	y = my_char_find_from_right(s1, set, x);
	trm = malloc(y - x + 1);
	if (!trm)
		return (NULL);
	i = 0;
	while (i < y - x)
	{
		trm[i] = s1[x + i];
		i++;
	}
	trm[i] = '\0';
	return (trm);
}
