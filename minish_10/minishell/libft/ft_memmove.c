/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:35:49 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 22:42:47 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (src < dst)
	{
		while (i < len)
		{
			ft_memset(dst + len - 1 - i, *(const char *)(src + len - 1 - i), 1);
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		ft_memset(dst + i, *(const char *)(src + i), 1);
		i++;
	}
	return (dst);
}
