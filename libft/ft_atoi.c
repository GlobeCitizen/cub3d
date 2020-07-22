/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 05:00:13 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/29 00:26:11 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*p;
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	p = (char *)str;
	while (*p == ' ' || *p == '\f' || *p == '\r' || *p == '\t' ||
			*p == '\n' || *p == '\v')
		p++;
	if (*p == '-')
	{
		sign = -1;
		p++;
	}
	else if (*p == '+')
		p++;
	if (*p == '+' || *p == '-')
		return (0);
	while (*p <= '9' && *p >= '0')
	{
		result = result * 10 + (*p - '0');
		p++;
	}
	return (result * sign);
}
