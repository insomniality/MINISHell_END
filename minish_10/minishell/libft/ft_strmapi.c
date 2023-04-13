/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:15:04 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/15 00:43:15 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{	
	int		i;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	new = (char *)malloc(sizeof(char) * i + 1);
	if (!new)
		return (NULL);
	new[i] = '\0';
	while (i-- != 0)
		new[i] = (*f)(i, s[i]);
	return (new);
}
