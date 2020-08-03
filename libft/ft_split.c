/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:27:38 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/29 00:46:35 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chars(const char *s, char c)
{
	int		total;

	total = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s++ != c)
		total++;
	return (total);
}

static int	count_words(const char *s, char c)
{
	int		i;
	int		total;
	int		mot;

	i = 0;
	total = 0;
	mot = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && mot == 0)
		{
			mot = 1;
			total++;
		}
		else if (s[i] == c && mot == 1)
			mot = 0;
		i++;
	}
	return (total);
}

static char	**free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		size_tab_split;
	char	**tab_split;

	i = 0;
	if (!s)
		return (NULL);
	size_tab_split = count_words(s, c);
	if (!(tab_split = ft_calloc(size_tab_split + 1, sizeof(char*))))
		return (NULL);
	while (i < size_tab_split)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (!(tab_split[i] = ft_calloc(count_chars(s, c) + 1, sizeof(char))))
			return (free_tab(tab_split));
		while (*s && *s != c)
			tab_split[i][j++] = *s++;
		tab_split[i++][j] = '\0';
	}
	tab_split[i] = NULL;
	return (tab_split);
}
