/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:41:53 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/15 18:56:10 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	tms;

	i = 0;
	j = 0;
	tms = (size_t)ft_strlen((char *)dest);
	while (dest[i] && i != dstsize)
		i++;
	k = i;
	if (dstsize != 0)
	{
		while (src[j] && (j + tms + 1 < dstsize))
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	if (dstsize != 0 && !(k >= dstsize))
		dest[i] = '\0';
	if (dstsize == 0)
		k = 0;
	return ((size_t)ft_strlen((char *)src) + k);
}
