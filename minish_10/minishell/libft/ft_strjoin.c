/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:42:54 by mavardan          #+#    #+#             */
/*   Updated: 2022/05/23 19:06:08 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p;

	if (NULL == s1 || NULL == s2)
	{
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *)malloc(s1_len + s2_len + 1);
	if (NULL != p)
	{
		p = (char *)ft_memcpy(p, s1, s1_len);
		p = (char *)ft_memcpy(p + s1_len, s2, s2_len) - s1_len;
		p[s1_len + s2_len] = '\0';
	}
	return (p);
}
