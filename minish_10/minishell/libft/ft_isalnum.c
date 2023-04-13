/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:21:45 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 22:10:38 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int aln)
{
	if (ft_isalpha(aln) == 1 || ft_isdigit(aln) == 1)
		return (1);
	return (0);
}
