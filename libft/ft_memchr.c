/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 03:30:32 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/14 08:02:27 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c0;
	unsigned char	*p;

	c0 = (unsigned char)c;
	p = (unsigned char *)s;
	while (n > 0)
	{
		if (*p == c0)
			return ((void *)p);
		p++;
		n--;
	}
	return (0);
}
