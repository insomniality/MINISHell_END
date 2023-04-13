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

char	*replace_var(char *sentence, char *var, char *value, int i)
{
	char	*dest;

	dest = malloc (ft_strlen(sentence) - ft_strlen(var)
			+ ft_strlen(value) + 1);
	ft_strcpy (dest, sentence);
	if (dest + i)
	{
		ft_memmove(dest + i + ft_strlen(value), dest + i + ft_strlen(var),
			ft_strlen(dest + i + ft_strlen(var)) + 1);
		ft_strncpy (dest + i, value, ft_strlen(value));
	}
	return (dest);
}

char	*dollar(int i, char quote, char *str, int single_quote)
{
	int		j;
	char	*var;
	char	*value;
	char	*tmp;

	if (str[i] == '$' && (quote == '"' || quote == '-'
			|| single_quote == 1))
	{
		j = i;
		j++;
		while (str[j] != '\0' && (ft_isalnum(str[j]) || str[j] == '_'))
			j++;
		if (str[i + 1] == '?')
			j++;
		var = ft_substr(str, i, j - i);
		value = ft_get_env(var, 1);
		tmp = replace_var(str, var, value, i);
		free(var);
		return (tmp);
	}
	else
		return (NULL);
}

char	*ret_str(char *str, char *newstr)
{
	free(str);
	return (newstr);
}

char	*has_dollar(char *str, int single_quote)
{
	int		i;
	char	quote;
	char	*new_str;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			quote = str[i++];
			while (str[i] != quote && str[i] != '\0')
			{
				new_str = dollar(i, quote, str, single_quote);
				if (new_str)
					return (ret_str(str, new_str));
				i++;
			}
		}
		new_str = dollar(i, '-', str, single_quote);
		if (new_str)
			return (ret_str(str, new_str));
	}
	return (str);
}

char	*replace(char *str_z, int single_quote)
{
	char	*str_x;
	char	*str_y;

	str_x = str_z;
	str_y = str_z;
	while (1)
	{
		str_y = has_dollar(str_y, single_quote);
		if (!ft_strncmp(str_y, str_x, ft_strlen(str_y) + 1))
			return (str_y);
		str_x = str_y;
	}
}
