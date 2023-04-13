/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:01:05 by mikarzum          #+#    #+#             */
/*   Updated: 2023/02/10 19:01:10 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pastoren "" es haskanum ei vorpes arandzin argument

#include "../libft/libft.h"
#include "src.h"

char	*ft_malloc(int size)
{
	char	*str;

	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	else
		return (str);
}

char	*remove_quotes(int size, char *str)
{
	int		i;
	int		j;
	char	quote;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = ft_malloc(size);
	while (str[i] != '\0' && j < size)
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			while (str[i] != quote && str[i] != '\0')
				newstr[j++] = str[i++];
		}
		else
			newstr[j++] = str[i];
		if (str[i] != '\0')
			i++;
	}
	free(str);
	newstr[j] = '\0';
	return (newstr);
}
