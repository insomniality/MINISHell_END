/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:01:53 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 22:33:04 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	nl;

	if (!s)
		return ;
	nl = 10;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, &nl, 1);
}
