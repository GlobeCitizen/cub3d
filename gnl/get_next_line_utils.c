/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:57:24 by mahnich           #+#    #+#             */
/*   Updated: 2020/01/16 20:26:14 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	int c;

	c = 0;
	while (*s)
	{
		c++;
		s++;
	}
	return (c);
}

char	*ft_strnew(size_t len)
{
	char	*str;

	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len + 1)
		str[len--] = '\0';
	return (str);
}

char	*ft_strcat(char *s1, char const *s2)
{
	char	*p;

	p = s1 + ft_strlen(s1);
	while (*s2)
	{
		*p = *s2;
		p++;
		s2++;
	}
	*p = '\0';
	return (s1);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;

	if (!s1 || !s2 || !(joined = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	joined = ft_strcat(ft_strcpy(joined, s1), s2);
	free(s1);
	return (joined);
}
