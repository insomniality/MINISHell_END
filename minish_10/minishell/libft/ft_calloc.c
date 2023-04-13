/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:25:31 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/21 00:52:39 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	prod;

	prod = count * size;
	mem = (void *)malloc(prod);
	if (!mem)
		return (NULL);
	ft_bzero(mem, prod);
	return (mem);
}
