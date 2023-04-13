/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:58:20 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/20 03:45:08 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	cc = (unsigned char)c;
	str = (unsigned char *) s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n && *(str + i) != cc)
		i++;
	if (i < n && str[i] == cc)
		return ((void *)(str + i));
	return (NULL);
}
