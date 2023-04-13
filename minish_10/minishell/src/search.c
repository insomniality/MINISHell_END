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

int	search_p2(char **name, char *pth)
{
	char	*buf1;

	if ((*name)[0] && (*name)[0] == '.' && (*name)[1] && (*name)[1] == '/')
	{
		buf1 = ft_substr(*name, 2, ft_strlen(*name) - 2);
		free(*name);
		*name = buf1;
		return (1);
	}
	return (0);
}

void	search_p3(char **name, char *pth, int *i, char ***pts)
{
	char	*buf1;
	char	*buf2;

	while ((*pts)[*i] != NULL)
	{
		if ((*name)[0] && (*name)[0] != '/')
		{
			buf1 = ft_strjoin((*pts)[*i], "/");
			buf2 = ft_strjoin(buf1, *name);
			free(buf1);
		}
		else
			buf2 = ft_strdup(*name);
		if (access(buf2, X_OK) == 0)
		{
			free(buf2);
			break ;
		}
		free(buf2);
		(*i)++;
	}
}

void	search_p4(char **name, char *pth, int *i, char ***pts)
{
	char	*buf1;
	char	*buf2;

	if ((*pts)[*i] != NULL)
	{
		if ((*name)[0] && (*name)[0] != '/')
		{
			buf1 = ft_strjoin((*pts)[*i], "/");
			buf2 = ft_strjoin(buf1, *name);
			free(buf1);
		}
		else
			buf2 = ft_strdup(*name);
		free(*name);
		*name = ft_strdup(buf2);
		free(buf2);
	}
	else if ((*pts)[*i] == NULL)
	{
		ft_putstr_fd("-bash: ", 2);
		ft_putstr_fd(*name, 2);
		ft_putstr_fd(": command not found\n", 2);
		t_glob->exit_status = 127;
		exit(127);
	}
}

void	search(char **name, char *pth)
{
	char	**pts;
	int		i;
	char	*buf1;
	char	*buf2;

	if (search_p2(name, pth))
		return ;
	pts = ft_split(pth, ':');
	i = 0;
	search_p3(name, pth, &i, &pts);
	search_p4(name, pth, &i, &pts);
	free_ar((void **)pts);
}
