/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:13:05 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/20 01:46:59 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print(int i, int nb, char *arr, int fd)
{
	char	ch[2];
	int		j;

	j = i;
	ch[1] = '\0';
	if (nb < 0)
	{
		arr[9 - j] = nb * -1;
	}
	else
	{
		arr[9 - j] = nb;
	}
	j++;
	while (j != 0)
	{
		ch[0] = arr[9 - j + 1] + '0';
		write(fd, &ch[0], 1);
		j--;
	}
}

void	comb(int nb, int fd)
{
	int		y;
	char	arr[10];
	int		i;
	char	*p;

	p = arr;
	i = 0;
	while (nb >= 10 || nb <= -10)
	{
		y = nb % 10;
		nb = (nb - y) / 10;
		if (nb < 0)
		{
			arr[9 - i] = y * -1;
		}
		else
		{
			arr[9 - i] = y;
		}
		i++;
	}
	print(i, nb, p, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		comb(nb, fd);
	}
	else
		comb(nb, fd);
}
