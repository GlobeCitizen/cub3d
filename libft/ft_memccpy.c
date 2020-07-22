/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:29:55 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/16 04:40:55 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c0;
	unsigned char	*q;
	unsigned char	*p;

	i = -1;
	c0 = (unsigned char)c;
	q = dst;
	p = (unsigned char *)src;
	while (n > 0)
	{
		*q = *p;
		q++;
		if (*p == c0)
			return (q);
		p++;
		n--;
	}
	return (NULL);
}
