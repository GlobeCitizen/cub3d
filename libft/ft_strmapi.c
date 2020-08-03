/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 05:00:23 by mahnich           #+#    #+#             */
/*   Updated: 2019/11/28 21:15:47 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;
	int		len;

	if (!s || !(*f))
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[i])
	{
		res[i] = (f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
