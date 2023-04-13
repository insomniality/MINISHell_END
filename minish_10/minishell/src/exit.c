/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:03:46 by mavardan          #+#    #+#             */
/*   Updated: 2023/04/07 19:34:11 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/errno.h>
#include "../inc/builtins.h"
#include "../libft/libft.h"

int	exit_for_prj(char **text, t_data *data)
{
	int		len;

	ft_putstr_fd("exit\n", 2);
	if (!text || !data)
	{
		ft_putstr_fd("exit: NULL pointer\n", 2);
		return (1);
	}
	len = 0;
	while (text[len])
		++len;
	data->exit_status = 1;
	if (1 < len)
		ft_putstr_fd("exit: too many arguments\n", 2);
	if (0 == len)
		data->exit_status = 0;
	if (1 == len)
	{
		if (is_valid_num_for_exit(text[0]))
			data->exit_status = convert_to_num_for_exit(text[0]);
		else
			data->exit_status = 2;
	}
	return (data->exit_status);
}

//int main(int argc, char **argv, char **envp)
//{
//	t_data	*data;
//	data = (t_data *)malloc(sizeof(t_data));
//	//char *s[] = {"12356", "56", NULL};
//	//char *s[] = {"56", NULL};
//	char *s[] = {NULL};
//	printf("\n------ MAIN iexit 1 ---------\n");
//	exit_for_prj(s, data);
//	printf("exit_status = %d\n", data->exit_status);
//	return (0);
//}
