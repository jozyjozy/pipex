/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:01 by jlarue            #+#    #+#             */
/*   Updated: 2023/03/21 13:00:57 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_access(char *str1, char *env)
{
	char	*str;
	char	*cmd;
	int		i;

	i = 0;
	str = str1;
	if (access(str, F_OK) == -1)
	{
		cmd = malloc(sizeof(char) * (ft_strlen(str) + 2));
		if (!cmd)
			return (NULL);
		cmd[i] = '/';
		while (str[i])
		{
			cmd[i + 1] = str[i];
			i++;
		}
		cmd[i + 1] = '\0';
		str = get_valid_path(env, cmd);
		free(cmd);
		if (!str)
			return (str1);
		return (str);
	}
	return (str1);
}

void	exv(char *cmd, char **env)
{
	char	**tabtab;
	char	*str;

	tabtab = ft_split(cmd, ' ');
	str = get_access(tabtab[0], env[get_path_i(env)]);
	if (execve(str, tabtab, env) < 0)
	{
		ft_putstr_fd("pipex : command not found: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		free(tabtab);
		free(str);
		exit(1);
	}
}

void	parent_redirect(int	*pipefd)
{
	close(pipefd[1]);
	if (dup2(pipefd[0], 0) < 0)
		perror("dup2");
	close(pipefd[0]);
}

void	redirect(char *cmd, int i, char **env, int nb)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) < 0)
		perror("pipe");
	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid != 0)
		parent_redirect(pipefd);
	else
	{
		dupclose_placeholder(nb, i, pipefd);
		if (nb != 2)
			dup2(pipefd[1], 1);
		else
			dup2(i, 1);
		close_placeholder1(pipefd, 3, 4);
		if (i < 1)
			exit (1);
		else
			exv(cmd, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fdin;
	int	fdout;
	int	i;

	i = 3;
	if (argc < 5)
		return (ft_putstr_fd("pipex : argc < 5", 0), 0);
	fdin = get_fd(argv[1], 0);
	fdout = get_fd(argv[argc - 1], 1);
	redirect(argv[2], fdin, env, 1);
	while (i < argc - 2)
	{
		redirect(argv[i], 1, env, 0);
		i++;
	}
	redirect(argv[i], fdout, env, 2);
	if (fdout != -1)
		close(fdout);
	if (fdin != -1)
		close(fdin);
	wait_check(argc, argv, fdout, fdin);
	return (0);
}
