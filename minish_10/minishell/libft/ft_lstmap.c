/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:43:23 by mikarzum          #+#    #+#             */
/*   Updated: 2022/08/11 19:59:44 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nlst;
	t_list	*ntmp;
	t_list	*nhom;
	
	tmp = lst;
	nhom = (t_list *)malloc(sizeof(t_list));
	if (!nhom)
		return (NULL);
	nhom->content = (*f)(tmp->content);
	ntmp = nhom;
	while (tmp)
	{
		nlst = (t_list *)malloc(sizeof(t_list));
		if (!nlst)
		{	
			ntmp = nhom;
			while (ntmp->next) // kam menak ntmp
			{
				(*del)(ntmp->content);
				ntmp = ntmp->next;
				free(ntmp);
			}
			return (NULL);
		}
		nlst->content = (*f)(tmp->content);
		ntmp->next = nlst;
		ntmp = nlst;
		tmp = tmp->next;
	}
	nlst->content = (*f)(tmp->content);
	nlst->next = NULL;
	return (nhom);
}
