/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:14:30 by mikarzum          #+#    #+#             */
/*   Updated: 2022/08/11 22:11:53 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
	tmp = ft_lstlast(*lst);
	if (!tmp)
	{
		*lst = new;
		new->next = NULL;
	}
	else if (new)
		tmp->next = new;
}

// int main()
// {
// 	t_list **home = malloc(sizeof(t_list));
// 	t_list *a = malloc(sizeof(t_list));
// 	t_list *b = malloc(sizeof(t_list));
// 	(*home)->next = a;
// 	a->next = b;
// 	b->next = NULL;

// 	ft_lstadd_back(home, ft_lstnew((void*)1));
// 	printf("%p\n", b->next);
// }