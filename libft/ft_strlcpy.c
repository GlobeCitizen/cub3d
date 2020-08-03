/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:51:46 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/16 02:26:24 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*p;
	size_t	i;
	size_t	n;

	i = 0;
	n = dstsize;
	p = (char *)src;
	if (!src)
		return (0);
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*dst++ = *p++) == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
	}
	return (ft_strlen(src));
}
