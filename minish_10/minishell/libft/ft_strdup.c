/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:37:11 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 22:44:59 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		n;

	n = 0;
	while (s1[n])
		n++;
	str = (char *)malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[n] = '\0';
	while (n != 0)
	{
		--n;
		str[n] = s1[n];
	}
	return (str);
}
