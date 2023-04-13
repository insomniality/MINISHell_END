/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:11:08 by mikarzum          #+#    #+#             */
/*   Updated: 2022/08/11 21:41:22 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list *ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
 		lst = lst->next;
	return (lst);
}
// int main()
// {
// 	t_list *a = malloc(sizeof(t_list));
// 	a->next = NULL;

// 	t_list *b = malloc(sizeof(t_list));
// 	b->next = a;

// 	printf("%p\n", ft_lstlast(b));
// }