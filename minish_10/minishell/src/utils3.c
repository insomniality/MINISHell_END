/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:17:18 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/05 21:13:19 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../inc/builtins.h"

// ptrn is env var name, s is a full row
int	is_var_in_env(const char *s, const char *ptrn)
{
	int	i;

	if (!s || !ptrn)
		return (0);
	i = 0;
	while (ptrn[i] && s[i])
	{
		if (s[i] != ptrn[i])
			return (0);
		++i;
	}
	if ('=' == s[i] && '\0' == ptrn[i])
		return (1);
	return (0);
}

int	equal_sign_pos(char *text)
{
	int	pos;

	if (!text)
		return (-1);
	pos = 0;
	while (text[pos])
	{
		if ('=' == text[pos])
		{
			return (pos);
		}
		++pos;
	}
	return (-1);
}
