/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:48:42 by jlarue            #+#    #+#             */
/*   Updated: 2023/03/16 14:34:28 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

void	dupclose_placeholder(int nb, int i, int *pipefd);
void	close_placeholder1(int *pipefd, int i, int j);
void	wait_check(int argc, char **argv, int fdout, int fdin);
void	ft_putstr_fd(char *s, int fd);
char	*get_valid_path(char *env, char *cmd);
int		get_path_i(char **env);
int		get_fd(char *file, int in_out);
void	redirect(char *cmd, int i, char **env, int nb);
void	parent_redirect(int	*pipefd);
void	exv(char *cmd, char **env);
char	*get_access(char *str1, char *env);
char	**ft_split(char const *s, char c);
void	fill_tabtab(char **tabtab, char const *str, char c);
void	fill_tab(char *dest, char const *src, char c);
int		count_words(char const *str, char c);
void	free_tabs(char	**tabtab, int index);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
