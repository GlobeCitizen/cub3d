/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:58:23 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/16 04:37:30 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*q;
	unsigned char	*p;
	size_t			i;

	i = -1;
	p = (unsigned char *)src;
	q = (unsigned char *)dst;
	if (p < q)
		while ((int)(--len) >= 0)
			*(q + len) = *(p + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
