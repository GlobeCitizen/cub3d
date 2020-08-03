/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 22:43:29 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/14 01:26:42 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	c0;
	char			*ptr;

	ptr = b;
	i = 0;
	c0 = (unsigned char)c;
	while (i < len)
	{
		ptr[i] = c0;
		i++;
	}
	return (b);
}
