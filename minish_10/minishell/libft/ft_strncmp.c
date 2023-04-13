/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:50:29 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/19 17:23:42 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	unsigned int	i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (s11[i] == s22[i] && (s11[i] || s22[i]) && (i < n - 1))
		i++;
	if (s11[i] - s22[i] < 0)
		return (-1);
	else if (s11[i] - s22[i] > 0)
		return (1);
	else
		return (0);
}
