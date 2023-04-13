/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:24:52 by mikarzum          #+#    #+#             */
/*   Updated: 2022/08/09 18:05:41 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*NEW;

	NEW = (t_list *)malloc(sizeof(t_list));
	NEW->content = content;
	NEW->next = NULL;

	return (NEW);
}
