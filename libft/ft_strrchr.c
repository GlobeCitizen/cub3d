/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:42:30 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/14 08:14:00 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*last;

	last = 0;
	p = (char *)s;
	while (*p)
	{
		if (*p == (char)c)
			last = p;
		p++;
	}
	if (last)
		return (last);
	if (c == '\0')
		return (p);
	return (NULL);
}
