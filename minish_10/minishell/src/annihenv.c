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

#include "../libft/libft.h"
#include "src.h"

void	annihenv_p1(char ***str, int *j, int *strtj, char **sm)
{
	(*str)[1] = NULL;
	(*j) = (*strtj);
	while ((*sm)[(*j)] != '$')
		(*j)++;
	if ((*j) == 0)
		(*str)[0] = ft_strdup("");
	else
		(*str)[0] = ft_substr((*sm), 0, (*j));
	if (c_check((*sm), (*j) + 1, " 	") || ((*sm)[(*j)] && !(*sm)[(*j) + 1]))
		(*str)[1] = ft_strdup("$");
}

void	annihenv_p2_2(char ****str)
{
	if ((ft_strlen((**str)[1]) == 1 && (**str)[1][0] == '?'
	&& (**str)[1][1] == '\0')
	|| (ft_strlen((**str)[1]) > 1 && ((**str)[1])[0] == '?'
	&& ((**str)[1][1] == ' ' || (**str)[1][2] == '\"')))
	{
		free((**str)[1]);
		(**str)[1] = ft_itoa(t_glob->exit_status);
	}
	else
	{
		(**str)[2] = (**str)[1];
		(**str)[1] = ft_strjoin("", getenv((**str)[2]));
		free((**str)[2]);
	}
}

void	annihenv_p2(char ***str, int *j, int *strtj, char **sm)
{
	(*j)++;
	(*strtj) = (*j);
	while ((*sm)[(*j)] && !c_check((*sm), (*j), " 	") && (*sm)[(*j)] != '$')
		(*j)++;
	if ((*str)[1] == NULL)
	{
		if ((*j) == (*strtj))
			(*str)[1] = ft_strdup("");
		else
			(*str)[1] = ft_substr((*sm), (*strtj), (*j) - (*strtj));
		annihenv_p2_2(&str);
	}
}

void	annihenv_p3(char ***str, int *j, int *strtj, char **sm)
{
	(*strtj) = (*j);
	while ((*sm)[(*j)])
		(*j)++;
	if ((*j) == (*strtj))
		(*str)[2] = ft_strdup("");
	else
		(*str)[2] = ft_substr((*sm), (*strtj), (*j) - (*strtj));
	free((*sm));
	if (!(*str)[1])
		(*sm) = ft_strjoin((*str)[0], "");
	else
		(*sm) = ft_strjoin((*str)[0], (*str)[1]);
}

void	annihenv(char **sm, char *c)
{
	int		j;
	int		strtj;
	char	*str[3];
	char	**s;

	s = str;
	j = 0;
	strtj = j;
	while ((*sm)[j] && ft_strchr(&((*sm)[strtj]), '$') != NULL)
	{
		annihenv_p1(&s, &j, &strtj, sm);
		annihenv_p2(&s, &j, &strtj, sm);
		annihenv_p3(&s, &j, &strtj, sm);
		strtj = ft_strlen(*sm);
		j = strtj;
		free(str[0]);
		str[0] = (*sm);
		(*sm) = ft_strjoin(str[0], str[2]);
		free(str[0]);
		free(str[2]);
		if (str[1] != NULL)
			free(str[1]);
	}
}
