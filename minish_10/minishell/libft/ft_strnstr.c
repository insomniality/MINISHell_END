/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:59:07 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/17 21:26:42 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && len != 0 && (size_t)i < len)
	{
		j = 0;
		while (to_find[j] && str[i + j] && !(&str[len] == &str[i + j]))
		{
			if (to_find[j] != str[i + j])
				break ;
			j++;
		}
		i++;
		if (to_find[j])
			continue ;
		else if (to_find[j] == '\0')
			return ((char *)str + i - 1);
		len--;
	}
	return (NULL);
}
