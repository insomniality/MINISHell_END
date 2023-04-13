/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:05:40 by mikarzum          #+#    #+#             */
/*   Updated: 2022/08/09 18:43:44 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

// #define QUOT1 '\''
// #define QUOT2 '\"'

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "../inc/builtins.h"
# include <termios.h>

int		ft_strchr_indx(const char *s, int c);
char	**split2(char const *s, char *c, int cmdi);
void	define_signals();
int		c_check(char const *s, int idx, char *c);
void	free_ar(void **spl);
void	search(char **name, char *pth);
char	**split_fk(char *txt, char *c);
int		qt_check(char const *s);
int		c_check(char const *s, int idx, char *c);
void	envqt(char *c, char **ddy, int x);
void	envqt2(char *c, char *ddy);
char	*annihilator(char const *s, int *x, char *c);
void	annihenv(char **sm, char *c);
int		qt_strt(char const *s, int *x, char *c);
void	quoter(char const *s, char *cq, char **ddy, int *x);
int		_sp2(char const *s, int *x, char *c);
int		_pieces(char const *s, char *c);
void	heredoc_signals(void);
char	*remove_quotes(int size, char *str);
char	*replace(char *str_z, int single_quote);
char	*ft_get_env(char *env_name, int dlr);
void	ignore_signals(void);
void 	reprompt(int sig);
int		new_size(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		heredoc(char *delimiter);
void	ignore_symbols(void);
void	define_signals();
void 	reprompt(int sig);
void	my_waitpid(pid_t pid);
char	*pipfin(char *t);
int		ft_chrcnt(char *str, char chr);
int		ft_arrlen(void *arr, int typsz);
void	lowerc(char ***m_argv);
int		validornot(char *txt);
int		ispipe(char *s);
int		is_builtin(char *s, char *arg, t_data *data);
void	builtin_exec(char *s, char **arg, t_data *data);
void	*m_pipe(int pipn, char *txt);
void	m_pipe_p2_1(char **txt, char **txt2);
void	m_pipe_p3_f1(int pipn, int *j, int ***fd);
void	m_pipe_p3_f2(int pipn, int *j);
void	m_pipe_p4_c1(int pipn, int ***fd);
void	m_pipe_p5_fr1(int pipn, int ***fd, char **txt, int **pid);
void	main2(char *txt);
char	*nxt_pipe(char *str);
void	redir(char const *s, char *c, int *x, int cmdi);


#endif
