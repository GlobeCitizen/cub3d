/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:53:42 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/29 01:25:02 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digits(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	n = (n < 0) ? -n : n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char		*alloc(int n)
{
	char	*str;

	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	if (n == 0)
		str = ft_strdup("0");
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		count;

	if (n == 0 || n == -2147483648)
		return (alloc(n));
	count = digits(n);
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	if (!(str = (char *)malloc((count + neg) * sizeof(char) + 1)))
		return (NULL);
	*str = (neg == 1) ? '-' : *str;
	while (count-- + neg > 0)
		str++;
	*str-- = '\0';
	while (n > 0)
	{
		*str = n % 10 + '0';
		str--;
		n /= 10;
	}
	return (str + (1 - neg));
}
