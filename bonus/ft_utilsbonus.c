/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:41:59 by jlarue            #+#    #+#             */
/*   Updated: 2023/03/21 12:10:50 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	get_fd(char *file, int in_out)
{
	if (in_out == 0)
		return (open(file, O_RDONLY));
	else
		return (open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777));
}

int	get_path_i(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P')
			if (env[i][1] == 'A')
				if (env[i][2] == 'T')
					if (env[i][3] == 'H')
						if (env[i][4] == '=')
							return (i);
		i++;
	}
	return (1);
}

char	*get_valid_path(char *env, char *cmd)
{
	char	**path;
	char	*str;
	int		i;

	path = ft_split(&env[5], ':');
	i = 0;
	while (path[i])
	{
		str = ft_strjoin(path[i], cmd);
		if (access(str, F_OK) != -1)
			return (free(path), str);
		free(str);
		free(path[i]);
		i++;
	}
	return (free(path), NULL);
}

void	wait_check(int argc, char **argv, int fdout, int fdin)
{
	int	i;

	i = argc - 3;
	while (i > 0)
	{
		wait(NULL);
		i--;
	}
	if (fdout == -1 || fdin == -1)
	{
		if (fdin != -1)
			close(fdin);
		else
			perror(argv[1]);
		if (fdout != -1)
			close(fdout);
		else
			perror(argv[argc - 1]);
		exit (1);
	}
}
