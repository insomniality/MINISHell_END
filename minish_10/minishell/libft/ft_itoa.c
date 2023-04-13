/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:26:11 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 22:20:09 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*asc;
	int		dig;
	int		bkt;

	bkt = n;
	dig = 0;
	if (n != 0)
		while (n != 0 && ++dig)
			n /= 10;
	else
		dig = 1;
	n = bkt;
	asc = malloc(sizeof(char) * dig + (1 + (!(n >= 0))));
	if (!asc)
		return (NULL);
	asc[dig + !(n >= 0)] = '\0';
	if (n < 0)
		asc[0] = '-';
	while (dig-- != 0)
	{
		asc[dig + !(n >= 0)] = (n % 10) * -(!(n >= 0) - (!(n >= 0) == 0)) + 48;
		n /= 10;
	}
	return (asc);
}
