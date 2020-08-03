/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:01:35 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/29 00:29:44 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int		len_trimmed(const char *s, const char *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (is_in(s[i], set))
		i++;
	if (!s[i])
		return (-1);
	while (is_in(s[ft_strlen(s) - j - 1], set))
		j++;
	return (i + j);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		len;
	size_t	start;

	start = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if ((len = len_trimmed(s1, set)) == -1)
		return (ft_strdup(""));
	len = ft_strlen(s1) - len;
	if (!(trimmed = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (is_in(s1[start], set))
		start++;
	ft_strlcpy(trimmed, s1 + start, len + 1);
	return (trimmed);
}
