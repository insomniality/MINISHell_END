/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:19:27 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/15 18:54:48 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if ((char)c == '\0')
	{
		return ((char *)s + i);
	}
	if (s[i] == (char)c)
	{
		// printf("puk =>%c; =>%s\n", s[i], s);
		return ((char *)&s[i]);
	}
	return (NULL);
}
