/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:03:32 by jlarue            #+#    #+#             */
/*   Updated: 2023/03/14 14:56:40 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_tabs(char	**tabtab, int index)
{
	while (index <= 0)
	{
		free(tabtab[index]);
		index--;
	}
	free(tabtab);
	return ;
}

int	count_words(char const *str, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0')
			&& str[i] != c)
			nb++;
		i++;
	}
	return (nb);
}

void	fill_tab(char *dest, char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	fill_tabtab(char **tabtab, char const *str, char c)
{
	int	i;
	int	j;
	int	tabstart;

	tabstart = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c || str[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			tabtab[tabstart] = malloc(sizeof(char) * (j + 2));
			if (!tabtab[tabstart])
				return (free_tabs(tabtab, tabstart));
			fill_tab(tabtab[tabstart], &str[i], c);
			i = i + j;
			tabstart = tabstart + 1;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tabtab;
	int		nbtabs;

	nbtabs = count_words(s, c);
	tabtab = malloc(sizeof(char *) * (nbtabs + 1));
	if (!s)
		return (NULL);
	if (!tabtab)
		return (NULL);
	tabtab[nbtabs] = NULL;
	fill_tabtab(tabtab, s, c);
	return (tabtab);
}
