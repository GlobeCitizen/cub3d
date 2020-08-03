/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:00:52 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/16 02:21:51 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*q;
	char	*p;

	q = dst;
	p = (char *)src;
	if (!n || dst == src)
		return (dst);
	while (n > 0)
	{
		*q = *p;
		p++;
		q++;
		n--;
	}
	return (dst);
}
