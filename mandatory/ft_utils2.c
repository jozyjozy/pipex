/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:20:53 by jlarue            #+#    #+#             */
/*   Updated: 2023/03/20 12:16:08 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_placeholder1(int *pipefd, int i, int j)
{
	close(i);
	close(j);
	if (pipefd[1])
		close(pipefd[1]);
	if (pipefd[0])
		close(pipefd[0]);
}

void	dupclose_placeholder(int nb, int i, int *pipefd)
{
	if (nb == 1)
		dup2(i, 0);
	else
		close(pipefd[0]);
}
