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

void	annimot_p1(char **big, char *a, char ***snt, int *strti)
{
	int	*i;
	int	*strt;

	i = &(strti[0]);
	strt = &(strti[1]);
	(*i) = 0;
	(*strt) = 0;
	while ((*big)[(*i)] != '\'' && (*big)[(*i)] != '\"')
		(*i)++;
	(*a) = (*big)[(*i)];
	if ((*i) != (*strt))
		(*snt)[0] = ft_substr((*big), (*strt), (*i) - (*strt));
	else
		(*snt)[0] = ft_strdup("");
}

void	annimot_p2(char **big, char *a, char ***snt, int *strti)
{
	int	*i;
	int	*strt;

	i = &(strti[0]);
	strt = &(strti[1]);
	(*i)++;
	(*strt) = (*i);
	while ((*big)[(*i)] && (*big)[(*i)] != (*a))
		(*i)++;
	if ((*i) != (*strt))
		(*snt)[1] = ft_substr((*big), (*strt), (*i) - (*strt));
	else
		(*snt)[1] = ft_strdup("");
	if ((*a) == '\"' && ft_strchr((*snt)[1], '$'))
		annihenv(&((*snt)[1]), " 	");
}

void	annimot_p3(char **big, char ***snt, int *strti)
{
	int	*i;
	int	*strt;

	i = &(strti[0]);
	strt = &(strti[1]);
	(*i)++;
	(*strt) = (*i);
	while ((*big)[(*i)])
		(*i)++;
	if ((*i) != (*strt))
		(*snt)[2] = ft_substr((*big), (*strt), (*i) - (*strt));
	else
		(*snt)[2] = ft_strdup("");
	free((*big));
	(*big) = ft_strjoin((*snt)[0], (*snt)[1]);
	free((*snt)[0]);
	free((*snt)[1]);
	(*i) = ft_strlen((*big));
	(*snt)[0] = (*big);
	(*big) = ft_strjoin((*snt)[0], (*snt)[2]);
	free((*snt)[0]);
	free((*snt)[2]);
}

void	annihmotor(char	**big, char *a, char ***snt)
{
	int	strti[2];

	strti[0] = 0;
	while (ft_strchr(&((*big)[strti[0]]), '\'') != NULL
	|| ft_strchr(&((*big)[strti[0]]), '\"') != NULL)
	{
		annimot_p1(big, a, snt, strti);
		annimot_p2(big, a, snt, strti);
		annimot_p3(big, snt, strti);
	}
}

char	*annihilator(char const *s, int *x, char *c)
{
	char	*big;
	char	a;
	char	*sn[3];
	char	**snt;

	snt = sn;
	big = ft_substr(s, x[1], x[0] - x[1]);
	if (ft_strchr(big, '\'') != NULL || ft_strchr(big, '\"') != NULL)
		annihmotor(&big, &a, &snt);
	else if (ft_strchr(big, '$') != NULL)
		annihenv(&big, c);
	return (big);
}
