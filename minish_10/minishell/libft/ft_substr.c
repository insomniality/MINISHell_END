/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:53:37 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/19 22:47:23 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > (unsigned int)ft_strlen((char *)s))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	while (s[start + i] && len-- != 0)
		i++;
	sub = malloc(i + 1);
	if (!sub)
		return (NULL);
	sub[i] = '\0';
	while (i-- != 0)
		sub[i] = s[start + i];
	return (sub);
}
