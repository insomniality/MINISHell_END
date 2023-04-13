/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:05:14 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 22:31:50 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;
	char	*temp;

	temp = (char *)ptr;
	i = 0;
	while (i < num)
	{
		temp[i] = value;
		i++;
	}
	return ((void *)ptr);
}
