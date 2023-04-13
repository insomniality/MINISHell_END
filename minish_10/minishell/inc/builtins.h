/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:17:05 by mavardan          #+#    #+#             */
/*   Updated: 2023/03/08 21:23:43 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define NOT_IN_ENV -2

typedef struct s_cmds
{
	int		inp;
	int		out;
	char	**cmd;
	int		hd_amount;
	char	**hd_names;

}				t_cmds;

typedef struct s_data
{
	t_cmds			*t_cmnds;
	char			**envp;
	char			**exportp;
	unsigned char	exit_status;
}				t_data;

t_data			*g_glob;

void			fill_env(char **envp, t_data **data);
void			pwd(t_data *data);
int				cd(char **new_path, t_data *data);
int				env(t_data *data);
int				echo(char **text, t_data *data);
int				export(char **text, t_data *data);
int				unset(char **env_var, t_data *data);
int				is_var_in_env(const char *s, const char *ptrn);
int				update_env(char *env_var, char *val, t_data *data);
int				update_export(char *var, char *val, t_data *data);
int				add_env(char *env_var, char *val, t_data *data);
char			*get_env(char *env_var, char **envp);
int				get_env_var_pos_by_name(const char *env_var, char **envp);
int				get_export_var_pos_by_name(const char *var, char **exportp);
int				envp_len(char **envp);
void			ft_free(char **p, int count);
int				equal_sign_pos(char *text);
char			*get_env_val(char *env_line);
char			*get_env_name(char *env_line);
char			**extend_ch_pp(char **ch_pp);
void			print_export(const char **exportp);
unsigned char	convert_to_num_for_exit(const char *str);
int				is_valid_num_for_exit(const char *str);
int				exit_for_prj(char **text, t_data *data);
int				set_get_exit_status(t_data *data, int exit_status);
int				add_var_to_export(char *var, char *val, t_data *data);
char			*concat_with_free(char *s1, char *s2);
char			**get_argv(char **argv);
int				is_valid_export_arg_for_env(char *text);
int				is_valid_export_arg_for_export(char *text);

#endif