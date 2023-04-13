/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:02:42 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 23:18:47 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while ((src[i] != '\0') && (i < dstsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (dstsize != 0)
		dest[i] = '\0';
	return ((size_t)ft_strlen((char *)src));
}
