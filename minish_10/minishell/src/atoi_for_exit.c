/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:17:16 by mavardan          #+#    #+#             */
/*   Updated: 2022/11/23 15:40:44 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../libft/libft.h"

static int	is_leading_0s(const char *s)
{
	int	sign;
	int	i;

	sign = 1;
	if (!s)
		return (0);
	i = 0;
	if ('-' == s[i])
	{
		sign = -1;
		++i;
	}
	if ((-1 == sign && '0' == s[i]) || \
		('0' == s[i] && 1 != ft_strlen(s + i)))
	{
		ft_putstr_fd("exit: Leading 0. Numeric argument required\n", 2);
		return (1);
	}
	return (0);
}

static int	is_numeric(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if ('-' == s[i])
	{
		if (1 == ft_strlen(s))
		{
			ft_putstr_fd("exit: Numeric argument required\n", 2);
			return (0);
		}
		i++;
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			ft_putstr_fd("exit: Numeric argument required\n", 2);
			return (0);
		}
		++i;
	}
	return (1);
}

unsigned char	convert_to_num_for_exit(const char *str)
{
	long long	res;
	int			i;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	while (str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((unsigned char)(sign * res));
}

// len of LLONG_MAX, LLONG_MIN is 19, e.g. if > 20 (1 for sign) => Error
int	is_valid_num_for_exit(const char *str)
{
	unsigned long long	res;
	int					i;
	int					sign;

	if (!str || !is_numeric(str) || is_leading_0s(str))
		return (0);
	i = 0;
	sign = 1;
	if ('-' == str[i] && (++i))
		sign = -1;
	if (19 < ft_strlen(str + i))
	{
		ft_putstr_fd("exit: Numeric argument required\n", 2);
		return (0);
	}
	res = 0;
	while (str[i] != '\0')
		res = res * 10 + str[i++] - '0';
	if ((1 == sign && LLONG_MAX < res) || \
			(-1 == sign && ((unsigned long long)LLONG_MAX + 1 < res)))
	{
		ft_putstr_fd("exit: Numeric argument required\n", 2);
		return (0);
	}
	return (1);
}
