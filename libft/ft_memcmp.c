/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 04:34:25 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/14 01:51:35 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char	*)s1;
	q = (unsigned char	*)s2;
	while (n > 0)
	{
		if (*p != *q)
			return (*p - *q);
		p++;
		q++;
		n--;
	}
	return (0);
}
