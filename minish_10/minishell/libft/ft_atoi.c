/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:57:13 by mikarzum          #+#    #+#             */
/*   Updated: 2022/09/24 20:49:29 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	spaces(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	return (i);
}

int	digts(const char *str, int i)
{
	int	dif;

	dif = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		dif++;
	}
	return (dif);
}

size_t	pw(int n, int pw)
{
	size_t	x;

	x = n;
	if (pw == 0)
		return (1);
	while (pw - 1 != 0)
	{
		x *= 10;
		pw--;
	}
	return ((size_t)(x / 10));
}

int	j_cnt(const char *str)
{
	int	i;

	i = spaces(str);
	if (str[i] == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	ret;
	int	i;
	int	dif;
	int	z;

	ret = 0;
	i = spaces(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] == '0')
		i++;
	dif = digts(str, i);
	z = 0;
	while (dif != 0)
	{
		ret += (str[i + z] - 48) * (int)pw(10, dif);
		dif--;
		z++;
	}
	return (ret * j_cnt(str));
}
