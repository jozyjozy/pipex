/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:11 by jlarue            #+#    #+#             */
/*   Updated: 2023/03/13 15:46:10 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	j = ft_strlen((char *)s1);
	i = ft_strlen((char *)s2);
	newstr = malloc(sizeof(char) * (i + j + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
		newstr[i + j] = s2[j];
	newstr[i + j] = '\0';
	return (newstr);
}
