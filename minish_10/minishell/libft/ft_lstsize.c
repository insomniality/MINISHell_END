/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:25:04 by mikarzum          #+#    #+#             */
/*   Updated: 2022/08/11 19:59:00 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;
	
	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

//or

// {
// 	static int	i = 0;

// 	if (lst->next != '\0')
// 	{
// 		i++;
// 		ft_lstsize(lst->next);
// 	}
// 	if (lst->next == '\0')
// 		return (i);
// 	return (0);
// }