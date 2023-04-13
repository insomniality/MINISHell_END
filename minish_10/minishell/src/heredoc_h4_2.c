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

char	*ft_get_env(char *env_name, int dlr)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	if (!ft_strncmp(env_name, "$?", 2) && dlr)
		return (ft_itoa(t_glob->exit_status));
	if (!ft_strncmp(env_name, "$\0", 2) && dlr)
		return ("$");
	while (t_glob->envp[i] != NULL)
	{
		tmp = t_glob->envp[i];
		len = ft_strlen(env_name + dlr);
		if (!ft_strncmp(env_name + dlr, tmp, len) && tmp[len] == '=')
			return (t_glob->envp[i] + ft_strlen(env_name + dlr) + 1);
		i++;
	}
	return ("");
}

void	ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	new_size(char *str)
{
	int		i;
	int		size;
	char	quote;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i++];
			while (str[i] != quote && str[i] != '\0')
			{
				size++;
				i++;
				if (str[i] == '\0')
					return (size);
			}
		}
		else
			size++;
		i++;
	}
	return (size);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
